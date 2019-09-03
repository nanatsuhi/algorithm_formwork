#include <bits/stdc++.h>
using namespace std;
int n, m, c, a[100001][35];
int main()
{
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
                scanf("%d", &a[i][0]);
        c = (int)(log2(n));
        for (int j = 1; j <= c; j++)
                for (int i = 1; i <= n - (1 << j) + 1; i++)
                        a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
        while (m--)
        {
                int l, r;
                scanf("%d%d", &l, &r);
                int p = (int)(log2(r - l + 1));
                printf("%d\n", max(a[l][p], a[r - (1 << p) + 1][p]));
        }
        return 0;
}