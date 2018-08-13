#include <bitset>
#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int a = -20;
    cout << bitset<sizeof(int) * 8>(a) << endl;
    a <<= 2;
    cout << bitset<sizeof(int) * 8>(a) << endl;

    system("pause");
    return 0;
}
