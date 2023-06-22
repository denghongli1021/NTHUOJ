#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Case{
    protected:
        bool converted;
        string name;
    public:
        virtual void convert() = 0;
        virtual void revert() = 0;
        virtual ~Case(){}
        Case(string s): converted(false), name(s){}
        void show(ostream &os){
            os << name;
        }
        bool is_converted() const{
            return converted;
        }
};

class SnakeCase : public Case{
    public:
        SnakeCase(string s): Case(s){}
        void convert(){
            converted = true;
            for(int i = 0; i < name.length(); i++){
                if(name[i] == '-') name[i] = '_';
            }
        }
        void revert(){
            converted = false;
            for(int i = 0; i < name.length(); i++){
                if(name[i] == '_') name[i] = '-';
            }
        }
};

class CamelCase : public Case{
    public:
        CamelCase(string s): Case(s){}
        void convert();
        void revert();
};

void CamelCase::convert() {
    converted = true;
    stringstream ss;
    string tmp;
    ss << name;
    while (!ss.eof()) {
        string token;
        getline(ss, token, '-');
        token[0] -= 32; //Âà¤j¼g
        tmp += token;
    }
    name = tmp;
}

void CamelCase::revert() {
    converted = false;
    string tmp;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 'a') {
            if (i) tmp += '-';
            name[i] += 32;
        }
        tmp += name[i];
    }
    name = tmp;
}

ostream& operator << (ostream &os, Case &data){
    data.show(os);
    return os;
}

void convert_revert(Case &data){
    if(!data.is_converted()) data.convert();
    else data.revert();
}

int main(){
    string input_string;
    getline(cin, input_string);

    SnakeCase snake(input_string);
    convert_revert(snake);
    cout << "Snake Case (converted): " << snake << "\n";
    convert_revert(snake);
    cout << "Snake Case (reverted): " << snake << "\n";

    CamelCase camel(input_string);
    convert_revert(camel);
    cout << "Camel Case (converted): " << camel << "\n";
    convert_revert(camel);
    cout << "Camel Case (reverted): " << camel << "\n";
    return 0;
}
