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
    if (this->pos == right.pos && ret < 0) return 1; //ret < 0 �N���̤���h
    else return 0;
    // ���� position �p�G�O�b�a�O �άO�� �b �� ��m�O����e������ \
    // ���Nreturn 1;
    // �p�G�O�P�@��position �h����L�̦W�l������
    // �p�G��̦W�l�r�Ƥ���h �Nreturn 1
    // �`�Ө��� �ƧǦb�V�᭱ ���O �bfloor �B�W�r�r�Ƥ����
    // �]���L�O��sort
    // sort �w�]�O���W
    // �ӻ��W�N�O�Ϋe�@�өM��@�Ӥ���r�����
    // �e������� ��X�@�Ӥj�� 0 ����
    // �Ϥ� ��X�p�� 0
    /*
    enum position{
        FLOOR,
        STOMACH,
        TRASHCAN
    };
    */
    // compare �p�G��X������X �N���e�̤��̦h�X�Ӧr��
    // �Ϥ��h�N��ִX�Ӧr��
}

bool Food::operator == (const string& right) {
    return !this->name.compare(right);
    //this->name.compare(right); �p�G�@�˿�X0 �ҥH�e���[�@not �N�� 1
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
