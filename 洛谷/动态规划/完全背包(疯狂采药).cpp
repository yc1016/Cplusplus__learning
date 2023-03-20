#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 1e7 + 10;
int T;
int m;
long long f[N];
PII s[N];


int main()
{
    cin >> T >> m;
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        s[i] = {a,b};//时间，价值
    }    
    // sort(s+1,s+m+1);
    for (int i = 1; i <= m; i++)
        for (int j = s[i].x; j <= T; j++)
        {
            f[j] = max(f[j],f[j - s[i].x]+s[i].y);
        }
    cout << f[T] << endl;
    return 0; 
}