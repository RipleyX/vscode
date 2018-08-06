#include "iostream"

using namespace std;

const int MAX = 1000;

int num[MAX] = { 0 };

int main(int argc, char const* argv[])
{
    int k, n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> k;
        num[i] = k;
    }

    for (int i = 0; i < n;i++){
        int min = num[i];
        int ind = i;
        for (int j = i; j < n; j++){
            if(num[j]<min){
                min = num[j];
                ind = j;
            }
        }

        if (ind != i) {
            int tmp = num[i];
            num[i] = min;
            num[ind] = tmp;
        }

    }

    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    cin >> k;
    int i;
    for (i = 0; i < n - 1; i++) {
        if(k<num[i]){
            for (int j = n; j > i;j--) {
                num[j] = num[j - 1];
            }

            num[i] = k;
            break;
        }
    }

    if(i==n-1){
        num[n] = k;
    }

    for (int i = 0; i <= n;i++){
        cout << num[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
