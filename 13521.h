#include <iostream>
#include <string>
#include "function.h"

//class Codec {
//public:
//    virtual void encode() = 0;
//    virtual ~Codec() { } // Do nothing
//    virtual void show() = 0;
//};
//
//class Number_Codec: public Codec {
//public:
//    Number_Codec(std::string s): code_str{s} { }
//    void encode();
//    void show(){
//        std::cout << code_str << "\n";
//    }
//private:
//    std::string code_str;
//};
//
//class Two_Number_Codec: public Codec
//{
//public:
//    Two_Number_Codec(std::string s): code_str{s} { }
//    void encode();
//    void show(){
//        std::cout << code_str << "\n";
//    }
//private:
//    std::string code_str;
//};
//
//class The_Rail_Fence_Cipher_Codec: public Codec
//{
//public:
//    The_Rail_Fence_Cipher_Codec(std::string s): code_str{s} { }
//    void encode();
//    void show(){
//        std::cout << code_str << "\n";
//    }
//private:
//    std::string code_str;
//};

using namespace std;

void Number_Codec::encode()
{
    string ans = "";
    for (int i = 0 ;i< code_str.size() ;i++) {
        int temp = code_str[i]-'a'+1;
        string temp2 = to_string(temp);
        ans += temp2 ;
    }
    code_str = ans ;
}

void Two_Number_Codec::encode()
{
    string ans = "";
    string temp2 = "";
    for (int i = 0 ;i< code_str.size() ;i++) {
        int temp = code_str[i]-'a'+1;
        if (temp <= 9) {
            temp2 = "0" + to_string(temp);
        }
        else {
            temp2 = to_string(temp);
        }
        ans += temp2 ;
    }
    code_str = ans ;
}

void The_Rail_Fence_Cipher_Codec::encode()
{
    string a1 = "";
    string a2 = "";
    string ans = "";
    int stop ;
    if (code_str.size() % 2 == 0) {
        stop = code_str.size() / 2;
    }
    else {
        stop = (code_str.size()+1 ) / 2;
    }
    for (int i =0;i<stop ;i++) {
        a1 += code_str[i];
    }
    for (int i = stop ;i < code_str.size() ; i++) {
        a2 += code_str[i];
    }
    int x = 0;
    int y = 0;
    //cout << "a1 : " << a1 << endl;
    //cout << "a2 : " << a2 << endl;
    for (int i = 0 ;i < code_str.size() ;i++) {
        if (i % 2 == 0) {
            ans += a1[x];
            x++;
        }
        else {
            ans += a2[y];
            y++;
        }
    }
    code_str = ans ;
}


