#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int value;
    struct _node* left, * right;
} Node;

int len, T, preorder[200001], inorder[200001], postorder[200001], pos;

Node* head;

Node* create_node(int value);
int verify(Node* root);
void destroy(Node* root);
Node* build(int in_idx, int inorder_start, int inorder_end);

int main() {
    scanf("%d", &len);
    for (int i = 0; i < len; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < len; i++) scanf("%d", &postorder[i]);
    scanf("%d", &T);
    while (T--) {
        int Start;
        pos = 0;
        for (int i = 0; i < len; i++) {
            scanf("%d", &inorder[i]);
            if (inorder[i] == preorder[0]) Start = i;
        }
        head = build(Start, 0, len);
        pos = 0;
        verify(head) ? printf("Yes\n") : printf("No\n");
        destroy(head);
    }
}

// in_idx為root的位置
// inorder_start為區間起始的位置
// inorder_end為區間結束的位置
Node* build(int in_idx, int inorder_start, int inorder_end) {

    Node* root = create_node(preorder[pos++]);

    // 左區間
    for (int i = inorder_start; i < in_idx; i++) {
        if (inorder[i] == preorder[pos]) {
            root->left = build(i, inorder_start, in_idx);
            break;
        }
    }

    // 右區間
    for (int i = in_idx + 1; i < inorder_end; i++) {
        if (inorder[i] == preorder[pos]) {
            root->right = build(i, in_idx + 1, inorder_end);
            break;
        }
    }

    return root;
}

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int verify(Node* root) {
    if (root->left && !verify(root->left)) return 0;
    if (root->right && !verify(root->right)) return 0;
    if (root->value != postorder[pos++]) return 0;
    return 1;
}

void destroy(Node* root) {
    if (root->left) destroy(root->left);
    if (root->right) destroy(root->right);
    free(root);
}

// Utin
