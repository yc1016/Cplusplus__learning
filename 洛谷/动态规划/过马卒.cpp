#include<bits/stdc++.h>
using namespace std; 
const int N = 40;

// 记录马控制的范围偏移量
int x_ways[9] = { 0, 2, 1,1, 2,-2,-1,-1,-2};
int y_ways[9] = { 0,-1,-2,2, 1,-1,-2, 2, 1};
int s[N][N];//标记马的控制点
long long f[N][N];
///最朴素版
int main()
{
    int bx,by,mx,my;
    cin >> bx >> by >> mx >> my;
    bx += 2, by += 2, mx += 2, my += 2;
    for (int i = 0; i < 9; i++) s[mx + x_ways[i]][my + y_ways[i]] = 1;
    f[2][1] = 1;//保证第一次规划后，为1
    //枚举横,纵坐标
    for (int i = 2; i <= bx; i++)
        for (int j = 2; j <= by; j++)
        {
            if(s[i][j]) continue;
            else
                f[i][j] = f[i-1][j] + f[i][j-1];//从上边来的和从左边来的
        }
    cout << f[bx][by] << endl;
    return 0;
}
