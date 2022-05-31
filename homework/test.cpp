#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int chess[7][9] = {4, 4, 4, 4, 4, 4, 4, 4, 4,
                   4, 4, 4, 0, 0, 4, 4, 4, 4,
                   4, 4, 4, 0, 0, 4, 4, 4, 4,
                   4, 0, 0, -1, 1, 0, 0, 0, 0,
                   4, 0, 0, 1, -1, 0, 0, 0, 0,
                   4, 4, 4, 0, 0, 4, 4, 4, 4,
                   4, 4, 4, 0, 0, 4, 4, 4, 4};


class List{
    public:
    int *a[8];
};

int *a1[8];
int *a2[8];
int *a3[8];
int *a4[8];
int *a5[8];
int *a6[8];
int sign = 0;
void init()
{
    //初始化链表
    a1[0] = &chess[1][3];
    a1[1] = &chess[2][3];
    a1[2] = &chess[3][3];
    a1[3] = &chess[4][3];
    a1[4] = &chess[5][3];
    a1[5] = &chess[6][3];
    a1[6] = &chess[3][8];
    a1[7] = &chess[4][8];

    a2[0] = &chess[1][4];
    a2[1] = &chess[2][4];
    a2[2] = &chess[3][4];
    a2[3] = &chess[4][4];
    a2[4] = &chess[5][4];
    a2[5] = &chess[6][4];
    a2[6] = &chess[3][7];
    a2[7] = &chess[4][7];

    a3[0] = &chess[3][1];
    a3[1] = &chess[3][2];
    a3[2] = &chess[3][3];
    a3[3] = &chess[3][4];
    a3[4] = &chess[3][5];
    a3[5] = &chess[3][6];
    a3[6] = &chess[3][7];
    a3[7] = &chess[3][8];

    a4[0] = &chess[4][1];
    a4[1] = &chess[4][2];
    a4[2] = &chess[4][3];
    a4[3] = &chess[4][4];
    a4[4] = &chess[4][5];
    a4[5] = &chess[4][6];
    a4[6] = &chess[4][7];
    a4[7] = &chess[4][8];

    a5[0] = &chess[3][2];
    a5[1] = &chess[2][3];
    a5[2] = &chess[2][4];
    a5[3] = &chess[3][5];
    a5[4] = &chess[4][5];
    a5[5] = &chess[5][4];
    a5[6] = &chess[5][3];
    a5[7] = &chess[4][2];

    a6[0] = &chess[3][1];
    a6[1] = &chess[1][3];
    a6[2] = &chess[1][4];
    a6[3] = &chess[3][6];
    a6[4] = &chess[4][6];
    a6[5] = &chess[6][4];
    a6[6] = &chess[6][3];
    a6[7] = &chess[4][1];
}

