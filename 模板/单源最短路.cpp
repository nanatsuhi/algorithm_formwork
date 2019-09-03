#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int n,m,str;
int d[100005],vis[100005];
int first[100005],nex[200005],ver[200005],edge[200005];
priority_queue<pair<int,int> >q; //记得打空格。。
void add_edge(int i,int a,int b,int c)
{
    ver[i]=b;
    edge[i]=c;
    nex[i]=first[a];
    first[a]=i;
    return;
}
void dijkstra(int st)
{
    for(int i=1;i<=n;i++) d[i]=inf;
    memset(vis,0,sizeof(vis));
    d[st]=0;
    q.push(make_pair(0,st));
    while(q.size())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=first[x];i;i=nex[i])
        {
            int y=ver[i],z=edge[i];
            if(d[x]!=inf&&z!=inf&&d[y]>d[x]+z)
            {
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&str);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add_edge(i,a,b,c);
    }
    dijkstra(str);
    for(int i=1;i<=n;i++) printf("%d ",d[i]);
    return 0;
}