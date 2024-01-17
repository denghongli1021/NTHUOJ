#include <stdio.h>
#include <string.h>
////////////////////////////////////
typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->idx = num;
    new_node->next = (*head)->next;
    (*head)->next = new_node;

    if (new_node->next == NULL) {
        *back = new_node;
    }
}

void AddBack(Node** head, Node** back, int num) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->idx = num;
    new_node->next = NULL;

    if (*back != NULL) {
        (*back)->next = new_node;
        *back = new_node;
    } else {
        (*head)->next = new_node;
        *back = new_node;
    }
}

void DeleteFront(Node** head, Node** back) {
    if ((*head)->next != NULL) {
        Node* del = (*head)->next;
        (*head)->next = del->next;
        free(del);

        if ((*head)->next == NULL) {
            *back = *head;
        }
    }
}

void Delete(Node** head, Node** back, int num) {
    Node* current = *head;

    while (current->next != NULL && current->next->idx == num) {
        Node* del = current->next;
        current->next = del->next;
        free(del);

        if (current->next == NULL) {
            *back = current;
        }
    }
}

void Swap(Node** head, Node** back) {
    Node* prev = NULL;
    Node* current = (*head)->next;

    while (current != NULL) {
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    (*head)->next = prev;

    if (*back != NULL) {
        *back = (*head)->next;
    }
}
////////////////////////////////////
int main()
{
    char str[50];
    
    Node* head = (Node*) malloc(sizeof(Node));
    Node* back = head;
    // initialize the dummy head
    
    // we'll append the element after this dummy head to avoid runtime error.
    head->idx = -1;
    head->next = NULL;
    
    while (scanf("%s", str) != EOF) {
        
        int num;
        
        if (!strcmp(str, "AddFront")) {
            scanf("%d", &num);
            AddFront(&head, &back, num);
        }
        else if (!strcmp(str, "AddBack")) {
            scanf("%d", &num);
            AddBack(&head, &back, num);
        }
        else if (!strcmp(str, "DeleteFront")) {
            DeleteFront(&head, &back);
        }
        else if (!strcmp(str, "Delete")) {
            scanf("%d", &num);
            Delete(&head, &back, num);
        }
        else if (!strcmp(str, "Swap")) {
            Swap(&head, &back);
        }
    }
    
    // print all the element except the dummy head and free them.
    Node* print = head;
         
    if (head->next == NULL) printf("empty\n");
    
    while (print != NULL) {
        if (print->idx != -1)
            printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
        Node* del = print;
        print = print->next;
        free(del);
    }
}