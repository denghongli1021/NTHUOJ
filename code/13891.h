/*
#include <iostream>
#include <string>
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
*/

#include <iostream>
#include <string>
#include <sstream>
#include "function.h"
using namespace std;

void CamelCase::convert() {
    converted = true;
    string tmp;

    for (int i = 0 ;i< name.size() ;i++) {
        if ( i == 0) {
            tmp += name[i] - 32 ;
            continue;
        }
        if (name[i] == '-') {
            tmp += name[i+1] - 32;
            i++;
            continue;
        }
        tmp += name[i];
    }
    /*
    stringstream ss;
    string tmp;
    ss << name;
    while (!ss.eof()) {
        string token;
        getline(ss, token, '-');
        token[0] -= 32; // Âà¤j¼g
        tmp += token;
    }
    */
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

// Utin
