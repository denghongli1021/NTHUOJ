#include <bits/stdc++.h>
#include "function.h"

void _stack::push(const _node N) {
    _node* new_node = new _node(N.data);
    this->End->prev->next = new_node;
    new_node->prev = this->End->prev;
    new_node->next = this->End;
    this->End->prev = new_node;
}

void _stack::pop() {
    if (this->Begin->next == this->End) {
        return ;
    }
    _node* trash = this->End->prev;
    this->End->prev->prev->next = this->End;
    this->End->prev = this->End->prev->prev;
    delete trash;
    // 不用delete 也可以過
}

_node* _stack::get_data() {
    if (this->Begin->next == this->End) {
        return NULL;
    }
    return this->End->prev;
    // 回傳最後一個元素
}

void _queue::push(const _node N) {
    //將圖片中的 tail 當作 head
    _node* new_node = new _node(N.data);
    new_node->prev = this->Begin;
    new_node->next = this->Begin->next;
    this->Begin->next->prev = new_node;
    this->Begin->next = new_node;
}

void _queue::pop() {
    if (this->Begin->next == this->End) {
        return ;
    }
    _node* trash = this->End->prev;
    this->End->prev->prev->next = this->End;
    this->End->prev = this->End->prev->prev;
    delete trash;
}

_node* _queue::get_data() {
    if (this->Begin->next == this->End) {
        return NULL;
    }
    return this->End->prev;
    // 回傳最後一個元素
}

/*
#include <cstddef>

class _node{
    public:
        int data;
        _node* next,*prev;
        _node(int d=0){data = d; next=prev=NULL;}

};
class _dequeue{
    protected:
        _node* Begin,*End;

    public:
        _dequeue(){
            Begin = new _node(0);
            End = new _node(0);
            Begin->next=End;
            End->prev=Begin;
        }
        bool Empty(){
            if(Begin==NULL || Begin->next==End) return true;
            return false;
        }
        virtual void push(const _node) = 0;
        virtual void pop() = 0;
        virtual _node* get_data() = 0;
};

class _stack : public _dequeue{
    public:
        _stack():_dequeue(){}
        void push(const _node N);
        void pop();
        _node* get_data();

};
class _queue : public _dequeue{
    public:
        _queue():_dequeue(){}
        void push(const _node N);
        void pop();
        _node* get_data();

};
*/

// Utin
