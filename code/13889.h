#include "function.h"
#include <bits/stdc++.h>
using namespace std;

int pairofmate = 0;

int getAns() {
    return pairofmate / 2 ;
}

void ParentA(Person* p) {
    if (!p->parentA) {
        if (p->parentB) {
            p->parentA = new Person;
            p->parentA->child = p;
            p->parentA->mate = p->parentB;
            p->parentB->mate = p->parentA;
            pairofmate += 2;
            //printf("pair now by parent A: %d\n",pairofmate);
        }
        else {
            p->parentA = new Person;
            p->parentA->child = p;
        }
    }
}

void ParentB(Person* p) {
    if (!p->parentB) {
        if (p->parentA) {
            p->parentB = new Person;
            p->parentB->child = p;
            p->parentB->mate = p->parentA;
            p->parentA->mate = p->parentB;
            pairofmate += 2;
            //printf("pair now by parent B: %d\n",pairofmate);
        }
        else {
            p->parentB = new Person;
            p->parentB->child = p;
        }
    }
}

void Mate(Person* p) {
    if (!p->mate) {
        if (p->child) {
            p->mate = new Person();
            p->mate->mate = p;
            if (p->child->parentA == p)
                p->child->parentB = p->mate;
            else p->child->parentA = p->mate;
            p->mate->child = p->child;
        }
        else {
            p->mate = new Person();
            p->mate->mate = p;
        }
        pairofmate += 2;
        //printf("pair now by mate: %d\n",pairofmate);
    }
}

void Child(Person* p) {
    if (!p->child) {
        if (p->mate) {
            p->child = new Person();
            p->mate->child = p->child;
            p->child->parentA = p;
            p->child->parentB = p->mate;
        }
        else {
            p->child = new Person();
            p->child->parentA = p;
        }
    }
}

void Person::describe(string* arr, int now, int len) {
    if (now >= len) return;

    else if (arr[now] == "ParentA") {
        ParentA(this);
        this->parentA->describe(arr, now + 1, len);
    }

    else if (arr[now] == "ParentB") {
        ParentB(this);
        this->parentB->describe(arr, now + 1, len);
    }

    else if (arr[now] == "Mate") {
        Mate(this);
        this->mate->describe(arr, now + 1, len);
    }

    else if (arr[now] == "Child") {
        Child(this);
        this->child->describe(arr, now + 1, len);
    }

    else if (arr[now] == "Gender") {
        if (arr[now + 1] == "MALE") this->gender = MALE;
        else this->gender = FEMALE;
        this->describe(arr, now + 2, len);
    }

    else if (arr[now] == "Age") {
        this->age = stoi(arr[now + 1]);
        this->describe(arr, now + 2, len);
    }

    else if (arr[now] == "Name") {
        this->name = arr[now + 1];
        this->describe(arr, now + 2, len);
    }

    else if (arr[now] == "Personality") {
        if (this->personality == "") this->personality = arr[now + 1];
        else this->personality += " " + arr[now + 1];
        this->describe(arr, now + 2, len);
    }
}

Person* Person::getRelative(string* arr, int now, int len) {
    if (now == len)
        return this;

    if (arr[now] == "ParentA") {
        ParentA(this);
        return this->parentA->getRelative(arr, now + 1, len);
    }

    else if (arr[now] == "ParentB") {
        ParentB(this);
        return this->parentB->getRelative(arr, now + 1, len);
    }

    else if (arr[now] == "Mate") {
        Mate(this);
        return this->mate->getRelative(arr, now + 1, len);
    }

    else if (arr[now] == "Child") {
        Child(this);
        return this->child->getRelative(arr, now + 1, len);
    }

    else return this;
}
