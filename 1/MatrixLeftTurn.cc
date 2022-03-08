#include <iostream>
using namespace std;

void rotate(int *Matrix,int *ChangedMatrix)
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            *(ChangedMatrix+(2-j)*2+i) =*(Matrix+i*3+j);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    int Matrix[2][3];
    int ChangedMatrix[3][2];
    while (t--)
    {
        //输入矩阵
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                cin>>Matrix[i][j];

        //算法左转
        rotate(*Matrix , *ChangedMatrix);
        
        //输出矩阵
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<*(*(ChangedMatrix+i)+j)<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
