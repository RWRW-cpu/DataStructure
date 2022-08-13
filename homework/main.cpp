#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;


int temp[2];
int temp1[2];

class Chess{
    public:
    int chess[7][9];
    //初始化棋盘
    /*
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 0, 0, 4, 4, 4, 4,
    4, 4, 4, 0, 0, 4, 4, 4, 4,
    4, 0, 0, -1, 1, 0, 0, 0, 0,
    4, 0, 0, 1, -1, 0, 0, 0, 0,
    4, 4, 4, 0, 0, 4, 4, 4, 4,
    4, 4, 4, 0, 0, 4, 4, 4, 4
     */
    Chess(){
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 9; j++){
                chess[i][j] = 4;
            }
        }
        chess[1][3]=0;chess[1][4]=0;
        chess[2][3]=0;chess[2][4]=0;
        chess[3][1]=0; chess[3][2]=0; chess[3][3]=-1;chess[3][4]=1;chess[3][5]=0;chess[3][6]=0;chess[3][7]=0;chess[3][8]=0;
        chess[4][1]=0; chess[4][2]=0; chess[4][3]=1;chess[4][4]=-1;chess[4][5]=0;chess[4][6]=0;chess[4][7]=0;chess[4][8]=0;
        chess[5][3]=0;chess[5][4]=0;
        chess[6][3]=0;chess[6][4]=0;
    }

};


//链表
class List{
    public:
    int *a[8];
};

