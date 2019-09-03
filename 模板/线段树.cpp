#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[100005], tree[100005 * 4], lazy[100005 * 4];
void build(ll s, ll t, ll p)
{
        if (s == t)
        {
                tree[p] = a[s];
                return;
        }
        ll mid = (s + t) / 2;
        build(s, mid, p * 2);
        build(mid + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
        return;
}
ll ask(ll l, ll r, ll s, ll t, ll p)
{
        if (s >= l && t <= r)
        {
                return tree[p];
        }

        ll sum = 0, mid = (s + t) / 2;
        if (lazy[p] != 0)
        {
                lazy[p * 2] += lazy[p];
                lazy[p * 2 + 1] += lazy[p];
                tree[p * 2] += lazy[p] * (mid - s + 1);
                tree[p * 2 + 1] += lazy[p] * (t - mid);
                lazy[p] = 0;
        }
        if (l <= mid)
                sum += ask(l, r, s, mid, p * 2);
        if (r > mid)
                sum += ask(l, r, mid + 1, t, p * 2 + 1);
        return sum;
}
void update(ll l, ll r, ll c, ll s, ll t, ll p)
{
        if (s >= l && t <= r)
        {
                tree[p] += (t - s + 1) * c;
                lazy[p] += c;
                return;
        }
        ll mid = (s + t) / 2;
        if (lazy[p] != 0)
        {
                lazy[p * 2] += lazy[p];
                lazy[p * 2 + 1] += lazy[p];
                tree[p * 2] += lazy[p] * (mid - s + 1);
                tree[p * 2 + 1] += lazy[p] * (t - mid);
                lazy[p] = 0;
        }
        if (l <= mid)
                update(l, r, c, s, mid, p * 2);
        if (r > mid)
                update(l, r, c, mid + 1, t, p * 2 + 1);
        tree[p] = tree[2 * p] + tree[2 * p + 1];
        return;
}
int main()
{
        scanf("%lld%lld", &n, &m);
        for (ll i = 1; i <= n; i++)
                scanf("%lld", &a[i]);
        build(1, n, 1);
        while (m--)
        {
                ll ctrl;
                scanf("%lld", &ctrl);
                if (ctrl == 1)
                {
                        ll x, y, k;
                        scanf("%lld%lld%lld", &x, &y, &k);
                        update(x, y, k, 1, n, 1);
                }
                if (ctrl == 2)
                {
                        ll x, y;
                        scanf("%lld%lld", &x, &y);
                        printf("%lld\n", ask(x, y, 1, n, 1));
                }
        }
        return 0;
}