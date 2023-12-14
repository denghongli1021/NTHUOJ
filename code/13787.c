#include <stdio.h>
#include "function.h"

char thename[10][100] = {"Geodude", "Raichu", "Golbat", "Magnemite", "Exeggutor"};

void init();
void init_pokemon(int idx, int atk, int dfn, int hp, int mp, int cmp);

Pokemon myPokemon[1005];
Pokemon initPokemon[10];

int main(){
    init();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int type;
        scanf("%d", &type);
        myPokemon[i] = initPokemon[type];
    }
    int t;
    scanf("%d", &t);
    while(t--){
        int c;
        scanf("%d", &c);
        if(c == 1){
            int a;
            scanf("%d", &a);
            level_up(&myPokemon[a]);
        }
        else{
            int a, b;
            scanf("%d%d", &a, &b);
            battle(&myPokemon[a], &myPokemon[b]);
        }
    }
    return 0;
}

void init(){
    init_pokemon(0, 300, 100, 10, 20, 5);
    init_pokemon(1, 400, 50, 10, 25, 10);
    init_pokemon(2, 200, 80, 10, 15, 3);
    init_pokemon(3, 200, 50, 10, 15, 4);
    init_pokemon(4, 500, 150, 15, 20, 10);
}

void init_pokemon(int idx, int atk, int dfn, int hp, int mp, int cmp){
    strcpy(initPokemon[idx].name, thename[idx]);
    initPokemon[idx].id = idx;
    initPokemon[idx].level = 1;
    initPokemon[idx].attack = atk;
    initPokemon[idx].defense = dfn;
    initPokemon[idx].Hp = hp;
    initPokemon[idx].Mp = mp;
    initPokemon[idx].maxHp = hp;
    initPokemon[idx].maxMp = mp;
    initPokemon[idx].costMp = cmp;
}
