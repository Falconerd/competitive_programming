#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define LOWEST_POSSIBLE_NUMBER 1
#define HIGHEST_POSSIBLE_NUMBER 100

int main(void) {
    int count;
    scanf("%d", &count);
    int numbers[MAX_NUMBERS];

    int highest = LOWEST_POSSIBLE_NUMBER;
    int lowest = HIGHEST_POSSIBLE_NUMBER;
    int highest_index = 0;
    int lowest_index = 0;

    char number_str[4];
    int index = 0;
    while (scanf("%s", number_str) == 1) {
        int number = atoi(number_str);
        numbers[index] = number;

        if (number > highest) {
            highest = number;
            highest_index = index;
        } else if (number <= lowest) {
            lowest = number;
            lowest_index = index;
        }

        index += 1;
        if (index == count) {
            break;
        }
    }

    // Highest must be closest to the front of the array.
    int highest_distance = highest_index;
    int lowest_distance = count - 1 - lowest_index;
    int result = highest_distance + lowest_distance;

    // Subtract one when they swap with each other.
    if (lowest_index < highest_index) {
        result -= 1;
    }

    printf("%d\n", result);

    return 0;
}

