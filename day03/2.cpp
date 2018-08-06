#include "cmath"
#include "iostream"

using namespace std;

int factor(int k, int n)
{
    int sum = 1;
    for (int i = k; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += factor(i, n / i);
        }
    }
    return sum;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    if (n <= 1) {
        cout << 0 << endl;
    } else {
        cout << factor(2, n) << endl;
    }
    system("pause");
    return 0;
}
