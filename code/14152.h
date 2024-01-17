#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////
struct Contestant;
typedef void (*Attack)(struct Contestant*, struct Contestant*);

struct Contestant
{
    char name[100];
    int health;
    int strength;
    int magic;
    int defense;
    int resistance;
    Attack attackType;
};

void magicalAttack(struct Contestant* self, struct Contestant* target) {
    int damage = self->magic - target->resistance;
    target->health -= damage;
}

void physicalAttack(struct Contestant* self, struct Contestant* target) {
    int damage = self->strength - target->defense;
    target->health -= damage;
}

void getContestants(struct Contestant* contestants, int len) {
    for (int i = 0; i < len; i++) {
        char tmp[10];
        scanf("%s %d %d %d %d %d %s", contestants[i].name, &contestants[i].health, &contestants[i].strength,
              &contestants[i].magic, &contestants[i].defense, &contestants[i].resistance, tmp);

        if (strcmp(tmp, "physical") == 0) {
            contestants[i].attackType = &physicalAttack;
        } else {
            contestants[i].attackType = &magicalAttack;
        }
    }
}

int findTarget(struct Contestant* contestants, int idx, int len) {
    int targetIdx = (idx + 1) % len;

    while (contestants[targetIdx].health <= 0) {
        targetIdx = (targetIdx + 1) % len;
    }

    return targetIdx;
}
//////////////////////////////////////////