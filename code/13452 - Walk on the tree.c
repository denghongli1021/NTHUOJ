
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	int left;
	int right;
	int parent;
} Node;

int N, Q, A, B,count = 0;
Node arr[3001];

int run(int idx, int pre);

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        arr[i].value = i;
        arr[i].parent = 0;
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &arr[i].left, &arr[i].right);
        arr[arr[i].left].parent = arr[i].value;
        arr[arr[i].right].parent = arr[i].value;
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &A, &B);
        run(B, 0); // �˹L�Ӷ]
        printf("\n");
    }
}

int run(int idx, int pre) {
    // ��o�FA
    if (idx == A) {
        return 1;
    }
    // �줣�FA
    if (!idx) return 0;

    // �T�Ӥ�V���դ@�U
    if (arr[idx].left != pre && run(arr[idx].left, idx)) {
        printf("P");
        return 1;
    }
    if (arr[idx].right != pre && run(arr[idx].right, idx)) {
        printf("P");
        return 1;
    }
    if (arr[idx].parent != pre && run(arr[idx].parent, idx)) {
        if (arr[arr[idx].parent].left == arr[idx].value) printf("L");
        else printf("R");
        return 1;
    }

    // �S��
    return 0;
}

// By Utin
