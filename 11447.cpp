#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
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
	String::String(const std::string &str_)
		:str(str_){}

	String::String(const String &rhs)
		:str(rhs.str){}

	String& String::operator=(const String &rhs)
	{
		str=rhs.str;
		return *this;
	}

	std::ostream& operator<<(std::ostream &os,const String &str)
	{
		return os<<str.str;
	}
}

void oj::insert(std::map<int, oj::String> &ma, int key, const std::string &str) {
    std::string insertion = str;
    for (auto it : ma) {
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

int main()
{
	using namespace std;
	using namespace oj;
	map<int,String> ma;
	for(string cmd;cin>>cmd;)
	{
		if(cmd=="insert")
		{
			int key;
			cin>>key>>cmd;
			insert(ma,key,cmd);
		}
		else
			if(cmd=="range")
			{
				int begin,end;
				cin>>cmd>>begin>>end;
				if(cmd=="output")
					output(ma,begin,end);
				else
					if(cmd=="erase")
						erase(ma,begin,end);
					else
						assert(false);
			}
			else
				assert(false);
		cout<<ma<<endl;
	}
}
