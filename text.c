#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int n;
    char knuckles[10000000 + 5];
    scanf("%d", &n);
    scanf("%s", knuckles);
    int freq[26];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++) {
        freq[knuckles[i] - 'a']++;
    }
    int distinct_knuckles = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            distinct_knuckles++;
        }
    }
    if (distinct_knuckles) {
        printf("I'm the god of Knuckles!\n");
    } else {
        printf("Different makes perfect\n");
    }
    return 0;
}
