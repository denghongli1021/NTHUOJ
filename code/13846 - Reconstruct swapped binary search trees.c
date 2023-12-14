#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    long long value;
    struct _node* left, * right;
}Node;

Node* head = NULL;

Node* make_node(long long value);
void add_node(long long value, Node* ptr);
void print_tree_post(Node* ptr, int tail);

int main(){
    long long n,input;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf(" %lld",&input);
        add_node(input, head);
    }
    print_tree_post(head, 1);
}

Node* make_node(long long value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void add_node(long long value, Node* ptr){
    if(!head) head = make_node(value);
    else {
        if(value <= ptr->value){
            if(ptr->left) add_node(value, ptr->left);
            else ptr->left = make_node(value);
        }
        else{
            if(ptr->right) add_node(value, ptr->right);
            else ptr->right = make_node(value);
        }
    }
}

void print_tree_post(Node* ptr, int tail){
    if(ptr->left) print_tree_post(ptr->left,0);
    if(ptr->right) print_tree_post(ptr->right,0);
    printf("%lld", ptr->value);
    tail ? printf("\n") : printf(" ");
}
