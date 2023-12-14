#include <bits/stdc++.h>
#include "function.h"

void oj::insert(std::map<int, oj::String> &ma, int key, const std::string &str) {
    std::string insertion = str;
    for (auto it : ma) {
        // map 可以用 first 代表第一個的值
        // second 代表第二個
        if (it.first == key) {
            insertion += it.second.str;
            ma.erase(key);
            break;
        }
    }

    ma.insert({key, oj::String(insertion)});
}

void oj::output(const std::map<int, oj::String> &ma, int begin, int end) {
    for (auto it = ma.begin(); it != ma.end(); it++)
        if (it->first >= begin && it->first <= end)
            std::cout << it->second << ' ';
}

void oj::erase(std::map<int, oj::String> &ma, int begin, int end) {
    for (int i = begin; i <= end; i++) ma.erase(i);
}

std::ostream &oj::operator<<(std::ostream &output,const std::map<int, oj::String> &x) {
    for (auto it : x) output << it.second << ' ';
    return output;
}

// By Utin
/*
#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<map>
#include<string>

namespace oj
{
	struct String
	{
		std::string str;
		String(const std::string &);
		String(const String &);
		String& operator=(const String &);
	};

	std::ostream& operator<<(std::ostream &,const String &);

	void insert(std::map<int,String> &ma,int key,const std::string &str);
	void output(const std::map<int,String> &ma,int begin,int end);
	void erase(std::map<int,String> &ma,int begin,int end);

	std::ostream& operator<<(std::ostream &,const std::map<int,String> &);
}

#endif
*/
