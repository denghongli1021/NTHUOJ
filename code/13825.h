typedef struct _Node {
    int id;
    struct _Node* next;
} Node;

void reverse(Node *node_l, Node *node_r) {
    Node* now = node_l->next;
    Node* tmp = now->next;
    now->next = node_r->next;
    Node* nextOne = tmp;
    while (now != node_r) {
        tmp = tmp->next;
        nextOne->next = now;
        now = nextOne;
        nextOne = tmp;
    }
    node_l->next = node_r;
}
