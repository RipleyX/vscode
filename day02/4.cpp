#include "iostream"

using namespace std;

int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(int argc, char const* argv[])
{
    int day_sum = 0;
    int year, month, day;
    cin >> year >> month >> day;
    bool leap = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0);
    d[1] += leap;

    if (month < 1 or month > 12 or (day < 0 or day > d[month - 1])) {
        cout << "Incorrect!" << endl;
        system("pause");
        return -1;
    } else {
        for (int i = 0; i < month - 1; i++) {
            day_sum += d[i];
        }
        day_sum += day;
        cout << day_sum << endl;
    }

    system("pause");
    return 0;
}
