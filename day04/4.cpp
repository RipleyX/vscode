#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int P = 11;
const int max_size = 20;

int main(int argc, char const* argv[])
{
    vector<int> linkHash[P];
    int dualHash[max_size];
    memset(dualHash, -1, sizeof(dualHash));
    int delta[max_size] = { 0 };
    string s;
    getline(cin, s);
    istringstream line(s);
    int key;
    vector<int> v;
    while (line >> key) {
        int ind = key % P;
        linkHash[ind].push_back(key);
        while (dualHash[ind] != -1) {
            delta[ind]++;
            ind = (ind + ind * delta[ind]) % max_size;
        }
        dualHash[ind] = key;
    }
    for (int i = 0; i < P; i++) {
        cout << i << ": ";
        for (int j = 0; j < linkHash[i].size(); j++) {
            cout << linkHash[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < max_size; i++) {
        cout << dualHash[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
