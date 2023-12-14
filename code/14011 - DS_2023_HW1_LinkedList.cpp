#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char value) : data(value), next(nullptr) ,prev(nullptr) {}
};

class List {
private:
    Node* head; // Head of the linked list
    Node* cursor; // Cursor node

public:
    List() : head(new Node(1)){
        cursor = head;
    }

    void Type(const string& str) {
        for (char ch : str) {
            Node* newNode = new Node(ch);

//            if (head == nullptr) {
//                head = newNode;
//                cursor = newNode;
//            } else
            if(cursor->next == nullptr){
                newNode->next = cursor->next;
                newNode->prev = cursor;
//                cursor->next->prev = newNode;
                cursor->next = newNode;
                cursor = newNode;
            }
            else {
                newNode->next = cursor->next;
                newNode->prev = cursor;
                cursor->next->prev = newNode;
                cursor->next = newNode;
                cursor = newNode;
            }
        }
    }
    void Move(int n) {
        if (n > 0) {
            while (n > 0 && cursor->next != nullptr) {
                cursor = cursor->next;
                n--;
            }
        } else {
            while (n < 0 && cursor != head) {
                cursor = cursor->prev;
                n++;
            }
        }
    }
    void Backspace() {
        if (cursor != head) {
            Node* t = cursor;

            if(cursor->next != nullptr){
                cursor->next->prev = cursor->prev;
            }
            cursor->prev->next = cursor->next;
//            cursor->next->prev = cursor->prev;
            cursor = cursor->prev;
            delete t;
        }
//        else {
//            head = nullptr;
//            //cursor = nullptr;
//        }
    }
    void Print() {
        Node* current = head->next;
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
//private:
//    // Helper function to find the previous node
//    Node* findPrevious(Node* target) {
//        Node* current = head;
//        while (current->next != target) {
//            current = current->next;
//        }
//        return current;
//    }
};

int main() {
    List ll;
    string input,temp;
    int len;
    int num;
    //char c;
    while (cin >> input) {
        if (input == "Type") {
            cin >> temp;
            ll.Type(temp);
        }
        else if (input == "Print") {
            ll.Print();
        }
        else if (input == "Move") {
            cin >> num;
            ll.Move(num);
        }
        else if (input == "Backspace") {
            ll.Backspace();
        }
    }
}
