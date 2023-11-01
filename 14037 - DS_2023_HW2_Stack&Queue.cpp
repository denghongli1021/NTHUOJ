#include <iostream>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    string str;
    string ans;
    for (int i = 1; i <= testcase ; i++) {
        cin >> str;
        str = "a" + str;
        int left = 0;
        int right = 0;
        int len = 0;
        int a = 0;
        for (auto c:str) {
            if (c == '(') {
                left = left+1;
            }
            else if (c == ')') {
                right = right + 1;
            }
            if (right > left) {
                a = left;
                len = max(len,a);
                right = left = 0;
            }
            else if (right == left) {
                len = max(len,left);
            }
            //cout << " right " << right << " left " << left << " len " << len<<'\n';
        }
        if (left > right) {
            int left2 = 0;
            int right2 = 0;
            int len2 = 0;
            for (int j = str.size()-1 ; j >= str.size()-(left+right) ; j--) {
                if (str[j] == ')') {
                    right2 ++ ;
                }
                else if (str[j] == '(') {
                    left2 ++ ;
                }
                if (left2 > right2) {
                    a = right2;
                    len = max(len,a);
                    right2 = left2 = 0;
                }
                else if (right2 == left2) {
                    len = max(len,right2);
                }
            }
        }
//        a = right;
//        len = max(len,a);
        len = len % 26;
        char b = 'a' + len;
        //cout << b;
        ans = ans + b;
    }
    cout << ans << '\n';
}
