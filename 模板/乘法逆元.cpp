#include <bits/stdc++.h>
#define N 3000010
typedef long long ll;
using namespace std;
int inv[N], n, p;
int main()
{
        cin >> n >> p;
        inv[1] = 1;
        puts("1");
        for (int i = 2; i <= n; i++)
        {
                inv[i] = (ll)(p - p / i) * inv[p % i] % p;
                printf("%d\n", inv[i]);
        }
        return 0;
}