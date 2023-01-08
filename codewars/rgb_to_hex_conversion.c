#include <stdio.h>

int clamp(int n) {
    return n < 0 ? 0 : n > 255 ? 255 : n;
}

int rgb(int r, int g, int b, char *output) {
    sprintf(output, "%02X%02X%02X", clamp(r), clamp(g), clamp(b));
    return 0; 
}
