#include "iostream"

using namespace std;

int main(int argc, char const* argv[])
{
    int num = 0;
    for (int i = 6; i < 1000; i++) {
        int sum = 1;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            num++;
            cout << i;

            if (num == 5) {
                num = 0;
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
