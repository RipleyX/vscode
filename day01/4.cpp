#include "iostream"

using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    int num[4];

    //encode
    num[1] = n / 1000;
    num[0] = n % 1000 / 100;
    num[3] = n % 1000 % 100 / 10;
    num[2] = n % 1000 % 100 % 10;

    int code = 0;
    int rank = 1;
    for (int i = 0; i < 4; i++) {
        num[i] = (num[i] + 7) % 10;
        code += (num[i] * rank);
        rank *= 10;
    }

    for (int i = 0; i < 4; i++) {
        cout << num[3 - i];
    }
    cout << endl;

    //decode
    num[1] = code / 1000;
    num[0] = code % 1000 / 100;
    num[3] = code % 1000 % 100 / 10;
    num[2] = code % 1000 % 100 % 10;

    int decode = 0;
    rank = 1;
    for (int i = 0; i < 4; i++) {
        num[i] = (num[i] + 3) % 10;
        decode += (num[i] * rank);
        rank *= 10;
    }

    for (int i = 0; i < 4; i++) {
        cout << num[3 - i];
    }
    cout << endl;

    system("pause");
    return 0;
}
