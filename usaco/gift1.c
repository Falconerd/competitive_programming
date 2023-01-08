/*
ID: me85
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 15
#define MAX_PERSON_COUNT 10

int find_person_index(const char *name, char names[MAX_PERSON_COUNT][MAX_NAME_LENGTH]) {
    for (int i = 0; i < MAX_PERSON_COUNT; ++i) {
        if (strcmp(name, names[i]) == 0) {
            return i;
        }
    }

    // Should never be 1 so long as input is valid.
    return -1;
}

int main(void) {
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");

    int person_count;
    char names[MAX_PERSON_COUNT][MAX_NAME_LENGTH] = {0};
    int balances[MAX_PERSON_COUNT] = {0};

    fscanf(fin, "%d", &person_count);

    for (int i = 0; i < person_count; ++i) {
        fscanf(fin, "%s", names[i]);
    }

    for (int i = 0; i < person_count; ++i) {
        char name[MAX_NAME_LENGTH] = {0};
        int giving_amount, split_between, remainder;

        fscanf(fin, "%s", name);
        fscanf(fin, "%d %d", &giving_amount, &split_between);

        if (giving_amount == 0 || split_between == 0) {
            continue;
        }

        // Names are not stored in order, so 'i' does not work as the index.
        int sender_index = find_person_index(name, names);

        for (int j = 0; j < split_between; ++j) {
            char recipient[MAX_NAME_LENGTH] = {0};
            fscanf(fin, "%s", recipient);

            int recipient_index = find_person_index(recipient, names);

            if (giving_amount > 0 && split_between > 0) {
                balances[recipient_index] += giving_amount / split_between;
                remainder = giving_amount - (giving_amount / split_between) * split_between;
            }
        }

        balances[sender_index] -= giving_amount - remainder;
    }

    for (int i = 0; i < person_count; ++i) {
        fprintf(fout, "%s %d\n", names[i], balances[i]);
    }

    exit(0);
}
