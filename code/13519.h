/*
#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

#define maxsize 10000
class INT {
    public:
        INT();
        void mulby10();
        INT operator=(INT);
        INT operator+(INT);
        INT operator*(INT);
        friend std::istream &operator>>(std::istream &, INT &);
        friend std::ostream &operator<<(std::ostream &, INT);
    private:
        char data[maxsize + 1];
        int len;
};

#endif
*/

#include <iostream>
#include "function.h"
using namespace std;

INT INT::operator*(INT n) {
    INT ans;
    int max_len = n.len + this->len;
    int out[max_len];
    for (int i = 0 ;i < this->len ;i ++) {
        for (int j= 0;j < n.len ; j++) {
            out[i+j] += this->data[i] * n.data[j];
        }
    }
    for (int i = 0 ;i < max_len ; i++) {
        if (out[i] > 9) {
            out[i+1] += out[i]/10 ;
            out[i] %= 10;
        }
    }
    for (int i = max_len-1 ; !out[i] ;i--) {
        max_len--;
    }
    ans.len = max_len;
    for (int i = 0 ;i< max_len ;i++) {
        ans.data[i] = out[i];
    }
    return ans;
}

// Utin
