#include <iostream>
#include <cstring>

using namespace std;

int t;
char ch[1005][1005];
bool flag[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--)
    {
        int n, m, k;
        int x0, y0, d;

        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> ch[i][j];
            }
        }

        memset(flag, 0, sizeof(flag));
        flag[x0][y0] = true;

        for (int i = 1; i <= k; i++)
        {
            int nx = x0;
            int ny = y0;

            if (d == 0)
                ny++;
            else if (d == 1)
                nx++;
            else if (d == 2)
                ny--;
            else if (d == 3)
                nx--;

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && ch[nx][ny] == '.')
            {
                x0 = nx, y0 = ny;
                flag[nx][ny] = true;
                continue;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }

        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cnt += flag[i][j];
            }
        }

        cout << cnt << endl;
    }

    return 0;
}