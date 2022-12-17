# include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

//91-93,6-92
//85-97,18-63
//15-99,16-98
//35-49,34-50
//4-7,6-93
//57-86,57-58
//1-82,83-90
//21-88,20-89
//83-84,1-83
//8-82,7-83

//First, make it work, then, make it pretty
int main() {
    FILE* file = fopen("input.txt", "r"); /* should check the result */

    // Variables for puzzle 1
    //int total_overlapping_pairs=0;
    int lineNr=0;    // line number

    char line[13] = {0};        // the line
    char leftAss[2][3] = {0};   // left of the  ','
    char rightAss[2][3] = {0};  // right of the ','

    char buffer[13] = {0}; // buffer for lines read
    while(fgets(buffer, 13, file)) {
        memcpy(&line, &buffer[0], 13);
        char * tok_ptr; // pointer for traversal

        printf("\n\nL%d: %s \n", lineNr, line);


       //tok_ptr = strtok (line,"-");
       //strcpy(&leftAss[0], tok_ptr);
       //tok_ptr = strtok (NULL, ",");
       //strcpy(&leftAss[1], tok_ptr);
       //tok_ptr = strtok (NULL, "-");
       //strcpy(&rightAss[0], tok_ptr);
       //tok_ptr = strtok (NULL, "-");
       //strcpy(&rightAss[1], tok_ptr);

        printf("%s - %s , %s - %s\n", leftAss[0], leftAss[1], rightAss[0], rightAss[1]);
        memset(line, 0, 13);
        lineNr++;
    }
    fclose(file);
    return 0;
}

