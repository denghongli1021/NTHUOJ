#include <iostream>
#include <string>
#include <algorithm>
#include "function.h"
using namespace std;

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

enum position{
    FLOOR,
    STOMACH,
    TRASHCAN
};

class Food;
class Fruit;
class Meat;

class Food{
    protected:
        string name;
        int fly;
        int pos;
    public:
        // constructor
        Food();
        Food(string&);
        // copy constructor
        Food(const Food&);
        // functions
        // eaten: the food is eaten, change its position
        // thrown: the food is thrown, change its position
        // on_floor: return whether the food is on the floor
        // get_name: return the Food's name
        // get_fly: return the amount of the fly
        void eaten();
        void thrown();
        bool on_floor();
        string get_name();
        int get_fly();
        // operators
        // < : use this operator to sort the food so the output of on-floor food satisfy the requirement
        // == : determine whether the food's name is same as a string
        // << : output the food as the mentioned output format
        bool operator < (const Food&);
        bool operator == (const string&);
        friend ostream& operator << (ostream&, Food);
};

class Fruit: public Food{
    public:
        Fruit();
        Fruit(string&);
        // five_min_pass: 5 min passes
        // sickness: return whether the fruit makes someone sick
        // += : mix the food together
        void five_min_pass();
        bool sickness();
        void operator += (Fruit&);
        void operator += (Meat&);
};

class Meat: public Food{
    public:
        Meat();
        Meat(string&);
        // five_min_pass: 5 min passes
        // sickness: return whether the meat makes someone sick
        // += : mix the food together
        void five_min_pass();
        bool sickness();
        void operator += (Fruit&);
        void operator += (Meat&);
};
*/
Food::Food() : name(), fly(), pos() {}

Food::Food(string& Name) : name(Name), fly(), pos() {}

Food::Food(const Food& food) : name(food.name), fly(food.fly), pos(food.pos) {}

void Food::eaten() {
    this->pos = STOMACH;
}

void Food::thrown() {
    this->pos = TRASHCAN;
}

bool Food::on_floor() {
    if (this->pos == FLOOR) {
        return 1;
    }
    else {
        return 0;
    }
}

string Food::get_name() {
    return this->name;
}

int Food::get_fly() {
    return this->fly;
}

// operators
// < : use this operator to sort the food so the output of on-floor food satisfy the requirement
// == : determine whether the food's name is same as a string
// << : output the food as the mentioned output format
bool Food::operator < (const Food& right) {
    if (this->pos < right.pos) return 1;
    int ret = this->name.compare(right.name);
    if (this->pos == right.pos && ret < 0) return 1; //ret < 0 代表後者比較多
    else return 0;
    // 先比 position 如果是在地板 或是說 在 中 位置是比較前面的話 \
    // 那就return 1;
    // 如果是同一個position 則比較他們名子的長度
    // 如果後者名子字數比較多 就return 1
    // 總而言之 排序在越後面 的是 在floor 且名字字數比較少
    // 因為他是用sort
    // sort 預設是遞增
    // 而遞增就是用前一個和後一個比較字串長度
    // 前面比較長 輸出一個大於 0 的數
    // 反之 輸出小於 0
    /*
    enum position{
        FLOOR,
        STOMACH,
        TRASHCAN
    };
    */
    // compare 如果輸出市正的X 代表說前者比後者多幾個字元
    // 反之則代表少幾個字元
}

bool Food::operator == (const string& right) {
    return !this->name.compare(right);
    //this->name.compare(right); 如果一樣輸出0 所以前面加一not 就變 1
}

ostream& operator << (ostream& output, Food food) {
    output << food.get_name();
    return output;
}

Fruit::Fruit() : Food() {}

Fruit::Fruit(string& Name) : Food(Name) {}

void Fruit::five_min_pass() {
    if (this->pos == FLOOR) {
        this->fly += 4;
    }
}

bool Fruit::sickness() {
    if (this->fly >= 10 && this->pos == STOMACH) {
        return 1;
    }
    else {
        return 0;
    }
}
///mix
void Fruit::operator += (Fruit& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}

void Fruit::operator += (Meat& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}
///food operation and constructor
Meat::Meat() : Food() {}

Meat::Meat(string& Name) : Food(Name) {}

void Meat::five_min_pass() {
    if (this->pos == FLOOR) this->fly += 5;
}

bool Meat::sickness() {
    if (this->fly >= 20 && this->pos == STOMACH) {
        return 1;
    }
    else {
        return 0;
    }
}

void Meat::operator += (Fruit& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}

void Meat::operator += (Meat& m) {
    this->name = m.get_name() + this->name;
    this->fly += m.get_fly();
}
