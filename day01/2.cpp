#include <cctype>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    char c, out;
    cin >> c;
    while (!islower(c)) {
        cout << "not low alpha character!" << endl;
        cin >> c;
    }

    out = 25 - (c - 'a') + 'a';
    cout << out << endl;
    system("pause");
    return 0;
}
