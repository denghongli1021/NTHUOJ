#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct _Node{
    int number, age;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* age_list[500005];
Node* head;

int cmp (const void * a, const void * b) {
    Node* A = *(Node**)a;
    Node* B = *(Node**)b;

    if (A->age != B->age) return A->age - B ->age;
    else {
        return A->number-B->number;
    }
}

Node* createList(int n) {
    Node* list = (Node*)malloc(sizeof(Node)*n);
    for (int i = 0 ;i< n ;i ++) {
        list[i].number = i + 1;
        scanf(" %d",&list[i].age);
        age_list[i] = &list[i];

        if (i != n-1) {
            list[i].next = &list[i+1];
        }
        else {
            list[i].next = &list[0];
        }
        if ( i != 0) {
            list[i].prev = &list[i-1];
        }
        else {
            list[i].prev = &list[n-1];
        }

    }
    qsort(age_list,n,sizeof(Node*),cmp);
    return list;

}
Node* solve(int n, int m) {
    int a,b;
    char input;
    while (m--) {
        scanf(" %d %d %c",&a,&b,&input);
        a--;
        b %= (n-1);
        if (b== 0 ) {
            continue;
        }
        Node* tmp = age_list[a];
        Node* next = age_list[a]->next;
        Node* prev = age_list[a]->prev;

        next->prev = prev;
        prev->next = next;

        if (input == 'R') {
            while (b--) {
                prev = prev->next;
                next = next->next;
            }
        }
        else if (input == 'L') {
            while (b--) {
                prev = prev->prev;
                next = next->prev;
            }
        }

        prev->next = tmp;
        tmp->next = next;
        next->prev = tmp;
        tmp->prev = prev;


    }
    return age_list[0];
}

#endif
