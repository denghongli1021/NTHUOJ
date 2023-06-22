#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/*
typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;
*/

Node* ReadOneList() {
    Node* dummy_head = (Node*)malloc(sizeof(Node));
    scanf("%d: ", &(dummy_head->size));
    dummy_head->data = (int*)malloc(dummy_head->size * sizeof(int));
    for(int i=0; i<(dummy_head->size); i++) {
        int x;
        scanf(" %d", &x);
        //getchar();
        *((dummy_head->data)+i) = x;
    }
    dummy_head->next = NULL;
    return dummy_head;
}

void PrintList(Node* dummy_head) {
    dummy_head = dummy_head->next;
    while(dummy_head != NULL) {
        printf("%d", *(dummy_head->data));
        for(int i=1; i<(dummy_head->size); i++)
            printf(" %d", *((dummy_head->data)+i));
        printf("\n");

        dummy_head = dummy_head->next;
    }
}

void Merge(Node* dummy_head, int x, int y) {
    if(x == y) return;
    //先定位temp_x 和 temp_y
    Node* prev_x = dummy_head;
    Node* temp_x = prev_x->next;
    Node* prev_y = dummy_head;
    Node* temp_y = prev_y->next;
    x--;
    while(x--) {
        prev_x = prev_x->next;
        temp_x = temp_x->next;
        if(temp_x == NULL) return;
    }
    y--;
    while(y--) {
        prev_y = prev_y->next;
        temp_y = temp_y->next;
        if(temp_y == NULL) return;
    }
    //定義一個新的
    Node* new_head = (Node*)malloc(sizeof(Node));
    new_head->size = temp_x->size + temp_y->size;
    new_head->data = (int*)malloc((new_head->size) * sizeof(int));
    int i;
    for(i=0; i<temp_y->size; i++)
        *((new_head->data)+i) = *((temp_y->data)+i);
    for(int j=0; j<temp_x->size; j++)
        *((new_head->data)+i+j) = *((temp_x->data)+j);

    if(temp_y == prev_x) {
        prev_y->next = new_head;
        new_head->next = temp_x->next;
    }
    else if(temp_x == prev_y) {
        prev_x->next = new_head;
        new_head->next = temp_y->next;
    }
    else {
        prev_y->next = new_head;
        new_head->next = temp_y->next;
        prev_x->next = temp_x->next;
    }
    free(temp_x->data);
    free(temp_x);
    free(temp_y->data);
    free(temp_y);
}

void Cut(Node* dummy_head, int x, int y) {
    Node* prev = dummy_head;
    Node* temp = dummy_head->next;
    x--;
    while(x--) {
        prev = prev->next;
        temp = temp->next;
    }
    if(temp->size < 2) return;
    int size_1 = y;
    int size_2 = temp->size - y;
    Node* new_head_1 = (Node*)malloc(sizeof(Node));
    Node* new_head_2 = (Node*)malloc(sizeof(Node));
    new_head_1->size = size_1;
    new_head_2->size = size_2;
    new_head_1->data = (int*)malloc(new_head_1->size * sizeof(int));
    new_head_2->data = (int*)malloc(new_head_2->size * sizeof(int));

    int i;
    for(i=0; i<new_head_1->size; i++)
        *(new_head_1->data+i) = *(temp->data+i);

    for(int j=0; j<new_head_2->size; j++)
        *(new_head_2->data+j) = *(temp->data+i+j);

    prev->next = new_head_1;
    new_head_1->next = new_head_2;
    new_head_2->next = temp->next;
    free(temp->data);
    free(temp);
}

