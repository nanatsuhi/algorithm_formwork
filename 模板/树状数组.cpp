#include <bits/stdc++.h>
using namespace std;
int a[500005], tree[500005 * 4], n, m, xx, yy;
int lowbit(int num)
{
        return num & (-num);
}
void add(int s, int val)
{
        for (int i = s; i <= n; i += lowbit(i))
                tree[i] += val;
        return;
}
int ask(int q)
{
        int ans = 0;
        while (q)
        {
                ans += tree[q];
                q -= lowbit(q);
        }
        return ans;
}
int main()
{
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
                scanf("%d", &xx);
                a[i] = xx - yy;
                yy = xx;
                add(i, a[i]);
        }
        while (m--)
        {
                int ctrl;
                scanf("%d", &ctrl);
                if (ctrl == 1)
                {
                        int x, y, k;
                        scanf("%d%d%d", &x, &y, &k);
                        add(x, k);
                        add(y + 1, -k);
                }
                if (ctrl == 2)
                {
                        int q;
                        scanf("%d", &q);
                        printf("%d\n", ask(q));
                }
        }
        return 0;
}