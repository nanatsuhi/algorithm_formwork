#include <iostream>
#include <cstdio>
using namespace std;
int fa[10005], n, m;
int father(int k)
{
        int kk = k;
        while (fa[kk] != kk)
                kk = fa[kk];
        int i;
        while (fa[k] != k)
        {
                i = k;
                k = fa[k];
                fa[i] = kk;
        }
        return kk;
}
int main()
{
        for (int i = 0; i < 10005; i++)
                fa[i] = i;
        scanf("%d%d", &n, &m);
        while (m--)
        {
                int ask, x, y;
                scanf("%d%d%d", &ask, &x, &y);
                if (ask == 1)
                        fa[father(x)] = father(y);
                else if (father(x) == father(y))
                        printf("Y\n");
                else
                        printf("N\n");
        }
        return 0;
}