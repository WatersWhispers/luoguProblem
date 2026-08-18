#include <iostream>
#include <cmath>

using namespace std;

int n, w;
int a[100005];
int t[605];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int num = max(1, (int)floor(i * 1.0 * w / 100));
        int sum = 0;

        t[a[i]]++;

        for (int j = 600; j >= 0; j--)
        {
            sum += t[j];

            if (sum >= num)
            {
                cout << j << " ";
                break;
            }
        }
    }

    return 0;
}