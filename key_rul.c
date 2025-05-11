#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Key dimensions in centimeters
#define KEY_WIDTH_CM 1.8
#define KEY_SPACING_CM 0.2
#define TOTAL_KEY_SIZE_CM (KEY_WIDTH_CM + KEY_SPACING_CM)

// Struct to represent a key's position
typedef struct {
    char key;
    int x;
    int y;
} KeyPos;

// Simplified QWERTY layout (only letters)
KeyPos layout[] = {
    {'Q', 0, 0}, {'W', 1, 0}, {'E', 2, 0}, {'R', 3, 0}, {'T', 4, 0},
    {'Y', 5, 0}, {'U', 6, 0}, {'I', 7, 0}, {'O', 8, 0}, {'P', 9, 0},
    {'A', 0, 1}, {'S', 1, 1}, {'D', 2, 1}, {'F', 3, 1}, {'G', 4, 1},
    {'H', 5, 1}, {'J', 6, 1}, {'K', 7, 1}, {'L', 8, 1},
    {'Z', 0, 2}, {'X', 1, 2}, {'C', 2, 2}, {'V', 3, 2}, {'B', 4, 2},
    {'N', 5, 2}, {'M', 6, 2}
};

// Finds a key's position in the layout
KeyPos find_key(char c) {
    for (size_t i = 0; i < sizeof(layout) / sizeof(layout[0]); i++) {
        if (layout[i].key == c) {
            return layout[i];
        }
    }
    // Return an invalid position if key not found
    return (KeyPos){.key = c, .x = -1, .y = -1};
}

// Calculates the distance between two keys in centimeters
double get_distance(KeyPos a, KeyPos b) {
    double dx = (a.x - b.x) * TOTAL_KEY_SIZE_CM;
    double dy = (a.y - b.y) * TOTAL_KEY_SIZE_CM;
    return sqrt(dx * dx + dy * dy);
}

int main(void) {
    char key1, key2;

    printf("Enter the first key: ");
    if (scanf(" %c", &key1) != 1) {
        fprintf(stderr, "Error reading the first key.\n");
        return 1;
    }

    printf("Enter the second key: ");
    if (scanf(" %c", &key2) != 1) {
        fprintf(stderr, "Error reading the second key.\n");
        return 1;
    }

    // Convert input to uppercase to match layout
    KeyPos k1 = find_key(toupper(key1));
    KeyPos k2 = find_key(toupper(key2));

    if (k1.x == -1 || k2.x == -1) {
        fprintf(stderr, "Invalid key entered.\n");
        return 1;
    }

    double distance_cm = get_distance(k1, k2);
    printf("Distance between '%c' and '%c': %.2f cm\n", key1, key2, distance_cm);

    return 0;
}
