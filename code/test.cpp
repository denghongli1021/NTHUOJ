#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<char,char> mapping = {
  {'{','}'} ,
  {'[' ,']' } ,
  {'(' ,')' } ,
  {'<' ,'>' }
};

int main() {
    int testcase;
    cin >> testcase;
    string input;
    getline(cin,input);
    for (int i = 1 ; i<= testcase ;i++) {
        getline(cin,input);
        stack<char> s;
        bool valid = true;
        for (char c : input) {
            if (c == '{' || c == '(' || c == '[' || c == '<') {
                s.push(c);
                continue;
            }
            else if (c == '}' || c == ')' || c == ']' || c == '>') {
                if (s.empty()) {
                    valid = false;
                    //cout << "1\n";
                    break;
                }
                if (c != mapping[s.top()]) {
                    valid = false;
                    //cout << "2\n";
                    break;
                }
                else {
                    s.pop();
                }
            }
        }
        if (!s.empty()) {
            valid = false;
            //cout << "3\n";
        }
        cout << "Case " << i << ": ";
        if (valid) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}
