#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <easyx.h>
#include <graphics.h>
#define ROW 16
#define COL 30
#define MINE_CNT 99
/* 微软扫雷的难度分级：
    简单难度9 x 9，共10雷，占比12.345%
    中级难度16 x 16，共40雷，占比15.625%
    高级难度16 x 30，共99雷，占比20.625%
*/
/*  1.生成界面
    2.第一次点击不能有雷
    3.生成雷的方式就是靠二维数组里的数字来表示，while(1)不断刷新界面
    4.雷，已打开的非雷块，未打开的遮罩层，标记可以通过[-1 + 10 * k, 8 + 10 * k](k -> Z)来表示
    5.当前底部栏还存在bug，会导致有某一个方块大小区域一点击即游戏失败（于4.13已修复）*/
using namespace std;
int map[ROW][COL];
IMAGE texture[16];
//生成地雷
void Mineinit(int inix, int iniy)
{
    srand((unsigned)time(NULL));
    int row, col;
    //for循环中将循环变量自增的语句删去，在循环体内部实现自增可以使雷块的生成不重复
    for (int i = 0; i < MINE_CNT;) {
        row = rand() % ROW;
        col = rand() % COL;
        if (map[row][col] == 20 && row != iniy && col != inix) {
            map[row][col] -= 1;
            i++;
        }
    }
    //生成雷块之后，遍历版面，找到雷块，以其为中心周围一圈的雷数标记 + 1
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (map[i][j] == 19) {
                for (int r = i - 1; r < i + 2; r++) {
                    for (int c = j - 1; c < j + 2; c++) {
                        //注意边界判定，否则导致segmentation fault
                        if (r >= 0 && r < ROW && c >= 0 && c < COL && map[r][c] != 19) {
                            map[r][c]++;
                        }
                    }
                }
            }
        }
    }
}
//加载图片
void Load_image()
{
    char str[50];
    for (int i = 0; i < 16; i++) {
        sprintf(str, "./H3Artsweeper_texture/%d.png", i);
        loadimage(texture + i, str, 32, 32);
    }
}
//将图片打印出来
void Put_image()
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            //0-8是已打开的数字层
            if (map[i][j] >= 0 && map[i][j] < 9) {
                putimage(j * 32, i * 32, texture + map[i][j]);
            } //19-28是初始遮罩层
            else if (map[i][j] >= 19 && map[i][j] < 29) {
                putimage(j * 32, i * 32, texture + 11);
                //39-48是flag（猫头标记）
            } else if (map[i][j] >= 39 && map[i][j] < 49) {
                putimage(j * 32, i * 32, texture + 10);
                //49-58是失败哭脸
            } else if (map[i][j] >= 49 && map[i][j] < 59) {
                putimage(j * 32, i * 32, texture + 12);
                //-1为雷（heart）
            } else if (map[i][j] == -1) {
                putimage(j * 32, i * 32, texture + 9);
            }
        }
    }
}
//实现鼠标点击到非数字也非雷位置的爆炸效果
void Booming(int row, int col)
{
    //遍历以传进来的坐标周围的一周方块
    for (int i = row - 1; i < row + 2; i++) {
        for (int j = col - 1; j < col + 2; j++) {

            if (i >= 0 && i < ROW && j >= 0 && j < COL) {
                //若未打开且为空白格（非雷非数字非标记）则直接打开
                if (map[i][j] == 20) {
                    map[i][j] -= 20;
                    //打开的空白格将递归调用该函数实现连续爆炸
                    Booming(i, j);
                    //若未打开且为数字格，那仅将数字格打开，不再进行递归调用
                } else if (map[i][j] > 20 && map[i][j] < 29) {
                    map[i][j] -= 20;
                }
            }
        }
    }
}
//决定该次点击触发的事件
int click_judge(int row, int col, int judge)
{
    //judge起初仅为实现判断左右键点击，但引入中键点击后也可以判断是否引发雷爆炸
    //左键点击若点到了空白格（非雷非数字非标记），则引发Booming效果
    if (map[row][col] == 0 && judge && row < ROW) {
        Booming(row, col);
    }
    //左键点击或中键引发雷爆炸，将所有雷块以爱心形式展开
    if (map[row][col] == -1 && row < ROW) {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (map[i][j] == 19) {
                    map[i][j] -= 20;
                    //已标记的位置也不要忘记展开
                } else if (map[i][j] == 39) {
                    map[i][j] -= 40;
                }
            }
        }
        return 1;
    }
    return 0;
}
//识别鼠标操作
int Mouse_event(int* inix, int* iniy)
{
    //利用getmessage函数获取鼠标输入信息
    ExMessage event = getmessage(EM_MOUSE);
    //将鼠标在程序图形化界面窗口的对应x、y坐标除以每个格子对应的长度
    //除以每个格子对应的长度后便是二维数组的下标值
    int row = event.y / 32;
    int col = event.x / 32;
    //左键点击的时候，若为未打开的格子，便打开，将该格的坐标传入Click_judge判断
    if (event.message == WM_LBUTTONDOWN) {
        if (map[row][col] >= 19 && map[row][col] < 29 && row < ROW) {
            map[row][col] -= 20;
        }
        *inix = col;
        *iniy = row;
        return 1;
        //右键点击的时候，若为未打开的格子，便标记，若为已标记的格子，便取消标记
    } else if (event.message == WM_RBUTTONDOWN) {
        if (map[row][col] >= 19 && map[row][col] < 29) {
            map[row][col] += 20;
        } else if (map[row][col] >= 39 && map[row][col] < 49) {
            map[row][col] -= 20;
        }
        //返回0，Click_judge的坐标记录为上一次左键或中键点击，但不会进入Booming判断
        //因此将不会打开莫名其妙的格子
        return 0;
        //中键点击的时候，首先需要判断中键点击的格子是否为已打开的数字格
    } else if (event.message == WM_MBUTTONDOWN && map[row][col] > 0 && map[row][col] < 9) {
        //判断中键点击的格子周围一周的标记数量是否与该格的数字相等，先累加标记数
        int flagnum = 0;
        for (int i = row - 1; i < row + 2; i++) {
            for (int j = col - 1; j < col + 2; j++) {
                if (i >= 0 && i < ROW && j >= 0 && j < COL && (i != row || j != col)) {
                    if (map[i][j] >= 39 && map[i][j] < 49) {
                        flagnum++;
                    }
                }
            }
        }
        if (flagnum == map[row][col]) {
            for (int i = row - 1; i < row + 2; i++) {
                for (int j = col - 1; j < col + 2; j++) {
                    if (i >= 0 && i < ROW && j >= 0 && j < COL) {
                        if (map[i][j] >= 19 && map[i][j] < 29) {
                            map[i][j] -= 20;
                            //若在中键打开的时候打开了雷块，直接返回1和雷块的坐标给主程序
                            //主程序中下一步骤的Click_judge将会判定游戏失败
                            if (map[i][j] == -1) {
                                *inix = j;
                                *iniy = i;
                                return 1;
                            }
                            //实现中键打开的时候也有Booming
                            click_judge(i, j, 1);
                        }
                    }
                }
            }
        }
        //若中键将所有可打开的坐标打开成功了，则返回0，不再被主程序中的Click_judge判断
        return 0;
    }
}
//统计当前打开的方格数量
int Open_count()
{
    int cnt = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (map[i][j] < 19) {
                cnt++;
            }
        }
    }
    //若打开的方格数量为（所有块 - 雷块），则返回1，代表获胜
    if (cnt == ROW * COL - MINE_CNT) {
        return 1;
    }
    return 0;
}
//底部栏
void Botton_line()
{
    putimage((COL - 1) * 32, ROW * 32, texture + 15);
    putimage(0, ROW * 32, texture + 13);
    for (int i = 1; i < COL - 1; i++) {
        putimage(i * 32, ROW * 32, texture + 14);
    }
    RECT r = { 0, ROW * 32, COL * 32, (ROW + 1) * 32 };
    drawtext(_T("Copyright H3Art_q from Jinan University International School 2021 CST Major"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
//胜利时的计时器
char* time_counter(time_t time_start)
{
    //游戏胜利时进入该函数，获取此时的时间，time(NULL)会返回以秒为单位的time_t格式数值
    //time_t类型可以强制转化为整形/长整形
    time_t time_final = time(NULL) - time_start;
    char* successful = (char*)calloc(150, sizeof(char));
    switch ((long int)time_final / 10) {
    case 0:
        sprintf(successful, "wtf，你是神吗？这才%lld秒欸？？？\n掐掐手指看看10秒才多久啊！", time_final);
        break;
    case 1:
        sprintf(successful, "用时%lldsec，\n你的算力和操作已经爆杀H3Art本人了。。。", time_final);
        break;
    case 2:
        sprintf(successful, "%lld秒结束战斗，\n进入20s范围已经很牛了，还能继续进步吗？", time_final);
        break;
    case 6:
    case 5:
    case 4:
    case 3:
        sprintf(successful, "仅用时%lld秒将我的所有heart躲过，\n看来有好好研究我捏，你敢更快一点吗？", time_final);
        break;
    case 10:
    case 9:
    case 8:
    case 7:
        sprintf(successful, "%lld秒在你的指间溜走，\n但我的heart会一直在那等你。", time_final);
        break;
    default:
        sprintf(successful, "虽然你把我的heart全躲过了，\n但是都过去了%lld秒捏，你下次肯定逃不过heart的！", time_final);
        break;
    }
    return successful;
}
//主程序
int main()
{
    //屏蔽console（命令行窗口）
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    MessageBox(NULL, TEXT("这是一个扫雷游戏，但雷是H3Art_q的heart，\n基本操作规则只有左键打开未打开的方块，\n右键在你认为有heart的位置进行标记，\n以及，通过鼠标中键在已打开的数字区域快速打开周围九宫格内的方块，\n但是请注意，中键使用的前提是该数字周围的九宫格里做了正确数量和正确位置的标记，\n否则，你将不可避免地坠入爱河！"), TEXT("这是H3Art_q自己写的第一个不是黑框窗口的程序！可恶的C语言！"), MB_OK);
    //创建游戏窗口
    initgraph(32 * COL, 32 * (ROW + 1));
    Load_image();
    setbkmode(TRANSPARENT);
    HWND hWnd = GetHWnd();
    //游戏主体
Label:
    int judge_firstclk = 0, judge_RLbutton = 0;
    time_t time_start = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            map[i][j] = 20;
        }
    }
    Botton_line();
    Put_image();
    while (true) {
        int x = 0, y = ROW + 1;
        //需要用户进行扫雷点击的代码
        //判断是否为第一次点击，以实现第一次必定非雷
        if (!judge_firstclk) {
            judge_RLbutton = Mouse_event(&x, &y);
            //第一次点击需是左键且于有效坐标内才生成雷
            if (judge_RLbutton && y < ROW) {
                Mineinit(x, y);
                judge_firstclk++;
                //获得第一次左键点击时的游戏时间
                time_start = time(NULL);
            }
        } else {
            judge_RLbutton = Mouse_event(&x, &y);
        }
        //往下是无需用户扫雷点击的代码
        //click_judge需要判断当左键点击后的结果，若失败，进入失败事件
        //以及中键点出了雷块时也会进入失败事件
        if (click_judge(y, x, judge_RLbutton)) {
            Put_image();
            int result = MessageBox(NULL, TEXT("哈，你坠入爱河了！\n速速再来一局8。"), TEXT("肿！"), MB_RETRYCANCEL);
            switch (result) {
            case IDRETRY:
                goto Label;
                break;
            case IDCANCEL:
                return EXIT_SUCCESS;
            }
        } else {
            Put_image();
        }
        //Open_count通过判断打开的块数是否等于所有非雷格数而判定是否胜利
        if (Open_count()) {
            //胜利时将所有雷的的位置展开（转换为哭泣脸展开）
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    if (map[i][j] == 19) {
                        map[i][j] += 30;
                        //标记过的雷格也要展开
                    } else if (map[i][j] == 39) {
                        map[i][j] += 10;
                    }
                }
            }
            Put_image();
            int result = MessageBox(NULL, TEXT(time_counter(time_start)), TEXT("可恶！"), MB_RETRYCANCEL);
            switch (result) {
            case IDRETRY:
                goto Label;
                break;
            case IDCANCEL:
                return EXIT_SUCCESS;
            }
        }
    }
}