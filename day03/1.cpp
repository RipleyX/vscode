#include "cmath"
#include "iostream"
#include "vector"

using namespace std;

bool prime(int n) //质数判断
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const* argv[])
{
    vector<int> primeSet;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (prime(i))
            primeSet.push_back(i);
    }

    for (int i = 1; i < primeSet.size(); i++) {
        if (primeSet[i] - primeSet[i - 1] == 2) {
            cout << primeSet[i - 1] << " " << primeSet[i] << endl;
        }
    }

    system("pause");
    return 0;
}
