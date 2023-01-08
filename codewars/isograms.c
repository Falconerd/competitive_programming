#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool IsIsogram (const char *string) 
{
    int length = strlen(string);
    bool found[26] = {false};

    if (length < 2) {
        return true;
    }

    for (int i = 0; i < length; ++i) {
        char c = string[i];
        if (string[i] >= 'A' && string[i] <= 'Z') {
            c += 32;
        }

        if (found[c - 97]) {
            return false;
        }

        found[c - 97] = true;
    }

    return true;
}

