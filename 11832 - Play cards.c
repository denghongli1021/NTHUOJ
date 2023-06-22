#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
}Node;

int main() {
    int t,n;
    scanf("%d %d",&t,&n);
    Node* head = (Node*)malloc(sizeof(Node));
    int temp;
    scanf(" %d",&temp);
    head->data = temp;
    Node* tail = head;

    for (int i = 1;i<=t-1;i++) {
        Node* now = (Node*)malloc(sizeof(Node));
        tail->next = now;
        scanf(" %d",&temp);
        now->data = temp;
        now->next = NULL;
        tail = now;
        if (i == 1) {
            head->next = tail;
        }
    }

    /*while (head != NULL) {
        printf("%d\n",head->data);
        head = head->next;
    }*/
    char str[100];
    int idx,idy;
    for (int i =1 ;i<= 2;i++) {
        scanf("%s",str);
        scanf(" %d %d",&idx,&idy);
        if (str[0] == 'A') {
            Node* tmp = (Node*)malloc(sizeof(Node));
            if (idx == 0) {
                tmp->data = idy;
                tmp->next = head;
                head = tmp;
                continue;
            }
            int id = 0;
            Node* head2 = head;
            Node* head3 = head;
            while (id < idx ) {
                head3 = head2;
                head2 = head2->next;
                id++;
            }
            tmp->data = idy;
            tmp->next = head2;
            head3->next = tmp;
            t++;
        }
        else if (str[0] == 'C') {
            if (idx == 0) continue;
            int time = 1;
            Node* head2 = head;
            while (time < idx) {
                head2 = head2->next;
                time++;
            }

            Node* tmp = head2;
            head2 = head2->next;

            Node* now = head2;
            while (time < (idx+idy)-1 ) {
                now = now->next;
                time++;
            }
            //printf("%d\n",(now->data));
            tmp->next = now->next;
            now->next = head;
            head = head2;
            //printf("Hello\n");
        }
    }
    while (head != NULL) {
        printf("%d\n",head->data);

        Node* tmp = head;
        head = head->next;
        free(tmp);
    }

}

/*3 2
1 2 3
ADD 0 4
CUT 2 2*/
