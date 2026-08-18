#include <iostream>
#include <cmath>

using namespace std;

long long n, l, r;

int main()
{
    cin >> n >> l >> r;

    double round;
    long long num;

    round = floor(l / n);
    num = n * round;

    if (num + n - 1 > r)
    {
        cout << r - num << endl;
    }
    else
    {
        cout << n - 1 << endl;
    }

    return 0;
}