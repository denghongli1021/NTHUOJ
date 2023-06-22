#include <iostream>
#include <string>
#include <algorithm> // ¦]¬°sort
#include "function.h"
using namespace std;

Meat meat[105];
Fruit fruit[105];
int meat_count, fruit_count;

int get_index(string n, string k){
    if(k == "fruit"){
        for(int i = 0; i < fruit_count; i++){
            if(fruit[i] == n) return i;
        }
    }
    else{
        for(int i = 0; i < meat_count; i++){
            if(meat[i] == n) return i;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        while(n--){
            string s, n1, n2, k1, k2;
            cin >> s;
            if(s == "report"){
                cin >> n1 >> k1;
                if(k1 == "fruit"){
                    fruit[fruit_count++] = Fruit(n1);
                }
                else{
                    meat[meat_count++] = Meat(n1);
                }
            }
            else if(s == "eat"){
                cin >> n1 >> k1;
                int idx = get_index(n1, k1);
                if(k1 == "fruit"){
                    fruit[idx].eaten();
                }
                else{
                    meat[idx].eaten();
                }
            }
            else if(s == "throw"){
                cin >> n1 >> k1;
                int idx = get_index(n1, k1);
                if(k1 == "fruit"){
                    fruit[idx].thrown();
                }
                else{
                    meat[idx].thrown();
                }
            }
            else{
                cin >> n1 >> n2 >> k1 >> k2;
                int idx1 = get_index(n1, k1);
                int idx2 = get_index(n2, k2);
                if(k1 == "fruit"){
                    if(k2 == "fruit"){
                        fruit[idx1] += fruit[idx2];
                    }
                    else{
                        fruit[idx1] += meat[idx2];
                    }
                }
                else{
                    if(k2 == "fruit"){
                        meat[idx1] += fruit[idx2];
                    }
                    else{
                        meat[idx1] += meat[idx2];
                    }
                }
            }
        }
        for(int i = 0; i < fruit_count; i++){
            fruit[i].five_min_pass();
        }
        for(int i = 0; i < meat_count; i++){
            meat[i].five_min_pass();
        }
    }
    // sort the food in the order which meets the requirement
    sort(fruit, fruit + fruit_count);
    sort(meat, meat + meat_count);
    // Making the first t food be all the food on the floor. Design the '<' operator to do this.
    int sick = 0, flag = 0;
    int fruit_floor = fruit_count, meat_floor = meat_count;
    for(int i = 0; i < fruit_count; i++){
        Fruit f(fruit[i]);
        if(!f.on_floor() && !flag){
            fruit_floor = i;
            flag = 1;
        }
        if(f.sickness()) sick++;
    }
    flag = 0;
    for(int i = 0; i < meat_count; i++){
        Meat m(meat[i]);
        if(!m.on_floor() && !flag){
            meat_floor = i;
            flag = 1;
        }
        if(m.sickness()) sick++;
    }

    int onfloor = fruit_floor + meat_floor ;
    cout << sick << "\n" << onfloor << "\n";

    int fruit_idx = 0, meat_idx = 0;
    while(onfloor--){
        bool f1 = meat_idx == meat_floor;
        bool f2 = fruit_idx != fruit_floor;
        bool f3 = fruit[fruit_idx].get_name() < meat[meat_idx].get_name();
        if(f1 || (f2 && f3)){
            cout << fruit[fruit_idx++] << "\n";
        }
        else{
            cout << meat[meat_idx++] << "\n";
        }
    }
    return 0;
}