int temp[2];
int temp1[2];
bool insearch(int x, int y)
{
    int flag = 0;
    for (int i = 0; i < 8; i++)
    {
        if (&chess[x][y] == a1[i])
        {
            temp[0] = 1;
            temp[1] = i;
            flag++;
            break;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (&chess[x][y] == a2[i])
        {
            temp[0] = 2;
            temp[1] = i;
            flag++;
            break;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (&chess[x][y] == a3[i])
        {
            if (flag == 1)
            {
                temp1[0] = 3;
                temp1[1] = i;
                return true;
            }
            else
            {
                temp[0] = 3;
                temp[1] = i;
                flag++;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (&chess[x][y] == a4[i])
        {
            if (flag == 1)
            {
                temp1[0] = 4;
                temp1[1] = i;
                return true;
            }
            else
            {
                temp[0] = 4;
                temp[1] = i;
                flag++;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (&chess[x][y] == a5[i])
        {
            temp1[0] = 5;
            temp1[1] = i;
            flag++;
            return true;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (&chess[x][y] == a6[i])
        {
            temp1[0] = 6;
            temp1[1] = i;
            flag++;
            return true;
        }
    }
    if (flag == 0)
        return false;
}

//输出棋盘界面
void gui()
{
    // system("cls");
    int score_black = 0, score_white = 0;
    printf("\033[0m\n        [黑白棋]\n\n    1 2 3 4 5 6 7 8\n  ┌─────────────────┐\n");
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (j % 8 == 1)
                printf(" %c│ ", (i * 8 + j) / 8 - 1 + 'A');
            switch (chess[i][j])
            {
            case -1:
                printf("○ "); //黑棋
                score_black++;
                break;
            case 1:
                printf("● "); //白棋
                score_white++;
                break;
            case 0:
                printf("┼ "); //空白
                break;
            case 2:
            case -2:
                printf("\033[32m┼ \033[0m");
                break; //提示位置
            default:
                printf("  "); //空位
            }
            if (j % 8 == 0)
                printf("│\n");
        }
    }
    printf("  └─────────────────┘\n   黑棋:%2d | 白棋:%2d \n", score_black, score_white);
    printf("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─\n");
    // return score_black==score_white ? 0 : ( score_black>score_white ? 1 : -1 ) ;
}
//输出信息,在gui()后
int info(const int sign, const int color)
{
    switch (sign)
    {
    default: // sign>=0
        if (sign < 24)
            printf("%s方在[%c%c]落子\n", color == 1 ? "白" : "黑", sign / 8 + 'A', sign % 8 + '1');
        else
            printf("%s方在[%c%c]落子\n%s方无可落子位置!\n", color == 1 ? "黑" : "白", sign / 8 - 10 + 'A', sign % 8 + '1', color == 1 ? "白" : "黑");
    }
    return 0;
}

bool react4(int color, int row)
{
    bool all = false;
    for (int dx = -1; dx <= 1; dx++)
    { //二向搜索,翻转棋子
        if (dx == 0)
            continue;
        int times = 1; //记录循环次数
        int flag = 0;  // 1表示实际 ，0表示虚拟
        for (int rowp = row + dx; times < 8; rowp += dx, times++)
        {
            //过界
            if (rowp >= 8)
            {
                rowp -= 8;
                flag = 1;
            }
            if (rowp <= -1)
            {
                rowp += 8;
                flag = -1;
            }
            //正常
            if (flag == 0)
            {
                 int temp;//处理rowp+dx过界的问题
                if(rowp+dx==8)
                {
                    temp=rowp+dx-8;
                }
                else if(row+dx==-1){
                    temp=rowp+dx+8;
                }
                else {
                    temp=rowp+dx;
                }
                if (*a4[rowp] != -color )break; //不是反色就退出 如果一直是同色就继续
                else if (*a4[temp] == color)
                {
                    for (; rowp != row; rowp -= dx)
                    {
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                    }
                    all = true;
                    break;
                }

            }
            //去下界
            else if (flag == -1)
            {
                
                if (*a4[rowp] != -color )
                    break;
                else if (*a4[rowp+dx] == color)
                {
                    for (; rowp != 8; rowp -= dx)
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子

                    rowp -= 8;

                    for (; rowp != row; rowp -= dx)
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                    all = true;
                    break;
                }
            }
            //去上界
            else if (flag == 1)
            {
                
                //正常的搜索
                if (*a4[rowp] != -color  )
                break;
                else if (*a4[rowp+dx] == color)
                {
                    for (; rowp != -1; rowp -= dx)
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子

                    rowp += 8;

                    for (; rowp != row; rowp -= dx)
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                    all = true;
                    break;
                }
            }
        }
        
    }
    if (all)
        return true;
    else
        return false;
}



int main()
{
    //chess[4][1] = -1;
    chess[4][2] = 1;
    chess[4][3] = 1;
    chess[4][4] = 1;
     chess[4][5] = -1;
    chess[4][6] = 1;
    chess[4][7] = 1;
    chess[4][8] = 1;
    int x, y;
    init();
    gui();
    int color=-1;
    scanf("%d%d", &x, &y);
    if(insearch(x,y)) {
        chess[x][y]=color;gui();
            /* if(temp[0]==1) {
            if(react1(color,temp[1])) gui();
                        }

            else if(temp[0]==2) {if(react2(color,temp[1])) gui();
            }

            else if(temp[0]==3) {if(react3(color,temp[1])) gui();
            }

            else if(temp[0]==4) {if(react4(color,temp[1])) gui();
            }

            if(temp1[0]==3) {if(react3(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;}


            else if(temp1[0]==4) {if(react4(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;}


            else if(temp1[0]==5) {if(react5(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;}


            else if(temp1[0]==6) {if(react6(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;} */
            if(temp[0]==4) {if(react4(color,temp[1])) gui();
            }


        
        }
    else printf("error");
    cout<<temp[0]<<" "  <<temp[1]<<endl;
    cout<<temp1[0]<<" "  <<temp1[1]<<endl;




    /* do
    {
        sign % 2 == 0 ? color = -1 : color = 1;
        gui();
        scanf("%d%d", &x, &y);
        //给你一个chess坐标找到他的两条链子
        if (insearch(x, y))
        {
            chess[x][y] = color;
            if (temp[0] == 1)
            {
                if (react1(color, temp[1]));
                else
                {
                    cout << "不能下这里" << endl;
                    chess[x][y] = 0;
                }
            }

            else if (temp[0] == 2)
            {
                if (react2(color, temp[1]));
                   else
                    {
                        cout << "不能下这里" << endl;
                        chess[x][y] = 0;
                    }
            }

            else if (temp[0] == 3)
            {
                if (react3(color, temp[1]));
                    else
                    {
                        cout << "不能下这里" << endl;
                        chess[x][y] = 0;
                    }
            }

            else if (temp[0] == 4)
            {
                if (react4(color, temp[1]));
                    else
                    {
                        cout << "不能下这里" << endl;
                        chess[x][y] = 0;
                    }
            }

            if (temp1[0] == 3)
            {
                if (react3(color, temp1[1]))
                {
                    gui();
                    sign++;
                }
            }

            else if (temp1[0] == 4)
            {
                if (react4(color, temp1[1]))
                {
                    gui();
                    sign++;
                }
            }

            else if (temp1[0] == 5)
            {
                if (react5(color, temp1[1]))
                {
                    gui();
                    sign++;
                }
            }

            else if (temp1[0] == 6)
            {
                if (react6(color, temp1[1]))
                {
                    gui();
                    sign++;
                }
            }
        }
        else
        {
            cout << "不能下这里" << endl; //位置不存在
        }

    } while (sign != 24); */

    /* chess[4][1] = 1;
    chess[4][2] = -1;
    chess[4][3] = 1;
    chess[4][4] = 1;
    chess[4][5] = -1;
    chess[4][6] = 1;
    chess[4][7] = 1;
    chess[4][8] = 1;
    chess[3][5]=1;
    chess[4][5]=-1;
    chess[2][3]=1;
    chess[2][4]=1;
    chess[3][2]=1;
    chess[4][2]=-1;
    chess[5][3]=1;
    chess[5][4]=1;



    int color = -1;
    int x=4;
    int y=5;



    //给你一个chess坐标找到他的两条链子
    if (insearch(x, y))
    {

            if(temp[0]==1) {if(react1(color,temp[1])) gui();
                            else cout<<"不能下这里"<<endl;}

            else if(temp[0]==2) {if(react2(color,temp[1])) gui();
            else cout<<"不能下这里"<<endl;}

            else if(temp[0]==3) {if(react3(color,temp[1])) gui();
            else cout<<"不能下这里"<<endl;}

            else if(temp[0]==4) {if(react4(color,temp[1])) gui();
            else cout<<"不能下这里"<<endl;}

            if(temp1[0]==3) {if(react3(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;}


            else if(temp1[0]==4) {if(react4(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;}


            else if(temp1[0]==5) {if(react5(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;}


            else if(temp1[0]==6) {if(react6(color,temp1[1])) gui();
            else cout<<"不能下这里"<<endl;}

        //cout << temp[0] << " " << temp[1] << endl;
        //cout << temp1[0] << " " << temp1[1] << endl;
    }
    else
    {
        cout << "不能下这里" << endl;//位置不存在
    } */
}


/* 

bool react4(int color, int row)
{
    bool all = false;
    for (int dx = -1; dx <= 1; dx++)
    { //二向搜索,翻转棋子
        if (dx == 0)
            continue;
        int times = 1; //记录循环次数
        int flag = 0;  // 1表示实际 ，0表示虚拟
        for (int rowp = row + dx; times < 8; rowp += dx, times++)
        {
            if (rowp >= 8)
            {
                rowp -= 8;
                flag = 1;
            }
            if (rowp <= -1)
            {
                rowp += 8;
                flag = -1;
            }
            if (flag == 0)
            {
                if (*a4[rowp] != -color )
                    break; //不是反色就退出 如果一直是同色就继续
                else if (*a4[rowp + dx] == color)
                {
                    for (; rowp != row; rowp -= dx)
                    {
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                    }
                    all = true;
                    break;
                }
            }
            else if (flag == -1)
            {
                if(rowp==7){
                    if (*a4[rowp] == color  )
                    rowp -= 7;//比如从7减到0

                    for (; rowp != row; rowp -= dx){
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                        
                    }
                        
                    all = true;
                    break;
                }
                else {
                    if (*a4[rowp] != -color )
                        break;
                    else if (*a4[rowp+dx] == color)
                    {
                        for (; rowp != 8; rowp -= dx)
                            *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子

                        rowp -= 8;

                        for (; rowp != row; rowp -= dx)
                            *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                        all = true;
                        break;
                    }
                }
            }
            else if (flag == 1)
            {
                
                if(rowp==0){
                    if (*a4[rowp] == color  )
                    rowp += 7;//比如从0加到7

                    for (; rowp != row; rowp -= dx){
                        *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                        
                    }
                        
                    all = true;
                    break;
                }
                else {
                    if (*a4[rowp] != -color  )
                    break;
                    else if (*a4[rowp+dx] == color)
                    {
                        for (; rowp != -1; rowp -= dx)
                            *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子

                        rowp += 8;

                        for (; rowp != row; rowp -= dx)
                            *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                        all = true;
                        break;
                    }

                }
                
            }
        }
        
    }
    if (all)
        return true;
    else
        return false;
}



 */


/* //处理rowp+dx过界的问题
                if(rowp+dx==8){
                    if (*a4[rowp] != -color )break; //不是反色就退出 如果一直是同色就继续
                    else if (*a4[rowp+dx-8] == color)
                    {
                        for (; rowp != row; rowp -= dx)
                        {
                            *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                        }
                        all = true;
                        break;
                    }
                }
                else if(rowp+dx==-1){
                    if (*a4[rowp] != -color )break; //不是反色就退出 如果一直是同色就继续
                    else if (*a4[rowp+dx+8] == color)
                    {
                        for (; rowp != row; rowp -= dx)
                        {
                            *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                        }
                        all = true;
                        break;
                    }
                }
                else{
                    if (*a4[rowp] != -color )break; //不是反色就退出 如果一直是同色就继续
                    else if (*a4[rowp+dx] == color)
                    {
                        for (; rowp != row; rowp -= dx)
                        {
                            *a4[rowp] = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                        }
                        all = true;
                        break;
                    }
                    
                } */