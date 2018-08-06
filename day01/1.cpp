#include "iostream"

using namespace std;

int main(int argc, char const* argv[])
{
    long long sec = 0;
    cin >> sec;
    long long d = 0, h = 0, m = 0, s = 0;
    d = sec / (60 * 60 * 24);
    h = sec % (60 * 60 * 24) / (60 * 60);
    m = sec % (60 * 60 * 24) % (60 * 60) / 60;
    s = sec % (60 * 60 * 24) % (60 * 60) % 60;
    cout << d << "," << h << "," << m << "," << s << endl;

    system("pause");
    return 0;
}
