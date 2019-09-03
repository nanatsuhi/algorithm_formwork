#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int dis[1005][1005],n,m;
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            i==j?dis[i][j]=0:dis[i][j]=inf;
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    while(m--)
    {
        int a,b,l;
        scanf("%d%d%d",&a,&b,&l);
        dis[a][b]=l;
        //dis[b][a]=l;  //无向图加一行
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",dis[a][b]==1e9+7?-1:dis[a][b]);
    }
    return 0;
}