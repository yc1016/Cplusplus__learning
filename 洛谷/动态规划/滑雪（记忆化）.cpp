//记录高度图，记录步数,更新最值
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;
const int N = 10110;
int n,m;
int hmap[N];
int s[N];//记录每个点状态
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cnt;

int get(int x,int y)
{
	return x*n + y;
}
int dfs(int x,int y)
{
    if (s[get(x,y)]) return s[get(x,y)];
    s[get(x,y)] = 1;
	for (int w = 0; w < 4; w++)
	{
		int a = dx[w],b = dy[w];
		if (hmap[get(x,y)] <= hmap[get(x+a,y+b)]) continue;
		if (x+a >= n || x+a < 0 || y+b >= m || y+b < 0) continue;
		dfs(x+a,y+b);
        s[get(x,y)] = max(s[get(x,y)],s[get(x+a,y+b)]+1);//每次更新，比较四个方向的长度
	}
    return s[get(x,y)];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d",&hmap[get(i,j)]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
		  //  if (check(i,j)) continue;
			if (cnt > hmap[get(i,j)]) continue;
			cnt = max(dfs(i,j),cnt);//最值更新
		}
	cout << cnt << endl;
	return 0;
}