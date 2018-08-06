#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    vector<vector<int>> adjlist; //采用邻接表存储图
    int indgree[1000] = { 0 };
    stack<int> headvertex;
    string s;
    while (getline(cin, s)) {
        istringstream line(s);
        int n;
        vector<int> v;
        while (line >> n) {
            v.push_back(n);
            indgree[n - 1]++; //邻接表创建过程中记录各点的入度
        }
        adjlist.push_back(v);
    }

    for (int i = 0; i < adjlist.size(); i++) {
        if (indgree[i] == 0) {
            headvertex.push(i + 1); //入度为0的点进栈
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
        for (int i = 0; i < adjlist[n - 1].size(); i++) { //反复出栈查邻接表更新入度信息
            int x = adjlist[n - 1][i];
            indgree[x - 1]--;
            if (indgree[x - 1] == 0) {
                headvertex.push(x); //度为0的点继续入栈
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
