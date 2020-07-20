#include <stdio.h>
#include <malloc.h>
#include <string.h>


void readline(char **str, int *lineSize);

int main() {
    printf("Enter your wordfind puzzle:\n");

    int *xCoord[26]; // coord for searching letters
    int *yCoord[26];
    int metingCount[26]; // amount of letters
    int memoryCount[26];

    // memory allocating for coord
    for (int i = 0; i < 26; ++i) {
        metingCount[i] = 0;
        memoryCount[i] = 64;
        xCoord[i] = (int *) malloc(sizeof(int) * memoryCount[i]);
        yCoord[i] = (int *) malloc(sizeof(int) * memoryCount[i]);
    }
    int rowCounter = -1;
    int n = 64; // amount of memory (random number 2^n)
    char **matrix = (char **) malloc(sizeof(char *) * n); //dinamic array of pointer to strings
    char *word;
    int lineCounter = 0;
    int lineSize = 0;


    while (1) {
        readline(&matrix[lineCounter], &lineSize); //reading matrix of letters
        if (lineSize == 0) {
            break;
        }
        if (rowCounter == -1) {
            rowCounter = lineSize;
        } else {
            if (rowCounter != lineSize) {
                printf("Invalid input!\n");
                return 1;
            }
        }

        lineCounter++;

        // memory increase if not enough
        if (lineCounter >= n) {
            n *= 2;
            matrix = (char **) realloc(matrix, sizeof(char *) * n);

        }
    }
// creating new array, coping matrix to array, 1 if '.'  0 if char
// Araycross = flags to print if nesssecary
    char **arrayCross = (char **) malloc((sizeof(char *)) * lineCounter);
    for (int i = 0; i < lineCounter; i++) {
        arrayCross[i] = (char *) malloc(sizeof(char) * rowCounter);
        for (int j = 0; j < rowCounter; j++) {

            arrayCross[i][j] = matrix[i][j] == '.' ? 1 : 0;
        }
    }
// searching letter for coord
    for (int x = 0; x < lineCounter; x++) {
        for (int y = 0; y < rowCounter; y++) {
            if (matrix[x][y] != '.') {
                int idx = matrix[x][y] - 'a';
                xCoord[idx][metingCount[idx]] = x;
                yCoord[idx][metingCount[idx]] = y;
                metingCount[idx]++;
                if (metingCount[idx] == memoryCount[idx]) {
                    memoryCount[idx] *= 2;

                    xCoord[idx] = (int *) realloc(xCoord[idx], sizeof(int) * memoryCount[idx]);
                    yCoord[idx] = (int *) realloc(yCoord[idx], sizeof(int) * memoryCount[idx]);
                }

            }

        }
    }
    // arrays of directions
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

    while (1) {
        readline(&word, &lineSize);
        if (lineSize == 0) break;
        int idx = word[0] - 'a';
        for (int i = 0; i < metingCount[idx]; i++) {

            // algo for moving throw 8 directions
            for (int t = 0; t < 8; t++) {
                int x = xCoord[idx][i];
                int y = yCoord[idx][i];
                int pos = 0;
                while (pos < lineSize
                       && x >= 0 && x < lineCounter
                       && y >= 0 && y < rowCounter
                       && word[pos] == matrix[x][y]) {
                    x += dx[t];
                    y += dy[t];
                    pos += 1;
                }
                if (pos == lineSize) {
                    int x = xCoord[idx][i];
                    int y = yCoord[idx][i];
                    for (int n = 0; n < lineSize; n++) {
                        arrayCross[x][y] = 1;
                        x += dx[t];
                        y += dy[t];
                    }
                }

            }
        }
    }
    // printing result
    printf("Result is:\n");
    for (int x = 0; x < lineCounter; x++) {
        for (int y = 0; y < rowCounter; y++) {
            if (arrayCross[x][y] == 0) {

                printf("%c", matrix[x][y]);

            }
        }
    }

    return 0;
}


void readline(char **str , int *lineSize) {

    char buffer[1024];
    char tmp;
    int index =0;
    *str = NULL;
    scanf("%c",&tmp);
    *lineSize =0;
    while (tmp != '\n') {

        buffer[index++] = tmp;
        if (index == 1024) {
            lineSize += 1024;
            *str = (char *)realloc(*str, *lineSize * sizeof(char ));
          //  memccpy(*str + *lineSize - 8, buffer, sizeof(buffer) / sizeof(char), sizeof(char));
            for( int i = 0; i < 1024; ++i)
                (*str)[*lineSize - 1024 + i] = buffer[i];
            index = 0;
        }
        scanf("%c",&tmp);

    }
    if(index != 0){
        *lineSize += index;
        *str = (char *)realloc(*str, *lineSize * sizeof(char ));
        //memccpy(*str + *lineSize - index, buffer, index, sizeof(char));
        for( int i = 0; i < index; ++i)
            (*str)[*lineSize - index + i] = buffer[i];
    }
}