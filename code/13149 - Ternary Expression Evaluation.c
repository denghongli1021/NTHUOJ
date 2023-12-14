#include <stdio.h>
#include <stdlib.h>

#define maxN 3000 + 5

typedef struct _Node {
	int id;
	struct _Node *l, *r;    //l -> true, r -> false
} Node;

char a[maxN];

Node* Construct() {
	Node* now = malloc(sizeof(Node));
	now->l = now->r = NULL;
	scanf("%d", &now->id);

	char c;
    scanf("%c", &c);

	if (c == '?') {
        now->l = Construct();
        now->r = Construct();
    }
	return now;
}

char Evaluate(Node* now) {
	if (a[now->id] == '1' && now->l) return Evaluate(now->l);
	else if (a[now->id] == '0' && now->r) return Evaluate(now->r);
	return a[now->id];
}

int main() {
	Node* root = Construct();
	int T;
    scanf("%d", &T);

	while (T--) {
		scanf("%s", a + 1);
		printf("%c\n", Evaluate(root));
	}
	return 0;
}

