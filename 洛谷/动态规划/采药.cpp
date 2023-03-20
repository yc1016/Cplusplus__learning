#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 110;
int T;
int m;
int w[N],t[N];
int f[N];



int main()
{
    cin >> T >> m;
    for (int i = 1; i <= m; i++)
        scanf("%d%d",&t[i],&w[i]);
    for (int i = 1; i <= m; i++)
        for (int j = T; j >= 0; j--)
        {
            if(t[i] <= j)
            {
                f[j] = max(f[j],f[j-t[i]]+w[i]);
            }
        }
    cout << f[T] << endl;
    return 0; 
}