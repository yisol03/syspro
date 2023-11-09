#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("How to use : %s FileName\n", argv[0]);
        return 1;
    }

    char savedText[MAX_LINES][MAX_LINES];
    FILE *file;
    int numLines = 0;

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error Open file\n");
        return 1;
    }

    while (fgets(savedText[numLines], MAX_LINES, file) != NULL && numLines < MAX_LINES) {
        numLines++;
    }

    fclose(file);

    for (int i = numLines - 1; i >= 0; i--) {
        printf("%s", savedText[i]);
    }

    return 0;
}
