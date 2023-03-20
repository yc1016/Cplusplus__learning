//无记忆化，tle
//记录高度图，判断走哪条，判断走过没有，记录步数，判断什么时候结束
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
int b[N];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cnt;


int get(int x,int y)
{
	return x*n + y;
}

bool check(int x,int y)//是不是要停止了
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		int a = dx[i],b = dy[i];
		//滑不了了
		if (x+a >= n || x+a < 0 || y+b >= m || y+b <0) continue;
		if ((hmap[get(x,y)] > hmap[get(x+a,y+b)])) flag = 1;
	}
	if (flag) return false;
	return true;
}

void dfs(int x,int y,int dis)
{
    s[get(x,y)] = dis;
    if(check(x,y))
    {
        if (cnt < s[get(x,y)])
        {
            cnt = s[get(x,y)];
        }
        return;
    }
	for (int w = 0; w < 4; w++)
	{
		int a = dx[w],b = dy[w];
		if (hmap[get(x,y)] <= hmap[get(x+a,y+b)]) continue;
		if (x+a >= n || x+a < 0 || y+b >= m || y+b <0) continue;
		dfs(x+a,y+b,dis+1);
        s[get(x,y)] = max(dis,s[get(x+a,y+b)]);
	}
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
			if (cnt > hmap[get(i,j)]) continue;
			dfs(i,j,1);//起点和现在的长度
		}
	cout << cnt << endl;
	return 0;
}
