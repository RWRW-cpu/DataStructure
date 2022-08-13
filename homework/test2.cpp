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
int temp[2];
int temp1[2];

//链表
class List{
    public:
    int *a[8];
};

//初始化指针
void init2(List *list){
     //初始化链表
    list[1].a[0] = &chess[1][3];
    list[1].a[1] = &chess[2][3];
    list[1].a[2] = &chess[3][3];
    list[1].a[3] = &chess[4][3];
    list[1].a[4] = &chess[5][3];
    list[1].a[5] = &chess[6][3];
    list[1].a[6] = &chess[3][8];
    list[1].a[7] = &chess[4][8];

    list[2].a[0] = &chess[1][4];
    list[2].a[1] = &chess[2][4];
    list[2].a[2] = &chess[3][4];
    list[2].a[3] = &chess[4][4];
    list[2].a[4] = &chess[5][4];
    list[2].a[5] = &chess[6][4];
    list[2].a[6] = &chess[3][7];
    list[2].a[7] = &chess[4][7];

    list[3].a[0] = &chess[3][1];
    list[3].a[1] = &chess[3][2];
    list[3].a[2] = &chess[3][3];
    list[3].a[3] = &chess[3][4];
    list[3].a[4] = &chess[3][5];
    list[3].a[5] = &chess[3][6];
    list[3].a[6] = &chess[3][7];
    list[3].a[7] = &chess[3][8];

    list[4].a[0] = &chess[4][1];
    list[4].a[1] = &chess[4][2];
    list[4].a[2] = &chess[4][3];
    list[4].a[3] = &chess[4][4];
    list[4].a[4] = &chess[4][5];
    list[4].a[5] = &chess[4][6];
    list[4].a[6] = &chess[4][7];
    list[4].a[7] = &chess[4][8];

    list[5].a[0] = &chess[3][2];
    list[5].a[1] = &chess[2][3];
    list[5].a[2] = &chess[2][4];
    list[5].a[3] = &chess[3][5];
    list[5].a[4] = &chess[4][5];
    list[5].a[5] = &chess[5][4];
    list[5].a[6] = &chess[5][3];
    list[5].a[7] = &chess[4][2];

    list[6].a[0] = &chess[3][1];
    list[6].a[1] = &chess[1][3];
    list[6].a[2] = &chess[1][4];
    list[6].a[3] = &chess[3][6];
    list[6].a[4] = &chess[4][6];
    list[6].a[5] = &chess[6][4];
    list[6].a[6] = &chess[6][3];
    list[6].a[7] = &chess[4][1];

}

//输出棋盘界面
void gui()
{
    //system("cls");
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






int main()
{
    List *list=new List [7];
    cout<<chess[1][3]<<endl;
    init2(list);
    cout<<chess[1][3]<<endl;
    chess[1][3]=-1;
    cout<<chess[1][3]<<endl;
    chess[2][3]=-1;
    chess[3][1]=-1;
    chess[4][1]=-1;
    chess[4][2]=-1;
    chess[4][5]=-1;
    chess[4][6]=-1;
    chess[4][7]=-1;
    chess[4][8]=-1;
    chess[1][3]=1;
    chess[3][2]=1;
    chess[3][3]=1;
    chess[4][3]=1;
    chess[4][4]=1;
    chess[5][3]=1;
    chess[5][4]=1;
    chess[6][3]=1;
    gui();
    cout<<chess[1][3]<<endl;


    
    


   /*  int sign=4;
    int color;
    int x, y;
    // system("pause");
    do{
        
        if(sign%2==0)color=-1;
        else color=1;
        insearchReal(color,list);
        gui();
        if(sign!=4) printf("%s 下了 %d %d\n",color!=1?"白棋":"黑棋",x,y);
        printf("%s 下：",color==1?"白棋":"黑棋");
        scanf("%d %d", &x, &y);
        if(insearch2(x,y,list)&&judgeAlready(x,y))
        {
            //先是反面
            if(!react(color,temp[0],temp[1],list)&&!react(color,temp1[0],temp1[1],list)){
                printf("11%s不能在这里下棋\n" ,color==1 ? "白方" : "黑方" );
            }
            else{
                sign++;
                chess[x][y]=color;
            }
        }
        else
        {
            printf("22%s不能在这里下棋\n" ,color==1 ? "白方" : "黑方" );
        }
    }while(sign!=24); */
}
