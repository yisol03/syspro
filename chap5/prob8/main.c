#include <stdio.h>
#include <string.h>

#define MAX_LINES 100


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("How to use: %s FileName\n", argv[0]);
        return 1;
    }

    char savedText[MAX_LINES][MAX_LINES];
    FILE *fp;
    int numLines = 0;

    fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
        printf("Error Open File\n");
        return 1;
    }
   
    while (fgets(savedText[numLines], MAX_LINES, fp) != NULL && numLines < MAX_LINES) {
        numLines++;
    }

    fclose(fp);

    char input[100];
    scanf("%s", input);

    if (input[0] == '*') {
        for (int i = 0; i < numLines; i++) {
            printf("%s", savedText[i]);
        }
    } else {
        char *token = strtok(input, ",");
        while (token != NULL) {
            int start, end;
            if (strstr(token, "-")) {
                sscanf(token, "%d-%d", &start, &end);
            } else {
                sscanf(token, "%d", &start);
                end = start;
            }

            if (start < 1 || end > numLines || start > end) {
                printf("잘못된 범위 또는 번호가 입력되었습니다.\n");
                return 1;
            }

            for (int i = start - 1; i < end; i++) {
                printf("%s", savedText[i]);
            }

            token = strtok(NULL, ",");
        }
    }

    return 0;
}

