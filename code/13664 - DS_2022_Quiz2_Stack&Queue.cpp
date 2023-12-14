#include <iostream>

using namespace std;
int a[2000005];

int main() {

    int tmp = 0;
    int i = 0;

    while(cin >> tmp) {
        a[i] = tmp;
        i++;
    }
    i = i-1;
    for (int j = 0 ; j<=i;j++) {
        int k = j;
        while (a[k] <= a[j]) {
            if (k==0) {
                k = i;
            }
            else {
                k = k-1;
            }
            if (k == j) {
                break;
            }
        }
        if (k < j) {
            cout << k - j;
        }
        else {
            cout << k - j;
        }
        cout << " ";
        if (j == i) {
            cout << "\n";
        }
    }
//    for (auto c : a) {
//        cout << c << " ";
//        if (c == 0) {
//            break;
//        }
//    }
}
