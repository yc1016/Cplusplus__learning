//记录路径，更新路径长度，判断是否使用过该点
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int N =  25;
int n,m;
int w[N];//记录每个地窖的地雷数
int f[N][N];//记录两个地窖是否相通，通为1，不通为0
bool st[N];//判断这个点是否走过
// int sum;//dfs内部地雷数和
int maxw;//最大地雷数
int path[N];//dfs内部路径更新
int ans[N];//答案路径
int dis;//跟进路径长度

bool check(int x)//判断是不是要停了
{
	for (int i = x+1; i <= n; i++)
		if (f[x][i] && !st[i])//如果有后继，并且可以走
			return false;
	return true;
}

void dfs(int x,int stp, int sum)
{
	if (check(x))//如果不能继续走了，走到尽头了
	{
		//判断是否比最大值大
		if (sum >= maxw)
		{
			dis = stp;
			for (int i = 1; i <= stp; i++)
				ans[i] = path[i];//路线答案更新
			maxw = sum;//最大值更新
		}
		return;
	}

	for (int i = x+1; i <= n; i++)
	{
		if (f[x][i] && !st[i])
		{
			st[i] = 1;
			path[stp+1] = i;//路线更新
			dfs(i,stp+1,sum+w[i]);
			st[i] = 0;
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			cin >> f[i][j];//i到j是否可行
	//dfs不同的起点
	for (int i = 1; i <= n; i++)
	{
		path[1] = i;//路线起始点是i
		st[i] = 1;
		dfs(i,1,w[i]);
		st[i] = 0;
	}
	for (int i = 1; i <= dis; i++)
		cout << ans[i] << ' ';
	cout << endl << maxw;
	return 0;
}