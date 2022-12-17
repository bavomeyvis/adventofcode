#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

//First, make it work, then, make it pretty
int main() {
    FILE* file = fopen("input.txt", "r"); /* should check the result */

    // Variables for puzzle 1
    int full_overlaps=0;
    int overlaps=0;
    int lineNr=0;    // line number

    char line[13] = {0};        // the line
    char leftElf[2][3] = {0};   // left of the  ','
    char rightElf[2][3] = {0};  // right of the ','

    char buffer[13] = {0}; // buffer for lines read
    while(fgets(buffer, 13, file)) {
        memcpy(&line, &buffer[0], 13);
        char * p = line; // pointer for traversal
        int pos = 0;
        while (*p) { // While there are more characters to process...
            if ( isdigit(*p) && *p >= 0 ) {
                // Found a number
                long val = (int)strtol(p, &p, 10);
                if (pos == 0)       memcpy(&leftElf[0], &val, sizeof(char));
                else if (pos == 1)  memcpy(&leftElf[1], &val, sizeof(char));
                else if (pos == 2)  memcpy(&rightElf[0], &val, sizeof(char));
                else                memcpy(&rightElf[1], &val, sizeof(char));
                pos++;
            } else {
                p++; // Otherwise, move on to the next character.
            }
        }

        if ((*leftElf[0] <= *rightElf[0] && *leftElf[1] >= *rightElf[1]) || (*rightElf[0] <= *leftElf[0] && *rightElf[1] >= *leftElf[1])) {
            full_overlaps += 1;
        }

        if (*leftElf[0] <= *rightElf[1] && *leftElf[1] >= *rightElf[0]) {
            overlaps += 1;
        }

        // Prepare for next line
        memset(line, 0, 13);
        lineNr++;
    }
    printf("Total full overlaps: %d\nTotal overlaps:\t%d\n", full_overlaps, overlaps);
    fclose(file);
    return 0;
}

