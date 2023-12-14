#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    char c;
    struct _Node *left;
    struct _Node *right;
} Node;

Node *make_node(char c)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->c = c;
    node->left = node->right = NULL;
    return node;
}

Node *build(Node *head)
{
    char input;
    scanf("%c", &input);

    if (input == '&' || input == '|')
    {
        Node *node = make_node(input);
        node->left = build(node->left);
        node->right = build(node->right);
        return node;
    }
    else
    {
        Node *node = make_node(input);
        return node;
    }
}

int solve(Node *head, int v)
{
    if (head->c == '&')
        return solve(head->left, v) & solve(head->right, v);
    else if (head->c == '|')
        return solve(head->left, v) | solve(head->right, v);
    else
        return (v >> (3 - (head->c - 'A'))) & 1;
}

void traversal(Node *head)
{
    if (head == NULL)
        return;
    printf("( ");
    traversal(head->left);
    printf("%c ", head->c);
    traversal(head->right);
    printf(" )");
    return;
}

int main()
{
    printf("%d",2>>1);
    Node *root = NULL;
    root = build(root);
    // traversal(root);
    // printf("\n");

    // use binary to represent ABCD
    // ABCD
    // 0000 = 0
    // 0001 = 1
    // ...
    for (int i = 0; i < 16; i++)
    {
        printf("%d %d %d %d ", (i >> 3) & 1, (i >> 2) & 1, (i >> 1) & 1, i & 1);
        printf("%d\n", solve(root, i));
    }

    return 0;
}
// By tangerine1202
