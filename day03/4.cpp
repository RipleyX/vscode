#include "iostream"
#include "vector"
using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> v;
    int n, m;
    cin >> n;
    cin >> m;
    v.push_back(n);
    for (int i = 1; i < n; i++) {
        v.push_back(i);
    }
    int k = 1;
    while (v.size()) {
        k = (k + m - 1) % v.size(); //采用vector容器，依次提取
        cout << v[k] << " ";
        v.erase(v.begin() + k);
    }
    cout << endl;

    system("pause");
    return 0;
}
