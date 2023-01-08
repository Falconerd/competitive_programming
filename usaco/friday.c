/*
ID: me85
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>

int is_leap_year(int year) {
    if (year % 100 == 0) {
        return year % 400 == 0;
    }
    return year % 4 == 0;
}

// Use 1-index so as to not break one's brain.
int days_in_month[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main() {
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");

    int years;
    fscanf(fin, "%d", &years);

    // Store the count of 13ths in here.
    int days[7] = {0};

    int day_of_week = 2; // Mon, 1st Jan 1900

    for (int year = 1900; year < 1900 + years; ++year) {
        for (int month = 1; month <= 12; ++month) {
            int days_this_month = days_in_month[month];

            // Leap year Feb is 29.
            if (is_leap_year(year) && month == 2) {
                days_this_month = 29;
            }

            for (int date_of_month = 1; date_of_month <= days_this_month; ++date_of_month) {
                if (date_of_month == 13) {
                    ++days[day_of_week];
                }

                //printf("day_of_week: %d, month: %d, date_of_month: %d\n", day_of_week, month, date_of_month);

                ++day_of_week;

                if (day_of_week == 7) {
                    day_of_week = 0;
                }
            }
        }
    }

    fprintf(fout, "%d %d %d %d %d %d %d\n", days[0], days[1], days[2], days[3], days[4], days[5], days[6]);

    exit(0);
}
