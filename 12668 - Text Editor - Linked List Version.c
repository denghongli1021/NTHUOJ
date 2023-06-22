#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char data;
    struct _Node * next;
    struct _Node * pre;
}Node;

void back(Node ** nodeptr) {
    Node* curNode = (*nodeptr);

    if (curNode->next == NULL) {
        (*nodeptr) = curNode->pre;
        (*nodeptr)->next = NULL;
        free(curNode);
    }
    else {
        curNode->pre->next = curNode->next;
        curNode->next->pre = curNode->pre;
        (*nodeptr) = curNode->pre;
        free(curNode);
    }
}

void insert ( Node** nodeptr,char input) {
    Node* curNode = (*nodeptr);
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = input;
    newNode->pre = curNode;
    newNode->next = curNode->next;

    if (curNode->next != NULL) {
        curNode->next->pre = newNode;
    }
    curNode->next = newNode;
    (*nodeptr) = newNode;
}

void print(Node* head) {
    Node* curNode = head->next;
    while (curNode != NULL) {
        printf("%c",curNode->data);
        Node* tmp = curNode;
        curNode = curNode->next;
        free(tmp);
    }
    free(head);
    printf("\n");
}

int main() {
    int t,len;
    scanf("%d",&t);
    while (t--) {
        Node* head = (Node*)malloc(sizeof(Node));
        head->pre = NULL;
        head->next = NULL;

        Node* curNode = head;

        int N;
        scanf("%d\n",&N);
        char input;
        while (N--) {
            scanf(" %c",&input);
            if (input == 'L') {
                curNode = curNode->pre;
            }
            else if (input == 'R') {
                curNode = curNode->next;
            }
            else if (input == 'B') {
                back(&curNode);
            }
            else {
                insert(&curNode,input);
            }
        }
        print(head);
    }
    return 0;
}
