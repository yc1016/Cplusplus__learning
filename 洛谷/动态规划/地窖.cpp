//��¼·��������·�����ȣ��ж��Ƿ�ʹ�ù��õ�
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int N =  25;
int n,m;
int w[N];//��¼ÿ���ؽѵĵ�����
int f[N][N];//��¼�����ؽ��Ƿ���ͨ��ͨΪ1����ͨΪ0
bool st[N];//�ж�������Ƿ��߹�
// int sum;//dfs�ڲ���������
int maxw;//��������
int path[N];//dfs�ڲ�·������
int ans[N];//��·��
int dis;//����·������

bool check(int x)//�ж��ǲ���Ҫͣ��
{
	for (int i = x+1; i <= n; i++)
		if (f[x][i] && !st[i])//����к�̣����ҿ�����
			return false;
	return true;
}

void dfs(int x,int stp, int sum)
{
	if (check(x))//������ܼ������ˣ��ߵ���ͷ��
	{
		//�ж��Ƿ�����ֵ��
		if (sum >= maxw)
		{
			dis = stp;
			for (int i = 1; i <= stp; i++)
				ans[i] = path[i];//·�ߴ𰸸���
			maxw = sum;//���ֵ����
		}
		return;
	}

	for (int i = x+1; i <= n; i++)
	{
		if (f[x][i] && !st[i])
		{
			st[i] = 1;
			path[stp+1] = i;//·�߸���
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
			cin >> f[i][j];//i��j�Ƿ����
	//dfs��ͬ�����
	for (int i = 1; i <= n; i++)
	{
		path[1] = i;//·����ʼ����i
		st[i] = 1;
		dfs(i,1,w[i]);
		st[i] = 0;
	}
	for (int i = 1; i <= dis; i++)
		cout << ans[i] << ' ';
	cout << endl << maxw;
	return 0;
}