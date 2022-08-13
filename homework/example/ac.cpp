#include <cstdio>
#include <cstring>
using namespace std;
template <typename T> T min(const T &x, const T &y) { return x < y ? x : y; }
template <typename T> T max(const T &x, const T &y) { return x > y ? x : y; }
const int weight[10][10] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 65,  -3, 6, 4, 4, 6,  -3, 65, 0,
    0, -3, -29, 3, 1, 1, 3, -29, -3, 0,
    0, 6,   3, 5, 3, 3, 5,   3,  6, 0,
    0, 4,   1, 3, 1, 1, 3,   1,  4, 0,
    0, 4,   1, 3, 1, 1, 3,   1,  4, 0,
    0, 6,   3, 5, 3, 3, 5,   3,  6, 0,
    0, -3, -29, 3, 1, 1, 3, -29, -3, 0,
    0, 65,  -3, 6, 4, 4, 6,  -3, 65, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};//苟的debian黑白棋AI的权值表
const int d[8][2] =
{
    -1, 0, 1, 0, 0, -1, 0, 1,
    -1, -1, -1, 1, 1, -1, 1, 1
};
#define re register
int state[10][10], ansx, ansy;
//black:1 white:-1
int cur[10][10];
inline int alpha_beta(int dep, int player, int alpha, int beta, int cnt) //0 for me 1 for it
{
    if(dep > 9 || cnt > 64) //dep是搜索的层数
    {
        int ret = 0;
        for(re int i = 1; i <= 8; ++i)
            for(re int j = 1; j <= 8; ++j)
                ret += weight[i][j]*state[i][j];
        return ret;
    }
    int temp[10][10], tot = 0;
    memcpy(temp, state, sizeof state);
    if(!player)
        for(re int id = 1, x, y, i, j; id <= 64; ++id)
        {
            i = (id-1>>3)+1, j = (id-1)%8+1;
            if(state[i][j] == 0)
            {
                int flag = 0, t;
                for(re int k = 0; k < 8; ++k)
                {
                    t = 0, x = i+d[k][0], y = j+d[k][1];
                    while(state[x][y] == -1) t++, x += d[k][0], y += d[k][1];
                    if(t && state[x][y] == 1)
                    {
                        do
                        {
                            x -= d[k][0], y -= d[k][1];
                            state[x][y] = 1;
                        } while(x != i || y != j);
                        flag = 1;
                    }
                }
                if(flag)
                {
                    tot++;
                    int v = alpha_beta(dep+1, player^1, alpha, beta, cnt+1);
                    if(v > alpha)
                    {
                        if(!dep) ansx = i, ansy = j, memcpy(cur, state, sizeof state);
                        alpha = v;
                    }
                    memcpy(state, temp, sizeof temp);
                    if(beta <= alpha) break;
                }
            }
        }
    if(!tot) player = 1;
    if(player)
    {
        for(re int id = 1, x, y, tx, ty, i, j; id <= 64; ++id)
        {
            i = (id-1>>3)+1, j = (id-1)%8+1;
            if(state[i][j] == 0)
            {
                int flag = 0, t;
                for(re int k = 0; k < 8; ++k)
                {
                    t = 0, x = i+d[k][0], y = j+d[k][1];
                    while(state[x][y] == 1) t++, x += d[k][0], y += d[k][1];
                    if(t && state[x][y] == -1)
                    {
                        do
                        {
                            x -= d[k][0], y -= d[k][1];
                            state[x][y] = -1;
                        } while(x != i || y != j);
                        flag = 1;
                    }
                }
                if(flag)
                {
                    int v = alpha_beta(dep+1, player^1, alpha, beta, cnt+1);
                    if(beta > v) beta = v;
                    memcpy(state, temp, sizeof temp);
                    if(beta <= alpha) break;
                }
            }
        }
    }
    return !player ? alpha : beta;
}
int main()
{
    memset(cur, 0, sizeof cur);
    cur[4][4] = cur[5][5] = -1, cur[4][5] = cur[5][4] = 1;
    for(int i = 0; i < 10; ++i) cur[0][i] = cur[9][i] = -2;
    for(int i = 1; i < 9; ++i) cur[i][0] = cur[i][9] = -2;
    for(int i = 0, tx, ty; i < 32; ++i)
    {
        memcpy(state, cur, sizeof cur);
        ansx = -1, ansy = -1;
        alpha_beta(0, 0, -1000000000, 1000000000, i*2);
        if(ansx != -1)
        {
            printf("----------\n");
            printf("you should put here:%d %d\n", ansx, ansy);
            for(int p = 1; p <= 8; ++p)
            {
                for(int q = 1; q <= 8; ++q) printf("%d", cur[p][q] < 0 ? 2 : cur[p][q]);
                printf("\n");
            }
            printf("----------\n");
        }
        printf("Enter your competitor's move(If he can't even move,just type -1 -1):"); scanf("%d%d", &tx, &ty);
        if(tx == -1) continue;
        for(int k = 0, x, y, t; k < 8; ++k)
        {
            t = 0, x = tx+d[k][0], y = ty+d[k][1];
            while(cur[x][y] == 1) t++, x += d[k][0], y += d[k][1];
            if(t && cur[x][y] == -1)
            {
                do
                {
                    x -= d[k][0], y -= d[k][1];
                    cur[x][y] = -1;
                } while(x != tx || y != ty);
            }
        }
    }
    return 0;
}