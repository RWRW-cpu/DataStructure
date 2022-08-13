#include <stdio.h>
#include <stdlib.h>   
/*
具体思路如下：
1.定义一个二维数组chessboard[8][8]，用于保存黑白双方棋子的位置。如果数组元素为0，表示该单元格未落子；如果是-1，表示该单元格是黑子；如果是1，则表示该单元格是白子。
 2.当一方下棋时，先检查是否有位置可下，如果有则己方下棋，如果没有就让对手下棋。
 3.若玩家下，需要等待玩家输入棋子坐标，然后执行翻转对手棋子操作。
4.若计算机下，程序需对棋盘所有可以落子的位置进行判断，找出最佳的落子位置，然后执行翻转对手棋子操作。  9 5.重复步骤2~4，直到棋盘已满或双方都不能下子时结束。 
 */
void Output(char chessboard[][8]); //显示棋盘中的下子情况
 int Check(char chessboard[][8],int moves[][8],char player);//检查一方是否有位置下子
 void PlayStep(char chessboard[][8],int row,int col,char player);//在指定位置下棋
void AutoPlayStep(char chessboard[][8],int moves[][8],char player);//计算机思考下子
 int GetMaxScore(char chessboard[][8],char player);//获取分数
 int BestPlay(char chessboard[][8],int moves[][8],char player);//最优下子位置 
 
 
  int main(){
    char chessboard[8][8];//保存棋盘中各单元格下子的状态
    int isDown[8][8] = {0};//保存棋盘中的各个位置是否可以下子，可以下的位置为1，其余为0 
     int row,col,x,y;
    int iCount = 0;//以下子的数量
   int player = 0;//下棋方
    int SkipPlay = 0;//重置下子的次数为0，若为2，则表示双方都不能下子
    int Score[2];//保存计算机和玩家的得分
   
    char select,ch;
  
   printf("黑白棋\n\n");
    printf("玩家执黑子先行，计算机执白，按Enter开始\n");
    
    scanf("%c",&select);
     
     do{
         
         if(player==0){
             player = 1;
         }else{
             player = 0;
         }
          
         for(row=0;row<8;row++){
             for(col=0;col<8;col++){
                  chessboard[row][col]=0;
              }
        }
         
          iCount = 4;//游戏开始的四颗棋子 
       chessboard[3][3] = chessboard[4][4] = 1;
         chessboard[3][4] = chessboard[4][3] = -1;
        
         printf("\n棋盘初始状态：\n");
        Output(chessboard);
         
          //双方下棋 
        do{
              if(player==1){//玩家下棋（黑） 
                player = 0;
                  if(Check(chessboard,isDown,2)){
                     while(1){
                          fflush(stdin);
                         printf("输入下子的位置（行，列）：");
                        scanf("%d%c",&x,&ch);                         x--;//因为数组是从0开始存的 
                         if(ch>='a'){
                              y = ch - 'a' + 1;
                        } else{
                           y = ch - 'A' + 1;
                        }
                        y--;
                        //判断是否越界、是否已有棋子 
                         if(x>=0&&x<8&&y>=0&&y<8&&isDown[x][y]){
                            PlayStep(chessboard,x,y,2);
                           iCount++;
                            break; 
                          }else{
                            printf("坐标输入有误，请重新输入。\n\n");
                        }
                     }
                    
                    printf("\n你下子之后的状态：\n");
                     Output(chessboard);
                    system("pause"); 
                }else if(++SkipPlay < 2){//无效下子的次数小于2 
                     fflush(stdin);
                      printf("你没位置可下，按Enter让计算机下子");
                   scanf("%c",&select); 
                } else{
                    printf("双方都没位置下子，游戏结束！\n");
                 }
             }else{//计算机下棋（白） 
                player = 1;
                if(Check(chessboard,isDown,1)) {
                    SkipPlay = 0;//清除无效下子次数
                     AutoPlayStep(chessboard,isDown,1); //下子
                   iCount++;
                     printf("\n计算机下子后的状态：\n");
                     Output(chessboard); 
                 }else if(++SkipPlay < 2){//无效下子的次数小于2 
                     fflush(stdin);
                     printf("我没位置可下，你走\n");
                     scanf("%c",&select); 
                 } else{
                     printf("双方都没位置下子，游戏结束！\n");
                }
           
            
            
            } 
            
            
        }while(iCount<64&&SkipPlay<2);
        
        Output(chessboard);
         Score[0] = Score[1]= 0;//清空几份变量 
          
         for(row=0;row<8;row++){
             for(col=0;col<8;col++){
                 if(chessboard[row][col]==-1){
                     Score[0]++;//统计黑子数量 
                 }
                 if(chessboard[row][col]==1){
                     Score[1]++;//统计白子数量 
                 }
             }
         }
         printf("最终成绩：\n");
         printf("玩家：%d\n计算机：%d\n",Score[0],Score[1]);
         fflush(stdin);
         printf("继续下一局（y/n）？\n");
         scanf("%c",&select); 
         
     }while(select=='y'||select=='Y');
     printf("游戏结束！");
     system("pause");
     return 0; 
          
 }
 
 
 //显示棋盘中的下子情况
 void Output(char chessboard[][8]){
     int row, col;
   printf("\n  ");
   for (col = 0; col < 8; col++)        //输出列标号
         printf("  %c", 'A' + col);
   printf("\n");
   printf("  ┌");    //输出顶部横线
   for (col = 0; col < 7; col++)        //输出一行
         printf("——┬");
   printf("——┐\n");
   for (row = 0; row < 8; row++)
   {
         printf("%2d|", row + 1);       //输出行号
         for (col = 0; col < 8; col++)  //输出棋盘各单元格中棋子的状态
         {
         if (chessboard[row][col] == 1)  //白棋
             printf("○ |");
         else if (chessboard[row][col] == -1)    //黑棋
             printf("● |");
         else   //未下子处
             printf("  |");
         }
         printf("\n");
         if (row < 8-1)
         {
         printf("  ├"); //输出交叉线
         for (col = 0; col < 8-1; col++)   //输出一行
             printf("——┼");
         printf("——┤\n");
         }
   }
   printf("  └");
   for (col = 0; col < 8-1; col++) //最后一行的横线
         printf("——┴");
   printf("——┘\n");
 }
 
 //检查一方是否有位置下子
 int Check(char chessboard[][8], int isDown[][8], char player)
 {
   int rowdelta, coldelta, row, col, x, y = 0;
   int iStep = 0;//可下的位置数量 
   char opponent = (player == 1) ? -1 : 1;   //对方棋子
   char myplayer = -1 *opponent;//我方棋子
   for (row = 0; row < 8; row++) //将isDown数组全部清0
         for (col = 0; col < 8; col++)
         isDown[row][col] = 0;
   for (row = 0; row < 8; row++) //循环判断棋盘中的哪些单元格可以下子
   {
         for (col = 0; col < 8; col++)
         {
             if (chessboard[row][col] != 0)  //若棋盘上的对应位置不为空(表示已经有子)
                 continue;   //继续处理下一个单元格
             for (rowdelta = -1; rowdelta <= 1; rowdelta++)  //循环检查上下行
             {
                 for (coldelta = -1; coldelta <= 1; coldelta++)   //循环检查左右列
                 {
                   if (row + rowdelta < 0 || row + rowdelta >= 8 || col + coldelta < 0 || col + coldelta >= 8|| (rowdelta == 0 && coldelta == 0))//若坐标超过棋盘或为当前单元格
                                           continue;  //继续循环
                   if (chessboard[row + rowdelta][col + coldelta] == opponent)//若(row,col)四周有对手下的子
                   {
                           x = row + rowdelta;    //以对手的下子位置为坐标
                           y = col + coldelta;
                           while(1)//以对手的下子为起始点，沿着该方向查找自己方的棋子，以攻击对方棋子
                           {
                             x += rowdelta; //对手下子的四周坐标
                             y += coldelta;
                             if (x < 0 || x >= 8 || y < 0 || y >= 8) //超过棋盘
                                 break;  //退出循环
                              if (chessboard[x][y] == 0)          //若对应位置为空
                                break;
                              if (chessboard[x][y] == myplayer) //若对应位置下的子是当前棋手的
                             {
                                //设置移动数组中对应位置为1 (该位置可下子，形成向对手进攻的棋形)
                               isDown[row][col] = 1;
                                  iStep++;                //加可下子的位置数量
                                 break;
                             }
                          }
                   }
                 }
             }
         }
   }
   return iStep; //返回可下的位置数量（若返回值为0，表示没地方可下）
 }    
 
 
 //在指定位置下子
 void PlayStep(char chessboard[][8], int row, int col, char player)
 {
   int rowdelta = 0;
   int coldelta = 0;
   int x = 0;
   int y = 0;
   char opponent = (player == 1) ? -1 : 1;   //对方棋子
   char myplayer = -1 * opponent;//我方棋子
   chessboard[row][col] = myplayer;  //保存所下的棋子
   for (rowdelta = -1; rowdelta <= 1; rowdelta++)//检查所下子四周的棋子
   {
         for (coldelta = -1; coldelta <= 1; coldelta++)
         {
             if (row + rowdelta < 0 || row + rowdelta >= 8 || col + coldelta < 0 || col + coldelta >= 8 || (rowdelta == 0 && coldelta == 0))
                         //若坐标超过棋盘界限
                         continue;   //继续下一位置
                     //若该位置是对手的棋子
                     if (chessboard[row + rowdelta][col + coldelta] == opponent)
                     {
                         x = row + rowdelta; //以对手的棋子作为坐标
                         y = col + coldelta;
                         while(1) //在对手棋子的四周寻找我方棋子
                         {
                           x += rowdelta;
                           y += coldelta;
                           if (x < 0 || x >= 8 || y < 0 || y >= 8)   //若坐标超过棋盘
                                   break; //退出循环
                           if (chessboard[x][y] == 0)//若对应位置为空
                                   break; //退出循环
                           if (chessboard[x][y] == myplayer) //若对应位置是我方棋子
                           {
                               //循环处理
                               while (chessboard[x -= rowdelta][y -= coldelta] == opponent)
                               chessboard[x][y] = myplayer;   //将中间的棋子都变成我方棋子
                               break; //退出循环
                           }
                         }
                     }
         }
   }
 }
 
 //计算机自动下子
 void AutoPlayStep(char chessboard[][8], int isDown[][8], char player)
 {
   int row, col, row1, col1, i, j;
   int Score = 0, MinScore = 100;//对方可下子得到的分数和最小分数
   char chessboard1[8][8];   //临时数组，保存棋盘的下子位置
   int isDown1[8][8];    //临时数组，保存可下子的位置
   char opponent = (player == 1) ? -1 : 1;   //对手下的棋子
   for (row = 0; row < 8; row++) //循环检查棋盘的每个单元格
   {
         for (col = 0; col < 8; col++)
         {
         if (isDown[row][col] == 0)  //若不可下子
             continue;           //继续下一个位置
         for (i = 0; i < 8; i++)//将棋盘原来的棋子复制到临时数组中
             for (j = 0; j < 8; j++)
         chessboard1[i][j] = chessboard[i][j];
         PlayStep(chessboard1, row, col, player);
                                 //试着在临时棋盘中的一个位置下子
         Check(chessboard1, isDown1, opponent);  //检查对手是否有地方可下子
         Score = BestPlay(chessboard1, isDown1, opponent);
                                 //获得临时棋盘中对方下子的得分情况
         if (Score < MinScore)   //保存对方得分最低的下法
         {
             MinScore = Score;
             row1 = row;
             col1 = col;
         }
         }
   }
   PlayStep(chessboard, row1, col1, player); //计算机按最优下法下子
 }
 
 //获取分数
 int GetMaxScore(char chessboard[][8], char player)
 {
   int Score, row, col;
   char opponent = (player == 1) ? -1 : 1;       //对方棋子
   char myplayer=-1*opponent;
  for (row = 0; row < 8; row++)                 //循环
   {
         for (col = 0; col < 8; col++)
         {
         //如果棋盘对应位置是对手下的棋子，从总分中减1分
        Score -= chessboard[row][col] == opponent;
         //如果棋盘对应位置是我方的棋子，在总分中加1分
         Score += chessboard[row][col] == myplayer;
         }
   }
   return Score;                                 //返回分数
 }
 
 //最优下子位置 
    int BestPlay(char chessboard[][8], int isDown[][8], char player)
 {
   int row, col, i, j;
   char chessboard1[8][8] = { 0 };   //定义一个临时数组
   int MaxScore = 0;                 //保存最高分
   int Score = 0;
   char opponent = (player == 1) ? -1 : 1;//对手下的棋子
   for (row = 0; row < 8; row++)     //循环检查每个单元格
   {
         for (col = 0; col < 8; col++)
         {
         if (!isDown[row][col])      //如果该位置不可下子
             continue;               //继续检查
         for (i = 0; i < 8; i++)     //复制棋盘各单元格下子的状态到临时数组
             for (j = 0; j < 8; j++)
               chessboard1[i][j] = chessboard[i][j];
         PlayStep(chessboard1, row, col, player);    //在临时数组中的指定行列下子
         Score = GetMaxScore(chessboard1, player);   //获取下子后可得到的分数
         if (MaxScore < Score)       //若原方案得到的分数小于本次下子的分数
             MaxScore = Score;       //保存最高分
         }
   }
   return MaxScore;                  //返回得到的最高分
 }