#include<bits/stdc++.h>
using namespace std; 
const int N = 40;

// ��¼����Ƶķ�Χƫ����
int x_ways[9] = { 0, 2, 1,1, 2,-2,-1,-1,-2};
int y_ways[9] = { 0,-1,-2,2, 1,-1,-2, 2, 1};
int s[N][N];//�����Ŀ��Ƶ�
long long f[N][N];
///�����ذ�
int main()
{
    int bx,by,mx,my;
    cin >> bx >> by >> mx >> my;
    bx += 2, by += 2, mx += 2, my += 2;
    for (int i = 0; i < 9; i++) s[mx + x_ways[i]][my + y_ways[i]] = 1;
    f[2][1] = 1;//��֤��һ�ι滮��Ϊ1
    //ö�ٺ�,������
    for (int i = 2; i <= bx; i++)
        for (int j = 2; j <= by; j++)
        {
            if(s[i][j]) continue;
            else
                f[i][j] = f[i-1][j] + f[i][j-1];//���ϱ����ĺʹ��������
        }
    cout << f[bx][by] << endl;
    return 0;
}
