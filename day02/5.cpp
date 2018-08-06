#include <cctype>
#include <iostream>

using namespace std;

char s[100] = { 0 };
int main(int argc, char const* argv[])
{
    int wordnum = 0;
    int n = 0;
    char ch;
    while ((ch = getchar()) != EOF) {
        s[n++] = ch;
    }

    bool isword = false;
    for (int i = 0; i < n; i++){
        if(isalpha(s[i])){
            if(isword == false){
                wordnum++;
            }
            isword = true;
        }
        else{
            isword = false;
        }
    }
    cout << wordnum << endl;
    
    system("pause");
    return 0;
}
