#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node** head, int data){
	if(data == 1){
		*head = (*head)->next;
		return;
	}
	Node *pre = NULL, *now = *head;
	data--;
	while(now != NULL && data--){
		pre = now;
		now = now->next;
	}
	if(now)pre->next = now->next;
	free(now);
}


Node* createList(){
	int val;
	Node *head, *tail, *tmp;
	scanf("%d", &val);
	tmp = (Node *) malloc(sizeof(Node));
	tmp->data = val;
	tmp->next = NULL;
	head = tail = tmp;
	while(scanf("%d", &val) && val != -1){
		tmp = (Node *) malloc(sizeof(Node));
		tmp->data = val;
		tmp->next= NULL;
		tail->next = tmp;
		tail = tmp;
	}
	return head;
}
