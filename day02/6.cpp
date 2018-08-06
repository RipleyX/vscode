#include "iostream"

using namespace std;

char s[10000] = { '\0' };
const char t[] = "debug";

int main(int argc, char const* argv[])
{
    bool flag = false;
    int n = 0;
    char ch;
    while ((ch = getchar()) != EOF) {
        s[n++] = ch;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[j]) { //暴力匹配
            j++;
            if (j == 5) {
                flag = true;
                break;
            }
        } else {
            j = 0;
        }
    }

    if (flag) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

    system("pause");
    return 0;
}