//初始化指针
void init2(List *list,Chess &ch){
     //初始化链表
    list[1].a[0] = &ch.chess[1][3];
    list[1].a[1] = &ch.chess[2][3];
    list[1].a[2] = &ch.chess[3][3];
    list[1].a[3] = &ch.chess[4][3];
    list[1].a[4] = &ch.chess[5][3];
    list[1].a[5] = &ch.chess[6][3];
    list[1].a[6] = &ch.chess[3][8];
    list[1].a[7] = &ch.chess[4][8];

    list[2].a[0] = &ch.chess[1][4];
    list[2].a[1] = &ch.chess[2][4];
    list[2].a[2] = &ch.chess[3][4];
    list[2].a[3] = &ch.chess[4][4];
    list[2].a[4] = &ch.chess[5][4];
    list[2].a[5] = &ch.chess[6][4];
    list[2].a[6] = &ch.chess[3][7];
    list[2].a[7] = &ch.chess[4][7];

    list[3].a[0] = &ch.chess[3][1];
    list[3].a[1] = &ch.chess[3][2];
    list[3].a[2] = &ch.chess[3][3];
    list[3].a[3] = &ch.chess[3][4];
    list[3].a[4] = &ch.chess[3][5];
    list[3].a[5] = &ch.chess[3][6];
    list[3].a[6] = &ch.chess[3][7];
    list[3].a[7] = &ch.chess[3][8];

    list[4].a[0] = &ch.chess[4][1];
    list[4].a[1] = &ch.chess[4][2];
    list[4].a[2] = &ch.chess[4][3];
    list[4].a[3] = &ch.chess[4][4];
    list[4].a[4] = &ch.chess[4][5];
    list[4].a[5] = &ch.chess[4][6];
    list[4].a[6] = &ch.chess[4][7];
    list[4].a[7] = &ch.chess[4][8];

    list[5].a[0] = &ch.chess[3][2];
    list[5].a[1] = &ch.chess[2][3];
    list[5].a[2] = &ch.chess[2][4];
    list[5].a[3] = &ch.chess[3][5];
    list[5].a[4] = &ch.chess[4][5];
    list[5].a[5] = &ch.chess[5][4];
    list[5].a[6] = &ch.chess[5][3];
    list[5].a[7] = &ch.chess[4][2];

    list[6].a[0] = &ch.chess[3][1];
    list[6].a[1] = &ch.chess[1][3];
    list[6].a[2] = &ch.chess[1][4];
    list[6].a[3] = &ch.chess[3][6];
    list[6].a[4] = &ch.chess[4][6];
    list[6].a[5] = &ch.chess[6][4];
    list[6].a[6] = &ch.chess[6][3];
    list[6].a[7] = &ch.chess[4][1];

}
//寻找两条链子
bool  insearch2(int x,int y,List *list,Chess &ch){
    int flag = 0;
    for (int i = 0; i < 8; i++)
    {
        if (&ch.chess[x][y] == list[1].a[i])
        {
            temp[0] = 1;
            temp[1] = i;
            flag++;
            break;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (&ch.chess[x][y] == list[2].a[i])
        {
            temp[0] = 2;
            temp[1] = i;
            flag++;
            break;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (&ch.chess[x][y] == list[3].a[i])
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
        if (&ch.chess[x][y] ==list[4].a[i])
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
        if (&ch.chess[x][y] == list[5].a[i])
        {
            temp1[0] = 5;
            temp1[1] = i;
            flag++;
            return true;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (&ch.chess[x][y] == list[6].a[i])
        {
            temp1[0] = 6;
            temp1[1] = i;
            flag++;
            return true;
        }
    }
        return false;
}
//输出棋盘界面
void gui(Chess ch)
{
    system("cls");
    int score_black = 0, score_white = 0;
    printf("\033[0m\n        [黑白棋]\n\n    1 2 3 4 5 6 7 8\n  ┌─────────────────┐\n");
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (j % 8 == 1)
                printf(" %c│ ", (i * 8 + j) / 8 - 1 + 'A');
            switch (ch.chess[i][j])
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


//判断位置是否下过
bool judgeAlready(int x,int y,Chess ch){
    if(ch.chess[x][y]==0||ch.chess[x][y]==2||ch.chess[x][y]==-2) return true;//可以下棋
    return false;
}
//n为链表的次序，color是1或者0，row是链表的第几个元素
bool react(int color,int n,int row,List *list){
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
                else if(rowp+dx==-1){
                    temp=rowp+dx+8;
                }
                else {
                    temp=rowp+dx;
                }
                if (*(list[n].a[rowp]) != -color )break; //不是反色就退出 如果一直是同色就继续
                else if (*(list[n].a[temp]) == color)
                {
                    for (; rowp != row; rowp -= dx)
                    {
                        *(list[n].a[rowp]) = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                    }
                    all = true;
                    break;
                }

            }
            //去下界
            else if (flag == -1)
            {
                
                if (*(list[n].a[rowp]) != -color )
                    break;
                else if (*(list[n].a[rowp+dx]) == color)
                {
                    for (; rowp != 8; rowp -= dx)
                        *(list[n].a[rowp]) = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子

                    rowp -= 8;

                    for (; rowp != row; rowp -= dx)
                        *(list[n].a[rowp]) = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
                    all = true;
                    break;
                }
            }
            //去上界
            else if (flag == 1)
            {
                
                //正常的搜索
                if (*(list[n].a[rowp]) != -color  )
                break;
                else if (*(list[n].a[rowp+dx]) == color)
                {
                    for (; rowp != -1; rowp -= dx)
                        *(list[n].a[rowp]) = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子

                    rowp += 8;

                    for (; rowp != row; rowp -= dx)
                        *(list[n].a[rowp]) = color; //存在反色棋子则搜寻同色,并翻转中间的所有反色棋子
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

//n为链表的次序，color是1或者0，row是链表的第几个元素
bool reactReal(int color,int n,int row,List *list){
    bool all = false;
    for (int dx = -1; dx <= 1; dx++)
    { //二向搜索,翻转棋子
        if (dx == 0)
            continue;
        int times = 1; //记录循环次数
        int flag = 0;  // 1，-1表示过界 ，0表示正常
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
                else if(rowp+dx==-1){
                    temp=rowp+dx+8;
                }
                else {
                    temp=rowp+dx;
                }
                if (*(list[n].a[rowp]) != -color )break; //不是反色就退出 如果一直是同色就继续
                else if (*(list[n].a[temp]) == color)
                {
                    *(list[n].a[row])=2*color;
                    all = true;
                    break;
                }

            }
            //去下界
            else if (flag == -1)
            {
                
                if (*(list[n].a[rowp]) != -color )
                    break;
                else if (*(list[n].a[rowp+dx]) == color)
                {
                    *(list[n].a[row])=2*color;
                    all = true;
                    break;
                }
            }
            //去上界
            else if (flag == 1)
            {
                
                //正常的搜索
                if (*(list[n].a[rowp]) != -color  )
                break;
                else if (*(list[n].a[rowp+dx]) == color)
                {
                    *(list[n].a[row])==2*color;
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

//搜索可下棋的部位//并翻转
bool insearchReal(int color,List *list,Chess &ch){

    //重置
    for(int i=1;i<=6;i++){
        for(int j=1;j<=8;j++){
            //重新标记
            if(ch.chess[i][j]==2||ch.chess[i][j]==-2){
                ch.chess[i][j]=0;
            }
        }
    }

    for(int j=1;j<=6;j++)
    for(int i=0;i<8;i++){
        if(*(list[j].a[i])==0) reactReal(color,j,i,list);
    }
    
    for(int i=1;i<=6;i++){
        for(int j=1;j<=8;j++){
            if(ch.chess[i][j]==color*2) return true;
        }
    }
    return false;
}


struct Move
{
	int row, col;
};

int  player = 1, opponent = -1;
//贪心算法评价这个棋盘
int evaluate(List *list,Chess &ch){
    int score=0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=8;j++){
            if(ch.chess[i][j]==player)
            {
                score++;
            }
            else if(ch.chess[i][j]==opponent)
            {
                score--;
            }
        }
    }
    return score;
}

Chess copychess(Chess &ch0,Chess &ch){
	Chess temp;
	for(int i=1;i<=6;i++)
	for(int j=1;j<=8;j++)
	{
		ch.chess[i][j]=ch0.chess[i][j];
	}
}

int afabeta(List *list,Chess &ch, int depth, bool isMax,int alpha,int beta){
    int score = evaluate(list,ch);

	//如果这个评价大于7，就是比对方要多7颗棋子
	if (score >=7 )
		return score;

	//如果这个评价小于-14，就是比对方要少14颗棋子
	if (score <= -14)
		return score;

	//该子无子可下
	if (insearchReal(isMax==true?player:opponent,list,ch)==false)
		return 0;

	//如果是白棋下，也就是max方
	if (isMax)
	{
		int best = -1000;

		// Traverse 整个棋盘
		for (int i = 1; i<=6; i++)
		{
			for (int j = 1; j<=8; j++)
			{
				// 判断是否能下
				if (ch.chess[i][j]==player*2)
				{
                    //先copy一下，以便后面的撤销
                    Chess tempch;
                    copychess(ch,tempch);
					// 做选择
					ch.chess[i][j] = player;
                    insearch2(i,j,list,ch);
					react(player,temp[0],temp[1],list);
					react(player,temp1[0],temp1[1],list);

					// 取胜率的最大值
					// 更新alpha值
					best = max( best,
						afabeta(list,ch, depth+1, !isMax,alpha,beta) );
                    alpha = max(alpha, best);

					// 撤销
					copychess(tempch,ch);
                    // Alpha Beta 剪枝叶
                    if (beta <= alpha)
                            break;       
                    
				}
			}
		}
		return best;
	}

	//如果是黑棋下，也就是min方
	else
	{
		int best = 1000;

		// Traverse 整个棋盘
		for (int i = 1; i<=6; i++)
		{
			for (int j = 1; j<=8; j++)
			{
				// 判断是否能下
				if (ch.chess[i][j]==2*opponent)
                {
                    //先copy一下，以便后面的撤销
                    Chess tempch;
                    copychess(ch,tempch);
					// 做选择
                    ch.chess[i][j] = opponent;
                    insearch2(i,j,list,ch);
                    react(opponent,temp[0],temp[1],list);
                    react(opponent,temp1[0],temp1[1],list);
					

					// 取胜率的最小值
					// 更新beta
					best = min(best,
						afabeta(list,ch, depth+1, !isMax,alpha,beta));
                    beta = min(beta, best);

					// 撤销
                    copychess(tempch,ch);
                    // Alpha Beta 剪枝叶
                    if (beta <= alpha)
                        break;					
				}
			}
		}
		return best;
	}    
}

Move findBestMove(List *list,Chess &ch){
    int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	// Traverse 整个棋盘
    //evaluate afabeta 可下的棋子的胜率
    //return 可选项
	for (int i = 1; i<=6; i++)
	{
		for (int j = 1; j<=8; j++)
		{
			// 判断是否能下
			if (ch.chess[i][j]==2*player)
			{
                //先copy一下，以便后面的撤销
                Chess tempch;
                copychess(ch,tempch);
				// 做选择
                ch.chess[i][j] = player;
                insearch2(i,j,list,ch);
                react(player,temp[0],temp[1],list);
                react(player,temp1[0],temp1[1],list);

				//算出score
				int moveVal = afabeta(list,ch, 0, false,-1000,1000);

				// 撤销
				copychess(tempch,ch);

				//如果之后的score较大，则更新
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	printf("AI能赢你%d个棋子\n",
			bestVal);

	return bestMove;
    
}

//除了没下其他棋子全为白棋
bool allColor(Chess &ch){
    for(int i=1;i<=6;i++)
	for(int j=1;j<=8;j++)
	{
		if(ch.chess[i][j]==-1) return false;
	}
}

int main()
{
    List *list=new List [7];
    Chess ch;
    init2(list,ch);

    int sign=4;
    //int sign=19;
    int color=-1;//黑手先下
    int x=0, y=0;
    // system("pause");
    do{
        //寻找可以下棋的位置,并react标记成2或者-2
        if(insearchReal(color,list,ch)) {
            
            gui(ch);
            //输出
            if(x!=0&&y!=0) printf("%s 下了 %d %d\n",color!=1?"白棋":"黑棋",x,y);
            printf("%s 下：",color==1?"白棋":"黑棋");

            //黑棋输入
            if(color==-1){
                scanf("%d %d", &x, &y);
                if(insearch2(x,y,list,ch)&&judgeAlready(x,y,ch))
                {
                    //先是不能
                    if(!react(color,temp[0],temp[1],list)&&!react(color,temp1[0],temp1[1],list)){
                        
                        printf("11%s不能在这里下棋\n" ,color==1 ? "白方" : "黑方" );
                        x=0;//不记录这次的x，y
                        y=0;
                        system("pause");
                    }
                    else{//可下棋
                        sign++;
                        ch.chess[x][y]=color;
                        color=-color;//反色

                    }
                }
                else//下过了
                {
                    printf("22%s不能在这里下棋\n" ,color==1 ? "白方" : "黑方" );
                    x=0;//不记录这次的x，y
                    y=0; 
                    system("pause");
                }
            }
            else{//进到这里后AI不用考虑不能呢下的问题
                //AI bestMove=findBestMove(list,ch);
                clock_t start = clock(); 
                //AI是x，我们是o
                //AI是player，我们是opponent
                Move bestMove = findBestMove(list,ch);
                clock_t end = clock();
                printf(" AI思考的时间 : %f second\n", (double)(end - start) / CLOCKS_PER_SEC);

                //翻转并下棋
                insearch2(bestMove.row,bestMove.col,list,ch);
                react(color,temp[0],temp[1],list);
                react(color,temp1[0],temp1[1],list);
                sign++;
                ch.chess[ bestMove.row][ bestMove.col]=1;
                x=bestMove.row;
                y=bestMove.col;
                color=-color;//反色以便对方下棋
                system("pause");
            }
        }
        else if(allColor(ch)){
            sign=24;
        }
        else{
            gui(ch);
            if(x!=0&&y!=0) printf("%s 下了 %d %d\n",color!=1?"白棋":"黑棋",x,y);
            printf("%s无子可下\n",color==1 ? "白方" : "黑方" );
            system("pause");
            color=-color;//反色
            x=0;//不记录这次的x，y
            y=0;    
        }
    }while(sign!=24);

    int wirte=0,black=0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=8;j++){
            if(ch.chess[i][j]==1) wirte++;
            else if(ch.chess[i][j]==-1) black++;
            else continue;
        }
    }
    gui(ch);
    if(wirte>black) printf("白方胜利");
    else if(wirte==black) printf("平局");
    else printf("黑方胜利");
}

