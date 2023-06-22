#include "function.h"

void Push (Node** ptr_head,int x) {
    Node* tr = (Node*)malloc(sizeof(Node));
    tr->next = (*ptr_head);
    tr->data = x;
    (*ptr_head) = tr;
}

void Pop(Node** ptr_head) {
    if (*ptr_head == NULL) return ;
    Node* tmp = *ptr_head;
    *ptr_head = (*ptr_head)->next;
    free(tmp);
}

void Reverse_List (Node** ptr_head) {
    Node *tmp,*scan,*new_head = NULL;
    while ((*ptr_head)!=NULL) {
        scan = *ptrhead;
        tmp = (Node*)malloc(sizeof(Node));
        tmp->data = scan->data;
        tmp->next = new_head;
        new_head = tmp;

        ptr_head = scan_next;
        free(scan);
    }
    *ptr_head = new_head;
}
