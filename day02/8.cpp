#include "iostream"

using namespace std;

const int MAX = 1000;

int num[MAX] = { 0 };

int main(int argc, char const* argv[])
{
    int k, n = 0;
    int avg = 0;
    while (cin >> k) {
        num[n++] = k;
        avg += k;
    }
    avg /= n;
    for (int i = 0; i < n; i++) {
        if (num[i] > avg)
            cout << num[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
