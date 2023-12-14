#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string , string > mapping = {
{"Wa","Waninoko"},
{"Mi","Milotic"},
{"Ma","Magikarp"},
{"Va","Vaporeon"},
{"Sh","Sharpedo"},
{"Tapu","Tapu Fini"},
{"Em","Empoleon"},
{"Pi","Pikachu"},
{"Pe","Pikachu"},
{"La","Lapras"},
{"Me","Mega Gyarados"},
};

int main() {
    int testcase;
    cin >> testcase ;
    string name,school;
    for (int i = 1;i<=testcase;i++) {
        cin >> name >> school;
        bool find = false;
        for (auto &it : mapping) {
            /// substr
            if (name.substr(0,it.first.size()) == it.first) {
                find = true;
                cout << name << " " << "the " << school << " " << it.second << "\n";
                break;
            }
        }
        if (!find) {
            cout << name << " is looking for a Chinese tutor, too!\n";
        }
    }
}
