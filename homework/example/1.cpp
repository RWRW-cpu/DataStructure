#include<iostream>
#include<windows.h> 
#include<cstdlib> 
#include<time.h>
#include<fstream>
using namespace std;
int N;//棋盘规模大小
int sum = 0;//计数
char chess[11][11];//初始化棋盘数组,不超过10*10 

class Start//开始工作 
{
public:
	void show();//展示页面
	void work();//开始工作，包含五个模块
	void screen();//最终反馈，程序运行
	void rule();//规则
	void clear();//初始化棋盘 
	void print();//打印棋盘
	int sum_one();//统计一手数量
	int sum_two();//统计二手数量
};
class Solve//解决问题 
{
public:
	bool find(int a, int b, int k);//保证正方形内都不是为空
	bool sure(int x, int y, int k, int a, int b);//保证每一个点都是在正方形内和棋盘内
	bool xyjudge(int a, int b, int k);//XY轴对称判断
	void Judge(int a, int b);//落子查找判断
	void reverse(int a, int b, int k, int x, int y);//翻转
	void predict();//输出答案
	//小部分功能封装
	void calulate(int n);//落子赋值和判断的过程
};
class Pattern// 模式
{
public:
	void player();//人人
	void computer();//人机
	void twocomputer();//机机
};
void Start::show()//游戏页面 
{
	system("color F2");
	cout << "=======================================================================================================================" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "对称棋" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "1.规则" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "2.人人对战" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "3.人机对战" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "4.机机对战" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "5.退出游戏" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "   请输入你要操作的序号：";
}
void Start::work()//执行操作 
{
	Pattern pattern;
	Start start;
	int num;
	start.show();
	cin >> num;
	switch (num)
	{
	case 1:
		system("cls");
		Start::rule();
		break;
	case 2:
		system("cls");
		pattern.player();
		break;
	case 3:
		system("cls");
		pattern.computer();
		break;
	case 4:
		system("cls");
		pattern.twocomputer();
		break;
	case 5:
		exit(0);//退出游戏 
		break;
	}
	sum = 0;//重新归0 
}
void Start::screen()//最终反馈 
{
	while (1)
	{
		Start start;
		start.work();
		cout << "按任意数字返回主界面：";
		int n;
		cin >> n;
		system("cls");
	}
}
void Start::rule()//规则说明 
{
	cout << "=======================================================================================================================" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "规则" << endl << endl;
	cout << "  “对称”是一种新的抽象策略棋盘游戏。游戏的规则非常简单，使用对称的概念，并导致一个非常具有挑战性的游戏。" << endl;
	cout << "  “对称”是一个抽象的2人游戏。玩家需要在棋盘上创建对称的图案以获得领地，同时防止对手在棋盘上创建对称的图案。" << endl;
	cout << "  对称性的激发规则如下:" << endl;
	cout << "  黑白相间轮流把石头放在石头上NxN板（白色开始)";
	cout << "  当一块石头放在木板上使一块正方形完全被石头复盖时，如果这块正方形的石头颜色图案变成水平或垂直的“镜子”对称，这个正方形就变成最后一块石头的颜色";
	cout << "  所以“对角对称“不会引起任何颜色变化";
	cout << "  对称正方形可能有任何大小(2x2，3x3，4x4等)。";
	cout << "  有时一个以上的方块会因为移动而变成对称。所有这些方块都会改变颜色。";
	cout << "  当棋盘上没有空的字段时游戏结束。";
	cout << "  胜者是在最后有最多他们的颜色的石头在棋盘上的球员" << endl;
	cout << "=======================================================================================================================" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "样例：" << endl << endl;
	cout << "1 0" << "                1 1 " << endl << "1 0" << "                0 0 " << endl;
	cout << "水平对称" << "           垂直对称" << endl;
	cout << "1 0 1" << endl << "0 1 0" << endl << "1 0 1" << endl;
	cout << "既水平对称又垂直对称" << endl << endl;
	cout << "注意：一手为1  二手为0     在人机对战中你是一手 ，人机和机机对战图一乐，随机套用" << endl;
	cout << "=======================================================================================================================" << endl;
}
void Start::clear()//初始化棋盘 
{
	system("color F2");//实现背景色白，字体为绿
	cout << endl << endl;
	//cout << '\t' << '\t' << '\t' << '\t' << '\t' << "你要设置的棋盘规模大小： ";
	//cin >> N;
    N=8;
	/* for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			chess[i][j] = '.';
		}
	} */
    for(int i=1;i<=6;i++){
        if(i==3||i==4){
            for(int j=1;j<=N;j++){
            chess[i][j] = '.';
            }
        }
        else{
            for(int j=1;j<=N;j++){
                if(j==3||j==4) chess[i][j] = '.';
                else chess[i][j]=' ';
            }
        }
    }
}
void Start::print()//打印棋盘 
{
	Start start;
	cout << endl << endl;
	cout << '\t' << '\t' << '\t';
	cout << " ";
	for (int i = 1; i <= N; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		if (i != 10) { cout << '\t' << '\t' << '\t' << i << " "; }
		else { cout << '\t' << '\t' << '\t' << i; }

		for (int j = 1; j <= N; j++)
		{
			cout << chess[i][j] << " ";

		}
		if (i == 1)
		{
			cout << "   一手: " << start.sum_one();

		}
		else if (i == 2)
		{
			cout << "   二手: " << start.sum_two();

		}
		cout << endl;
	}

}
bool Solve::find(int a, int b, int k)//用于查找正方形里是否填满以及是否可以构成一个正方形，没有就返回false,有则true ,考虑到奇数边长正方形有一条边长在计算对称会忽略 
{
	//a,b是坐标，k是边长
	bool flag = false;//标记是否 
	for (int i = a; i < a + k && a + k <= N + 1; i++)
	{
		for (int j = b; j < b + k && b + k <= N + 1; j++)
		{
			if (chess[i][j] != '.')//初始化为空
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (!flag) { break; }
	}
	return flag;
}
void Solve::Judge(int a, int b)//判断正方形是否对称， 也就是符合情况的正方形的左上角坐标全部在，a,b围成的区域里，其他只会重复 
{
	Solve solve;
	bool flag = false;
	int x[10], y[10], c[10];//存储符合情况的坐标和边长 ，因为N为10，也就是边长为10，最大的正方形也才10，符合情况的在10以内 
	int cnt = 0;
	for (int k = 2; k <= N; k++)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			for (int j = k - 1; j >= 0; j--)
			{
				if (solve.find(a - i, b - j, k) && solve.sure(a - i, b - j, k, a, b) && solve.xyjudge(a - i, b - j, k))
				{
					x[cnt] = a - i; y[cnt] = b - j; c[cnt] = k;
					cnt++;
				}
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		solve.reverse(x[i], y[i], c[i], a, b);//翻转 
	}
	Start start;
	start.print();//打印 

}
bool Solve::sure(int x, int y, int k, int a, int b)//针对部分情况，有些点要在正方形区域里面 
{
	bool flag1 = a <= x + k - 1 && a >= x && b <= y + k - 1 && b >= y;
	bool flag2 = x * y <= a * b && x * y >= 1;//合法坐标，在(a,b)区域里 
	return flag1 && flag2;
}
bool Solve::xyjudge(int a, int b, int k)//判断X,Y轴对称 ，k是正方形的边长 
{
	bool flag_x = false, flag_y = false;//flag_x判断X轴对称，flag_y判断Y轴对称 
	for (int i = 0; i < k / 2; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (chess[a + i][b + j] == chess[a + k - i - 1][b + j] && chess[a + i][b + j] != '.')//对称且不为空 
			{
				flag_x = true;
			}
			else
			{
				flag_x = false;
				break;
			}
		}
		if (!flag_x) { break; }
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k / 2; j++)
		{
			if (chess[a + i][b + j] == chess[a + i][b + k - j - 1] && chess[a + i][b + j] != '.')//对称且不为空，貌似可以不写find() 
			{
				flag_y = true;
			}
			else
			{
				flag_y = false;//只要有一个不符合就跳出 
				break;
			}
		}
		if (!flag_y) { break; }
	}
	return flag_x | flag_y;//只要有一个符合就行 
}
void Solve::reverse(int a, int b, int k, int x, int y)//实现数组的翻转，a,b,是起始坐标，k是边长，xy是符合对称的坐标 
{
	for (int i = a; i < a + k; i++)
	{
		for (int j = b; j < b + k; j++)
		{
			chess[i][j] = chess[x][y];//chess[x][y]是实现对称的棋子，最后翻转成他的样子
		}
	}
}
int Start::sum_one()//统计每次下棋之后，棋盘里的一手棋数量 
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (chess[i][j] == '1')
			{
				sum++;
			}
		}
	}
	return sum;
}
int Start::sum_two()//统计每次下棋之后，棋盘里的二手棋数量 
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (chess[i][j] == '0')
			{
				sum++;
			}
		}
	}
	return sum;
}
void Solve::predict()//最后比较一手二手最后的棋子数量 
{
	int cnt1 = 0, cnt2 = 0;//一手cnt1,二手cnt2
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (chess[i][j] == '1')
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
	}
	if (cnt1 > cnt2)
	{
		cout << "一手胜利！" << endl;
	}
	else if (cnt1 < cnt2)
	{
		cout << "二手胜利！" << endl;
	}
	else
	{
		cout << "平局！" << endl;
	}
}
void Solve::calulate(int n)
{
	Solve solve;
	Start start;
	if (n == 1)//n==1，一手情况，n==2二手情况 
	{
		cout << "一手坐标：";//默认坐标从（1，1）开始 
		int a, b;
		cin >> a >> b;
		chess[a][b] = '1';
		sum = sum + 1;
		solve.Judge(a, b);//每次落子就要判断，打印棋盘
		system("cls");
		start.print();

	}
	else if (n == 2)
	{
		cout << "二手坐标：";//默认坐标从（1，1）开始 
		int c, d;
		cin >> c >> d;
		chess[c][d] = '0';
		sum = sum + 1;
		solve.Judge(c, d);
		system("cls");
		start.print();

	}
	else if (n == 3)
	{
		int c, d;
		srand((int)time(0));//保证随机数不一样 
		c = 1 + rand() % (N + 1);
		d = 1 + rand() % (N + 1);
		while (chess[c][d] != '.')
		{
			c = 1 + rand() % (N + 1);
			d = 1 + rand() % (N + 1);
		}
		chess[c][d] = '0';//电脑下棋 即应该返回c,d值，也就是坐标 
		sum = sum + 1;
		solve.Judge(c, d);
		system("cls");
		start.print();
	}
	else if (n == 4)
	{
		int a, b;
		a = 1 + rand() % (N + 1);
		b = 1 + rand() % (N + 1);
		while (chess[a][b] != '.')
		{
			a = 1 + rand() % (N + 1);
			b = 1 + rand() % (N + 1);

		}
		chess[a][b] = '1';
		sum = sum + 1;
		solve.Judge(a, b);//每次落子就要判断，打印棋盘
		system("cls");
		start.print();
	}
}
void Pattern::player()//人人对战模式 
{
	Start start;
	Solve solve;
	start.clear();
	system("cls");
	start.print();//打印棋盘
	while (sum < N * N)
	{
		solve.calulate(1);
		if (sum == N * N)
		{
			break;
		}
		solve.calulate(2);
	}
	solve.predict();//棋盘填完，判断谁多
}
void Pattern::computer()//人机对战模式 ,应该只有一层 
{
	//默认自己先手 
	Start start;
	Solve solve;
	start.clear();
	system("cls");
	start.print();//打印棋盘
	while (sum < N * N)
	{
		solve.calulate(1);
		if (sum == N * N)
		{
			break;
		}
		solve.calulate(3);
	}
	solve.predict();//棋盘填完，判断谁多
}
void Pattern::twocomputer()//机机对战 
{
	//默认自己先手 
	Start start;
	Solve solve;
	start.clear();
	system("cls");
	start.print();//打印棋盘
	while (sum < N * N)
	{
		//sum计算一共合计下了多少个棋子
		solve.calulate(4);
		if (sum == N * N)
		{
			break;
		}
		solve.calulate(3);
	}
	solve.predict();//棋盘填完，判断谁多
}
int main()
{
	Start start;
	start.screen();//最终反馈
	return 0;
}
