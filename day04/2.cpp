#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    vector<vector<int>> adjlist;
    int indgree[1000] = { 0 };
    stack<int> headvertex;
    string s;
    while (getline(cin, s)) {
        istringstream line(s);
        int n;
        vector<int> v;
        while (line >> n) {
            v.push_back(n);
            indgree[n - 1]++;
        }
        adjlist.push_back(v);
    }

    for (int i = 0; i < adjlist.size(); i++) {
        if (indgree[i] == 0) {
            headvertex.push(i + 1);
        }
    }

    if (headvertex.empty()) {
        cout << "Not DAG!" << endl;
        system("pause");
        return -1;
    }

    vector<int> toplist;
    do {
        int n = headvertex.top();
        toplist.push_back(n);
        headvertex.pop();
        for (int i = 0; i < adjlist[n - 1].size(); i++) {
            int x = adjlist[n - 1][i];
            indgree[x - 1]--;
            if (indgree[x - 1] == 0) {
                headvertex.push(x);
            }
        }
    } while (!headvertex.empty());

    for (int i = 0; i < toplist.size(); i++) {
        cout << toplist[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
