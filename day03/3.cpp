#include "iostream"
#include "vector"
using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> v;
    int k;
    while (cin >> k) {
        v.push_back(k);
    }
    for (int i = 1; i < v.size(); i++) {
        for (int j = i - 1; j >= -1; j--) {
            if (j == -1 or v[i] >= v[j]) { //插入排序，哨兵为j=-1
                int tmp = v[i];
                v.erase(v.begin() + i);
                v.insert(v.begin() + j + 1, tmp);
                break;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    int oddNum = 0;
    for (int i = v.size() - 1; i >= oddNum; i--) {
        if (v[i] % 2) {
            int tmp = v[i];
            v.erase(v.begin() + i);
            v.insert(v.begin(), tmp);
            oddNum++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
