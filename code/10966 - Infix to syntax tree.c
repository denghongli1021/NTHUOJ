#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6

#include <stdio.h>
#include <stdlib.h>

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

BTNode* EXPR() {
    BTNode* right = NULL, * root = NULL;
    if (pos >= 0) {

        char c = expr[pos--];
        if (c >= 'A' && c <= 'D') right = makeNode(c);
        else if (c == ')') {
            right = EXPR();
            pos--; // skip '('
        }

        if (pos > 0) {
            c = expr[pos];
            if (c == '&' || c == '|') {
                root = makeNode(c);
                root->right = right;
                pos--;
                root->left = EXPR();
            }
            else root = right;
        }
        else root = right;
    }

    return root;
}

BTNode* makeNode(char c) {
    BTNode* new_node = (BTNode*) malloc(sizeof(BTNode));
    for (int i = 0; i < NUMSYM; i++) {
        if (c == sym[i]) new_node->data = i;
    }
    new_node->left = new_node->right = NULL;

    return new_node;
}

#endif

// By Utin
