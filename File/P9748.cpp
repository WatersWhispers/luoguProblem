#include <iostream>
#include <cmath>

using namespace std;

int n;

int main()
{
    cin >> n;

    int sum = 0, cnt = n;
    int day = 0, dayn = 0;
    bool flag = false;

    while (sum != n)
    {
        sum += ceil(cnt * 1.0 / 3);
        cnt -= ceil(cnt * 1.0 / 3);

        day++;

        if (cnt % 3 == 1 && flag == false)
        {
            dayn = day + 1;
            flag = true;
        }
    }

    if ((n - 1) % 3 == 0)
    {
        cout << day << " " << 1;
        return 0;
    }

    cout << day << " " << dayn;

    return 0;
}