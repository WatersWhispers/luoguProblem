#include <iostream>

using namespace std;

const int kMaxn = 1e6 + 5;

int n, maxn = -1;
int tree[kMaxn];
int real[kMaxn];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a]++;
        tree[b + 1]--;
    }

    for (int i = 0; i <= 1e6; i++)
    {
        real[i] = real[i - 1] + tree[i];
        maxn = max(maxn, real[i]);
    }

    cout << maxn;

    return 0;
}