/*
#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
class Darray {
    public:
        Darray() {
            capacity = 100;
            size = 0;
            data = new int[capacity];
        };
        ~Darray();
        int& operator[](int);
        void pushback(int x);
        void popback(void);
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};

class INT {
    public:
        void operator+=(INT&);
        friend std::istream &operator>>(std::istream &, INT &);
        friend std::ostream &operator<<(std::ostream &, INT &);
    private:
        Darray data;
};
#endif
*/
#include <iostream>
#include <string>

#include "function.h"

using namespace std;

void INT::operator+=(INT& tmp) {
    int size1 = tmp.data.length;

    for (int i = 0 ; i < size1 ;i++) {
        int temp1 = data[i];
        data[i] += tmp.data.data[i];
        if (data[i] >= 10) {
            if (data.size == data.capacity) {
                data.resize();
            }
            data[i+1] += 1;
            data[i] %= 10;
        }
    }
}
friend istream& INT::operator>>(std::istream &input, INT &tmp) {

    return input;
}
friend ostream& INT::operator<<(std::ostream &output, INT &tmp) {

    return output;
}

Darray::~Darray() {
    delete [] data;
}
int& Darray::operator[](int a) {
    return data[a];
}
void Darray::pushback(int x) {
    if (size == capacity) {
        resize();
    }
    data[size] = x;
    size++;
}
void Darray::popback(void) {
    if (size == 0) {
        return;
    }
    data[size-1] = 0;
    size--;
}
void Darray::clear(void) {
    delete [] data;
    int* tmp = new int[capacity];
    size = 0;
    data = tmp;
}
int Darray::length(void) {
    return size;
}
void Darray::resize(void) {
    capacity *= 2;
    int* tmp = new int[capacity];
    for (int i = 0 ; i< capacity/2 ;i++) {
        tmp[i] = data[i];
    }
    delete [] data;
    data = tmp;

}

