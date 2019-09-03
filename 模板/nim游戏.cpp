#include <bits/stdc++.h>
using namespace std;
int ans, n, T;
int main()
{
        scanf("%d", &T);
        while (T--)
        {
                scanf("%d", &n);
                ans = 0;
                for (int i = 0; i < n; i++)
                {
                        int x;
                        scanf("%d", &x);
                        ans ^= x;
                }
                if (ans)
                        printf("Yes\n");
                else
                        printf("No\n");
        }
        return 0;
}