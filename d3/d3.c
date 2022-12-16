# include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

//First, make it work, then, make it pretty
int main()
{
    FILE* file = fopen("input_ole.txt", "r"); /* should check the result */

    // Variables for puzzle 1
    char line[69] = {0};
    int total=0;
    char value=0;

    // Vairables for puzzle 2
    char lines[3][69];
    int total_badge_value=0;


    int lineNr=1;
    // Read from file and insert into line array
    while(fgets(line, 69, file)) {
        // Calculate half length of string
        size_t half = (strlen(line) - 1)/2;
        // Save to variable
        char leftWord[30] = {0};
        char rightWord[30] = {0};
        memcpy(&leftWord, &line[0], half);
        memcpy(&rightWord, &line[half], half);
        // Find common character
        char *common_char = strpbrk(leftWord, rightWord);
        // Calculate value and add to total
        if (isupper(common_char[0])) {
            value = common_char[0] - 38;
        }
        else {
            value = common_char[0] - 96;
        }
        total += value;


        // PUZZLE TWO
        char word[69] = {0};
        size_t full = strlen(line) -1;
        memcpy(&word, &line[0], full);


        // Find when three lines have been saved to array
        if (lineNr == 1) {
            // Save first line
            strcpy(lines[0], word);
        }
        else if (lineNr == 2) {
            // Save second line
            strcpy(lines[1], word);
        }
        else if (lineNr == 3) {
            // Save second line
            strcpy(lines[2], word);

            printf("lines[0]: %s\n", lines[0]);
            printf("lines[1]: %s\n", lines[1]);
            printf("lines[2]: %s\n", lines[2]);

            // MAGIC ABOUT TO HAPPEN
            char *startpoint = lines[0];

            int c=1;
            while (c==1) {
                char *first_match = strpbrk(startpoint, lines[1]);
                printf("first_match:   %s\n", first_match);
                char *last_match = strpbrk(first_match, lines[2]);
                printf("last_match:    %s\n", last_match);
                if (last_match != NULL) {
                    if (isupper(last_match[0])) {
                        total_badge_value += last_match[0] - 38;
                        printf("big letter %c increases score by 18 to: %d ...\n\n", last_match[0], total_badge_value);
                    }
                    else {
                        total_badge_value += last_match[0] - 96;
                        printf("small letter %c increases score by 18 to: %d ...\n\n", last_match[0], total_badge_value);
                    }
                    c=0;
                }
                else {
                    startpoint=first_match;
                }
            }
            // Finally reset the counter and lines
            lineNr=0;
            memset(lines[0], 0, 69); // clean on new run
            memset(lines[1], 0, 69); // clean on new run
            memset(lines[2], 0, 69); // clean on new run

        }
        else printf("ERRRRRRRRRRORR!!! wtf happened????\n");

        // Clean line for next line to be read.
        memset(line, 0, 69);
        lineNr++;
        //printf("line number increased to: %d\n\n",lineNr);
    }
    fclose(file);
    return 0;
}

