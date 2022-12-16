# include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//std::map


//First, make it work, then, make it pretty
int main()
{
    FILE* file = fopen("input.txt", "r"); /* should check the result */
    char line[5] = {0};
    int score=0;
    int secret_score = 0;
    // Read from file and insert into line array
    while(fgets(line, 5, file)) {
        printf("\n\n%c - %c (current score: %d)", line[0], line[2], score);
        if (line[2] == 'X') {
            score += 1;
        }
        else if (line[2] == 'Y') {
            score += 2;
        }
        else if (line[2] == 'Z') {
            score += 3;
        }
        // this also covers part 2
        if (line[2] == 'X') {
            if (line[0] == 'C') {
                score += 6;
                secret_score += 2;
            }
            else if (line[0] == 'A') {
                score += 3;
                secret_score += 3;
            }
            else {
                secret_score += 1;
            }
        }
        else if (line[2] == 'Y') {
            secret_score += 3;
            if (line[0] == 'A') {
                score += 6;
                secret_score += 1;
            }
            else if (line[0] == 'B') {
                score += 3;
                secret_score += 2;
            }
            else {
                secret_score += 3;
            }
        }
        else if (line[2] == 'Z') {
            secret_score += 6;
            if (line[0] == 'B') {
                score += 6;
                secret_score += 3;
            }
            else if (line[0] == 'C') {
                score += 3;
                secret_score += 1;
            }
            else {
                secret_score += 2;
            }
        }
    }
    printf("\nTotal score: %d\nTotal secret score: %d", score, secret_score);
    fclose(file);
    return 0;
}

