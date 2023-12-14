#include<iostream>
#include <string>

using namespace std;

char table[36] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

class String_Calculator {
    public:
        String_Calculator(){};
        String_Calculator(const string);
        String_Calculator& Add(const string);
        String_Calculator& Subtract(const string);
        String_Calculator& Shift(const string);
        void output() const;
    private:
        string s = "";
};

String_Calculator::String_Calculator( const string x) : s(x){}

String_Calculator& String_Calculator::Add(const string add) {
    s += add;
    return *this;
}

String_Calculator& String_Calculator::Subtract(const string sub) {
    size_t pos = s.find(sub, 0);
    //printf("size_t = %d\n",pos);
    if (pos == string::npos) {
        s = "error";
        return *this;
    }
    size_t len = sub.size();
    s.erase(pos, len);
    return *this;
}

String_Calculator& String_Calculator::Shift(const string shi) {
    size_t s_len = s.size();
    size_t shi_len = shi.size();

    int correct = 1;
    for (size_t i = 0 ; i< shi_len ; i ++) {
        if (shi[i] < '0' || shi[i] > '9') {
            correct = 0;
            break;
        }
    }
    if ( !correct ) {
        //printf("Hello\n");
        s = "error" ;
        return *this;
    }
    int shiftTime = stoi(shi);
    shiftTime %= 36 ;
    //printf("shift : %d\n",shiftTime);

    for (int i = 0 ; i <= s_len-1 ; i++) {
        int j = 0;
        for (j; j <= 35 ; j++) {
            if (s[i] == table[j]) {
                //printf("%d %d %c",i,j,table[j]);
                break;
            }
        }
        //printf("%d %d\n",i,j);
        if ( (j + shiftTime) > 35) {
            s[i] = table[shiftTime - (35 - j) - 1] ;
        }
        else {
            s[i] = table[j + shiftTime] ;
        }
        //printf("%c %d\n",s[i],s[i]);
    }


    return *this;
}


void String_Calculator::output() const {
    cout << s << '\n';
}
/*
9
98 35 @
ab 35 @
0123456789abcdefghijklmnopqrstuvwxyz 1 @
*/

int main(){
    int n;
    string x, y, c;
    cin >> n;
    for (int i = 0 ; i <= 35 ;i ++) {
        printf("%c",table[i]);
    }
    printf("\n");
    while(n--){
        cin >> x >> y >> c;
        String_Calculator a(x), ans;
        if(c == "+")
            ans = a.Add(y);
        if(c == "-")
            ans = a.Subtract(y);
        if(c == "@")
            ans = a.Shift(y);
        ans.output();
    }
}
