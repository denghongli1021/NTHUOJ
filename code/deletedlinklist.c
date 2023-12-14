#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void deleteNode(Node ** nd,int data) {
    Node* tr = (Node*)malloc(sizeof(Node));
    int i = 1;
    tr->next = (*nd);
    for (int i = 1;i< data;i++) {
        tr-> next = tr->next->next
    }

    tr->next = (*nd);
    tr->data = data;
    (*nd) = tr;
}

Node* createList () {

}
