#include<bits/stdc++.h>
using namespace std;

enum Gender {
    MALE,
    FEMALE
};

const string table[2] = {"MALE", "FEMALE"};

class Person {
    public:
        string name;
        int age;
        Gender gender;
        string personality;
        Person *parentA, *parentB, *mate, *child;

        Person() {
            this->name = "";
            this->age = 0;
            this->gender = MALE;
            this->personality = "";
            this->parentA = nullptr;
            this->parentB= nullptr;
            this->mate = nullptr;
            this->child = nullptr;
        }
        void describe(string* arr, int now, int len);
        Person* getRelative (string* arr, int now, int len);
        string info() {
            return
                "Name:" + this->name + ",\n" +
                "Age:" + to_string(this->age) + ",\n" +
                "Gender:" + table[this->gender] + ",\n" +
                "Personality:" + this->personality + "\n\n";
        };
};

string* ParseStatement(string statement) { // return the parsed array
    stringstream ss;
    vector<string> v;
    ss << statement;
    while (ss >> statement) v.push_back(statement);
    string* ret = new string[v.size()];
    for (int _ = 0; _ < v.size(); ++_) {
        ret[_] = v[_];
    }
    return ret;
}

int getParseStatementLength(string statement) {
    stringstream ss;
    ss << statement;
    int ret = 0;
    while (ss >> statement) ++ret;
    return ret;
}

int main () {
    Person* narrator = new Person();

    narrator->name = "Pineapple Senpai";
    narrator->age = 21;
    narrator->gender = MALE;
    narrator->personality = "seasick";

    int Q;
    cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        // input type of the query
        int type;
        cin >> type;
        // get the parsed array
        string statement;
        getline(cin, statement);
        string* arr = ParseStatement(statement);
        // compute the length of the array
        int len = getParseStatementLength(statement);
        switch(type) {
            case 1:
                narrator = narrator->getRelative(arr, 0, len);
                break;
            case 2:
                narrator->describe(arr, 0, len);
                break;
            case 3:
                cout << narrator->info() << "\n";
                break;
        }
        delete[] arr;
    }
    return 0;
}

void ParentA(Person* p) {
    if (!p->parentA) {
        if (p->parentB) {
            p->parentA = new Person;
            p->parentA->child = p;
            p->parentA->mate = p->parentB;
            p->parentB->mate = p->parentA;
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
// Utin
/*
#include<bits/stdc++.h>
using namespace std;

enum Gender {
    MALE,
    FEMALE
};

const string table[2] = {"MALE", "FEMALE"};

class Person {
    public:
        string name;
        int age;
        Gender gender;
        string personality;
        Person *parentA, *parentB, *mate, *child;

        Person() {
            this->name = "";
            this->age = 0;
            this->gender = MALE;
            this->personality = "";
            this->parentA = nullptr;
            this->parentB= nullptr;
            this->mate = nullptr;
            this->child = nullptr;
        }
        void describe(string* arr, int now, int len);
        Person* getRelative (string* arr, int now, int len);
        string info() {
            return
                "Name:" + this->name + ",\n" +
                "Age:" + to_string(this->age) + ",\n" +
                "Gender:" + table[this->gender] + ",\n" +
                "Personality:" + this->personality + "\n\n";
        };
};
*/
