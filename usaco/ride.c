/*
ID: me85
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>

int hash(char *string) {
    int result = string[0] - '@';
    char *c = &string[1];

    while (*c != 0) {
        result *= *c - '@';
        ++c;
    }

    return result;
}

int main() {
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");

    char comet_name[7] = {0};
    char group_name[7] = {0};

    fscanf(fin, "%s %s", comet_name, group_name);

    if (hash(comet_name) % 47 == hash(group_name) % 47) {
        fprintf(fout, "%s\n", "GO");
    } else {
        fprintf(fout, "%s\n", "STAY");
    }

    exit(0);
}
