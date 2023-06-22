#include<iostream>
//#include"function.h"
using namespace std;
#include <string>

class String_Calculator {
    public:
        String_Calculator(){}; //default constructor(no parameter)
        String_Calculator(const string); //都是 constructor // 沒有回傳值
        String_Calculator& Add(const string);
        String_Calculator& Subtract(const string);
        String_Calculator& DividedBy(const string);
        void output() const;

    private:
        string s = "";
}; //end class String_Calculator

String_Calculator::String_Calculator( const string x) : s(x){}

String_Calculator& String_Calculator::Add(const string add) {
    s += add;
    return *this;
}

String_Calculator& String_Calculator::Subtract(const string sub) {
    size_t pos = s.find(sub, 0);
    printf("size_t = %d\n",pos);
    if (pos == string::npos) {
        s = "error";
        return *this;
    }
    size_t len = sub.size();
    s.erase(pos, len);
    return *this;
}

String_Calculator& String_Calculator::DividedBy(const string div) {
    int count = 0;
    size_t s_len = s.size();
    size_t div_len = div.size();
    size_t len = s_len - div_len + 1;
    for (size_t i = 0; i < len; i++) {
        int flag = 0;
        for (size_t j = 0; j < div_len && !flag; j++) {
            if (s[i + j] != div[j]) flag = 1;
        }
        if (!flag) count++;
    }
    s = to_string(count);
    return *this;
}

void String_Calculator::output() const {
    cout << s << '\n';
}

int main(){
    int n;
    string x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        String_Calculator a(x), ans;
        ans = a.Subtract(y).Add(y).DividedBy(y);
        ans.output();
    }
}


