#include <iostream>
#include <string>
#include "function.h"
/*
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
};*/
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
