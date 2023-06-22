#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum node_type {
    op_and , op_or , op_id
} Nodetype;


typedef struct Node {
    int id;
    Nodetype type;
    bool b_val;
    struct Node* L;
    struct Node* R;
    struct Node* P; //parent
}Node;

Node* variable[100001]; // This array stores the pointers pointing to the tree nodes. For example, variable[0] points to the node with ID number 0.

Node* makeNode(Nodetype type,int id,Node* p) {
    Node* n = malloc(sizeof(Node));
    n->id = id;
    n->type = type;
    n->b_val = false;
    n->L = NULL;
    n->R = NULL;
    n->P = p;

    return n;
}

void constructSyntax(Node** root,Node* p) {
    char c = getchar();

    switch (c) {
        case '\n' : return;
        case '&'  : {
            (*root) = makeNode(op_and,-1,p);
            constructSyntax(&(*root)->L , (*root));
            constructSyntax(&(*root)->R , (*root));
            break;
        }
        case '|' : {
            (*root) = makeNode(op_or,-1,p);
            constructSyntax(&(*root)->L , (*root));
            constructSyntax(&(*root)->R , (*root));
            break;
        }
        case '[' : {
            int id;
            scanf("%d]",&id);
            (*root) = makeNode(op_id,id,p);
            variable[(*root)->id]  = (*root);
            break;
        }
        default :
            break;
    }
    return;
}

int find_b_value (Node* leaf) {
    Node* p = leaf->P;
    if (p== NULL) return leaf->b_val;

    if (p->type == op_and) {
        p->b_val = (p->L->b_val & p->R->b_val) ;
    }
    else if (p->type == op_or) {
        p->b_val = (p->L->b_val | p->R->b_val);
    }

    return find_b_value (p);
}

void free_tree (Node* root) {
    if (root != NULL) {
        free_tree(root->L);
        free_tree(root->R);
        free(root); //這是 free 不是 free_tree;
    }
}

int main() {
    int t,flip_time,val_cnt;
    scanf("%d",&t);

    while (t--) {
        scanf(" %d %d",&val_cnt,&flip_time);
        getchar();
        Node* root = NULL;
        constructSyntax(&root,NULL);

        while (flip_time --) {
            int id;
            scanf("%d",&id);

            variable[id]->b_val = !variable[id]->b_val;
            printf("%d\n",find_b_value(variable[id]));
        }

        for (int i = 0 ; i <= val_cnt-1 ; i++) {
            variable[i] = NULL;
        }
        free_tree(root);
    }
    return 0;
}

