#include<iostream>
#include<windows.h> 
#include<cstdlib> 
#include<time.h>
#include<fstream>
using namespace std;
    
char chess[7][9];
char *a1[9];
char *a2[9];
char *a3[9];

char *a4[9];
char *a5[9];
char *a6[9];

int temp[2];
int temp1[2];
bool insearch(int x,int y){
    int flag=0;
    for(int i=1;i<=8;i++){
        if(&chess[x][y]==a1[i]){
            temp[0]=1;
            temp[1]=i;
            flag++;
            break;
        }
    }
    for(int i=1;i<=8;i++){
        if(&chess[x][y]==a2[i]){
            temp[0]=2;
            temp[1]=i;
            flag++;
            break;
        }
    }
    for(int i=1;i<=8;i++){
        if(&chess[x][y]==a3[i]){
            if(flag==1) {
                temp1[0]=3;
                temp1[1]=i;
                return true;

            }
            else{
                temp[0]=3;
                temp[1]=i;
                flag++;
            }
        }
    }
    for(int i=1;i<=8;i++){
        if(&chess[x][y]==a4[i]){
            if(flag==1) {
                temp1[0]=4;
                temp1[1]=i;
                return true;

            }
            else{
                temp[0]=4;
                temp[1]=i;
                flag++;
            }
        }
    }
    
    for(int i=1;i<=8;i++){
        if(&chess[x][y]==a5[i]){
            temp1[0]=5;
            temp1[1]=i;
            flag++;
            return true;
        }
    }
    for(int i=1;i<=8;i++){
        if(&chess[x][y]==a6[i]){
            temp1[0]=6;
            temp1[1]=i;
            flag++;
            return true;
        }
    }
    if(flag==0) return false;
}

int main(){
    //初始化棋盘
    for(int i=1;i<=6;i++){
        if(i==3||i==4){
            for(int j=1;j<=8;j++){
            chess[i][j] = '.';
            }
        }
        else{
            for(int j=1;j<=8;j++){
                if(j==3||j==4) chess[i][j] = '.';
                else chess[i][j]=' ';
            }
        }
    }
    //初始化链表
    a1[1]=&chess[1][3];
    a1[2]=&chess[2][3];
    a1[3]=&chess[3][3];
    a1[4]=&chess[4][3];
    a1[5]=&chess[5][3];
    a1[6]=&chess[6][3];
    a1[7]=&chess[3][8];
    a1[8]=&chess[4][8];
                    
    a2[1]=&chess[1][4];
    a2[2]=&chess[2][4];
    a2[3]=&chess[3][4];
    a2[4]=&chess[4][4];
    a2[5]=&chess[5][4];
    a2[6]=&chess[6][4];
    a2[7]=&chess[3][7];
    a2[8]=&chess[4][7];

    a3[1]=&chess[3][1];
    a3[2]=&chess[3][2];
    a3[3]=&chess[3][3];
    a3[4]=&chess[3][4];
    a3[5]=&chess[3][5];
    a3[6]=&chess[3][6];
    a3[7]=&chess[3][7];
    a3[8]=&chess[3][8];

    a4[1]=&chess[4][1];
    a4[2]=&chess[4][2];
    a4[3]=&chess[4][3];
    a4[4]=&chess[4][4];
    a4[5]=&chess[4][5];
    a4[6]=&chess[4][6];
    a4[7]=&chess[4][7];
    a4[8]=&chess[4][8];

    a5[1]=&chess[3][2];
    a5[2]=&chess[2][3];
    a5[3]=&chess[2][4];
    a5[4]=&chess[3][5];
    a5[5]=&chess[4][5];
    a5[6]=&chess[5][4];
    a5[7]=&chess[5][3];
    a5[8]=&chess[4][2];

    a6[1]=&chess[3][1];
    a6[2]=&chess[1][3];
    a6[3]=&chess[1][4];
    a6[4]=&chess[3][6];
    a6[5]=&chess[4][6];
    a6[6]=&chess[6][4];
    a6[7]=&chess[6][3];
    a6[8]=&chess[4][1];



    chess[3][1]='1';
    chess[3][2]='0';
    chess[3][3]='1';
    chess[3][4]='0';
    chess[3][5]='1';
    chess[3][6]='1';
    chess[3][7]='1';
    chess[3][8]='1'; 
    
    
    //特殊情况考虑a1
    int sum1=0;
    int sum0=0;
    for(int i=1;i<=8;i++){
        
        if(*a3[i]=='1')sum1++;
        else if(*a3[i]=='0')sum0++;
        if(sum1==6&&sum0==2||sum1==2&&sum0==6) for(int i=1;i<=8;i++) *(a3[i])='1';
    }
    //给你一个坐标找到他的两条链子
    if(insearch(3,1)){
        cout<<temp[0]<<" "<<temp[1]<<endl;
        cout<<temp1[0]<<" "<<temp1[1]<<endl;
    }


    //判断数组a1两个1之间是否夹着0，如果是，则将a1中的0改为1
    

    
}


 






