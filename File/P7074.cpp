#include <iostream>
#include <cstring>

using namespace std;

const int kMAXN = 1e3 + 5;
const int INF = 1e9;

int n, m;
int grid[kMAXN][kMAXN];
long long dp[1005][1005][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    fill(&dp[0][0][0], &dp[0][0][0] + kMAXN * kMAXN * 2, -INF);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    dp[1][1][0] = dp[1][1][1] = grid[1][1];

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i != 1 || j != 1)
            {
                dp[i][j][0] = max({dp[i - 1][j][0], dp[i][j - 1][0], dp[i][j - 1][1]}) + grid[i][j];
            }
        }

        for (int i = n; i >= 1; i--)
        {
            if (j != 1)
            {
                dp[i][j][1] = max({dp[i + 1][j][1], dp[i][j - 1][0], dp[i][j - 1][1]}) + grid[i][j];
            }
        }
    }

    cout << max(dp[n][m][0], dp[n][m][1]) << endl;

    return 0;
}