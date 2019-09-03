#include <cstdio>
#include <algorithm>
using namespace std;
inline int read()
{
        int x = 0, f = 1, ch = getchar();
        while (ch < '0' || ch > '9')
        {
                if (ch == '-')
                        f = -1;
                ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
                x = x * 10 + ch - '0';
                ch = getchar();
        }
        return x * f;
}
inline void write(int x)
{
        if (x < 0)
                putchar('-'), x = -x;
        if (x >= 10)
                write(x / 10);
        putchar(x % 10 + '0');
}
inline void writeln(int x)
{
        write(x);
        puts("");
}
const int maxn = 1000005;
struct node
{
        int dis, val, ls, rs;
} a[maxn];
int root, n;
int merge(int &x, int &y)
{
        if (!x || !y)
                return x + y;
        if (a[x].val > a[y].val)
                swap(x, y);
        a[x].rs = merge(a[x].rs, y);
        if (a[a[x].ls].dis < a[a[x].rs].dis)
                swap(a[x].ls, a[x].rs);
        a[x].dis = a[a[x].rs].dis + 1;
        return x;
}
int main()
{
        int T = read();
        while (T--)
        {
                int opt = read();
                if (opt == 1)
                {
                        a[++n].val = read();
                        int temp = n;
                        root = merge(root, temp);
                }
                if (opt == 2)
                        writeln(a[root].val);
                if (opt == 3)
                        root = merge(a[root].ls, a[root].rs);
        }
        return 0;
}