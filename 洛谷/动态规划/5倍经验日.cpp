#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 1e3 + 10;
int n;
int f[N];
struct nums
{
    int a,b,c;
    bool operator < (const nums&t)const
    {
        if (c != t.c) return c<t.c;
        return b>t.b;
    }
}news[N];


int main()
{
    int x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        scanf("%d%d%d",&news[i].a,&news[i].b,&news[i].c);
    sort(news , news+n);
    for (int i = 0; i < n; i++)
        for (int j = x; j >= 0; j--)
        { 
            if (j >= news[i].c)//药剂够用
            {
                f[j] = max(f[j] + news[i].a ,f[j - news[i].c] + news[i].b);//能赢你
            }
            else f[j] += news[i].a;//赢不了
        }
    cout << 5*f[x] << endl;
    return 0;
}
