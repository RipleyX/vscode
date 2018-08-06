#include "iostream"

using namespace std;

int main(int argc, char const* argv[])
{
    int num = 1;
    for (int i = 0; i < 9; i++) {
        num = (num + 1) * 2;
    }
    cout << num << endl;
    system("pause");
    return 0;
}
