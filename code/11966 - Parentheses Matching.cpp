#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
map<char,char> pai = { {'{' , '}'} ,
                        {'[' , ']'} ,
                        {'(', ')'} ,
                        {'<' , '>'}
};

/// stzck 是 FILO
/// 有以下函式
/// push
/// pop
/// top
/// size
/// empty

int main() {
    int testcase;
    cin >> testcase;
    string str;
    getline(cin , str) ;
    for (int i = 1; i<= testcase ;i++) {
        getline(cin , str);
        bool valid = true;
        stack<char> S;
        /// 如果我放在全域變數 那我就需要每次都要清空
        /// 因為可能會有遺留下來的 影響之後的測值
        for (char c : str) {
            if (c == '{' || c == '[' || c == '(' || c == '<') {
                S.push(c);
            }
            else if (c == '}' || c == ']' || c == ')' || c == '>') {
                if (S.empty()) {
                    valid = false;
                    break;
                }
                else if (pai[S.top()] != c) {
                    valid = false;
                    break;
                }
                else {
                    S.pop();
                }
            }
        }
        if (!S.empty()) {
            valid = false;
        }
        cout << "Case " << i << ": " ;
        if (valid) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}
