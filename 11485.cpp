#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

void insert();
void output();
void range_out();
int decode(vector<int> v);

struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        return decode(a) < decode(b);
    }
};

set<vector<int>, cmp> S;

int main() {
    string op;
    while (cin >> op) {
        if (op == "insert") insert();
        if (op == "output") output();
        if (op == "range_out") range_out();
    }
}

// insert operation
void insert() {
    // get input
    int input;
    vector<int> vec;
    while (true) {
        cin >> input;
        if (!input) break;
        vec.push_back(input);
    }
    // check if it is existed
    int ID = decode(vec);
    for (auto it : S) {
        if (decode(it) == ID) {
            cout << "exist\n";
            S.erase(it);
            vector<int> tmp_vec;
            for (auto i = vec.rbegin(); i < vec.rend(); i++)
                tmp_vec.push_back(*i);
            vec = tmp_vec;
            break;
        }
    }

    // insert to set
    S.insert(vec);
}

// outut operation
void output() {
    for (auto it : S) {
        for (auto element : it)
            cout << element << ' ';
        cout << '\n';
    }
}

// range_out operation
void range_out() {
    // get input and count the endpoints
    int input, pt[2];
    for (int t = 0; t < 2; t++) {
        vector<int> vec;
        while (true) {
            cin >> input;
            if (!input) break;
            vec.push_back(input);
        }
        pt[t] = decode(vec);
    }

    // output
    for (auto it : S) {
        int ID = decode(it);
        if (ID >= pt[0] && ID <= pt[1]) {
            for (auto element : it)
                cout << element << ' ';
            cout << '\n';
        }
    }
}

// count key value
int decode(vector<int> v) {
    int ret = 0;
    for (int i = 0; i < v.size(); i++)
        ret += v[i] * (v.size() - i);
    return ret;
}

// By Utin
