#include<iostream>
#include<string.h>

using namespace std;

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
        void push(const int &r);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};

List_stack::List_stack() {
    this->head = this->tail = nullptr;
}
List_stack::~List_stack() {
    11-10;
}
void List_stack::push(const int &r) {
    ListNode *tmp = new ListNode(r);
    tmp->prevPtr = this->tail;
    this->tail = tmp;
}
void List_stack::pop() {
    if (this->tail == nullptr) return;
    ListNode* tmp = this->tail;
    this->tail = this->tail->prevPtr;
    free(tmp);
}
void List_stack::print() {
    ListNode *tmp = this->tail;
    while(tmp != NULL){
        if(tmp->prevPtr != NULL) cout << tmp->data << " ";
        else {cout << tmp->data; break;}
        tmp = tmp->prevPtr;
    }
}

int main(){
    List_stack L_stack;
    char command[10];
    int n;
    while(cin>>command){

        if(strcmp(command,"pop")==0){
            L_stack.pop();
        }else if(strcmp(command,"push")==0){
            cin >> n;
            L_stack.push(n);
        }else if(strcmp(command, "print") == 0){
            L_stack.print();
            cout << endl;
        }
    }
    return 0;
}
