#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "function.h"

/*
#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

class ListNode
{
    friend class List_stack; //make List_stack a friend
    public:
        ListNode( const int &info ) //constructor
        : data( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor

    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};
#endif // FUNCTION_H
*/
using namespace std;

List_stack::List_stack() {
    this->head = this->tail = NULL;
}
List_stack::~List_stack() {
    ListNode* tmp = head;
    while (tmp) {
        ListNode* trash = tmp;
        tmp = tmp->nextPtr;
        delete trash;
    }
}
void List_stack::push(const int &r) {
    ListNode *tmp = new ListNode(r);
    tmp->prevPtr = this->tail;
    //this->tail->nextPtr = tmp;
    // ¥[¤F´Nruntimeerror
    this->tail = tmp;
}
void List_stack::pop() {
    if (this->tail == NULL) return;
    ListNode* tmp = this->tail;
    this->tail = this->tail->prevPtr;
    free(tmp);
}
void List_stack::print() {
    ListNode *tmp = this->tail;
    if (!tmp) return;
    cout << tmp->data;
    tmp = tmp->prevPtr;
    while(tmp != NULL){
        cout << " " << tmp->data;
        tmp = tmp->prevPtr;
    }
}
