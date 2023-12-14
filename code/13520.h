#ifndef FUNCTION_H
#define FUNCTION_H
/*
#ifndef FUNCTION_H
#define FUNCTION_H
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
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};
#endif
*/
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
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};

Darray::~Darray () {
    delete [] data;
}

int& Darray::operator[](int n) {
    return this->data[n];
}

void Darray::pushback(int x) {
    if ((*this).size >= (*this).capacity) {
        (*this).resize();
    }
    data[size] = x;
    size++;
}

void Darray::clear(void){
    delete [] data;
    data = new int [capacity];
    size = 0;
}

int Darray::length(void) {
    return size;
}

void Darray::resize(void) {
    capacity *= 2;
    int * tmp = new int [capacity];

    for (int i = 0 ; i < size ;i ++) {
        tmp[i] = data[i];
    }
    delete [] data;
    data = tmp;
}

/*
#include <iostream>
#include "function.h"

Darray::~Darray() {
    delete[] data;
}

int& Darray::operator[](int idx) {
    return data[idx];
}

void Darray::pushback(int x) {
    if (size >= capacity) resize();
    data[size] = x;
    size++;
}

void Darray::clear(void) {
    delete[] data;
    data = new int[capacity];
    size = 0;
}

int Darray::length(void) {
    return size;
}

void Darray::resize(void) {
    capacity *= 2;
    int* tmp = new int[capacity];
    // copy data
    for (int i = 0; i < size; i++)
        tmp[i] = data[i];
    // free memory
    delete[] data;
    data = tmp;
}

// Utin
*/
#endif
