#include "iostream"

using namespace std;

int main(int argc, char const* argv[])
{
    int Denominator = 1, Numerator = 1;
    int n, i;
    cin >> n;
    for (i = 1; n > i; i++) {
        n -= i;
    }
    if (i % 2 == 0) { //斜行分子分母存在规律，可轻松推算
        Numerator = n;
        Denominator = i - n + 1;
    } else {
        Numerator = i - n + 1;
        Denominator = n;
    }
    cout << Numerator << "/" << Denominator << endl;
    system("pause");
    return 0;
}
