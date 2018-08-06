#include "iostream"

using namespace std;

int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(int argc, char const* argv[])
{
    int year, month, day;
    cin >> year >> month >> day;
    bool leap = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0);
    d[1] += leap;
    if (month < 1 or month > 12 or (day < 0 or day > d[month - 1])) {
        cout << "Incorrect!" << endl;
    } else {
        cout << "Correct!" << endl;
    }

    system("pause");
    return 0;
}
