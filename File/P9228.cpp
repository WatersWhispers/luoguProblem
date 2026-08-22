#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int kMAXN = 1e6 + 5;

int n, m, k;
int a[kMAXN], b[kMAXN];
int genshin = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    if (n >= m)
    {
        sort(a + 1, a + 1 + n, [](int a_, int b_)
             { return a_ > b_; });
        sort(b + 1, b + 1 + m, [](int a_, int b_)
             { return a_ < b_; });

        for (int i = n; i > m; i--)
        {
            genshin += a[i];
        }
    }

    else
    {
        sort(a + 1, a + 1 + n, [](int a_, int b_)
             { return a_ < b_; });
        sort(b + 1, b + 1 + m, [](int a_, int b_)
             { return a_ > b_; });

        for (int i = m; i > n; i--)
        {
            genshin += b[i];
        }
    }

    int num = min(n, m);

    for (int i = 1; i <= num; i++)
    {
        genshin += max(a[i] + b[i] + k, b[i] + 2 * a[i]);
    }

    cout << genshin << endl;

    return 0;
}