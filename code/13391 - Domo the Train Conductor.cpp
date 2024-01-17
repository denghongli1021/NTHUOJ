#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct Train {
    Node* head;
    Node* back;
};

typedef struct Train Train;

Train* createTrain() {
    Train* train = (Train*)malloc(sizeof(Train));
    train->head = NULL;
    train->back = NULL;
    return train;
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addFront(Train* train, int num) {
    Node* newNode = createNode(num);
    if (train->head == NULL) {
        train->head = newNode;
        train->back = newNode;
    } else {
        newNode->next = train->head;
        train->head = newNode;
    }
}

void addBack(Train* train, int num) {
    Node* newNode = createNode(num);
    if (train->head == NULL) {
        train->head = newNode;
        train->back = newNode;
    } else {
        train->back->next = newNode;
        train->back = newNode;
    }
}

void deleteCarriages(Train* train, int num) {
    Node* current = train->head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == num) {
            if (previous == NULL) {
                train->head = current->next;
            } else {
                previous->next = current->next;
            }

            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            previous = current;
            current = current->next;
        }
    }
}

void deleteFront(Train* train) {
    if (train->head != NULL) {
        Node* temp = train->head;
        train->head = train->head->next;
        free(temp);
    }
}

void swap(Train* train) {
    Node* current = train->head;
    Node* previous = NULL;
    Node* temp;

    while (current != NULL) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    train->head = previous;
}

void printTrain(Train* train) {
    Node* current = train->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Train* train = createTrain();
    char instruction[15];
    int num;

    while (scanf("%s", instruction) != EOF) {
        if (instruction[0] == 'A') {
            scanf("%s %d", instruction, &num);
            if (instruction[3] == 'F') {
                addFront(train, num);
            } else {
                addBack(train, num);
            }
        } else if (instruction[0] == 'D') {
            scanf("%d", &num);
            deleteCarriages(train, num);
        } else if (instruction[0] == 'D' && instruction[6] == 'F') {
            deleteFront(train);
        } else if (instruction[0] == 'S') {
            swap(train);
        }
    }

    printTrain(train);

    return 0;
}
