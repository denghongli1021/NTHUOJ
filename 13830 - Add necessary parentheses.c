#include <stdio.h>
#include <stdlib.h>

#define checkPM(c) ((c == '+' || c == '-') ? 1 : 0)
#define checkTD(c) ((c == '*' || c == '/') ? 1 : 0)
#define checkMT(c) ((c == '-' || c == '*') ? 1 : 0)
#define checkOP(c) ((c == '+' || c == '-' || c == '*' || c == '/') ? 1 : 0)

typedef struct _node {
	char c;
	struct _node* left, * right;
} Node;

Node* Root;

Node* create_tree();
Node* make_node(char c);
void print_tree(Node* root);
void destroy_tree(Node* root);

int main() {
    Root = create_tree();
    print_tree(Root);
    printf("\n");
    destroy_tree(Root);
}

Node* make_node(char c) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->c = c;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* create_tree() {
    Node* new_node = NULL;
    char c;
    if (~scanf("%c", &c)) {
        new_node = make_node(c);
        if (checkOP(c)) {
            new_node->left = create_tree();
            new_node->right = create_tree();
        }
    }
    return new_node;
}

void print_tree(Node* root) {
    if (root->left) {
        // (A op B) op ROOT
        if (checkTD(root->c) && checkPM(root->left->c)) printf("(");
        print_tree(root->left);
        if (checkTD(root->c) && checkPM(root->left->c)) printf(")");
    }

    printf("%c", root->c);

    if (root->right) {
        // ROOT op (A op B)
        if (root->c == '/' && checkOP(root->right->c)) printf("(");
        if (checkMT(root->c) && checkPM(root->right->c)) printf("(");
        print_tree(root->right);
        if (root->c == '/' && checkOP(root->right->c)) printf(")");
        if (checkMT(root->c) && checkPM(root->right->c)) printf(")");
    }
}

void destroy_tree(Node* root) {
    if (root->left) destroy_tree(root->left);
    if (root->right) destroy_tree(root->right);
    free(root);
}

// Utin
