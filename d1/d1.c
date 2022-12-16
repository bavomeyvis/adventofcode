#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


//First, make it work, then, make it pretty

#define MAX_LINES 100
#define MAX_LEN 1000

int main()
{
    char const* const fileName = "input.txt"; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */
    char lines[2500][10];

    // Read from file and insert into lines array
    int k=0;
    while(fgets(lines[k], 10, file)) {
        k++;
    }

    // Create array representing elves' total calories
    int elf=0;
    int totalCalories[1000] = {0};
    int currentElfCalories=0;
    int b=0;
    while(b<sizeof(lines) && strlen(lines[b]) != 0) {
        if (strcmp(lines[b], "\n") == 0) {
            totalCalories[elf]=currentElfCalories;
            elf++;
            currentElfCalories=0;
        }
        else {
            currentElfCalories += atoi(lines[b]);
        }
        b++;
    }

    // Calculate the three elves with the most calories
    int firstHighestNumber=0;
    int secondHighestNumber=0;
    int thirdHighestNumber=0;
    int c=0;
    while(c<elf) {
        if (totalCalories[c] > thirdHighestNumber) {
            if (totalCalories[c] > secondHighestNumber) {
                if (totalCalories[c] > firstHighestNumber) {
                    secondHighestNumber = firstHighestNumber;
                    thirdHighestNumber = secondHighestNumber;
                    firstHighestNumber = totalCalories[c];
                }
                else {
                    thirdHighestNumber = secondHighestNumber;
                    secondHighestNumber = totalCalories[c];
                }
            }
            else {
                thirdHighestNumber = totalCalories[c];
            }
        }
        c++;
    }

    // Print answers for assignment
    int totalHighestNumber = firstHighestNumber + secondHighestNumber + thirdHighestNumber;
    printf("Most calories elf has %d calories.\n", firstHighestNumber);
    printf("Second most calories elf has %d calories.\n", secondHighestNumber);
    printf("Third most calories elf has %d calories.\n", thirdHighestNumber);
    printf("Three most calories' total is %d calories.\n", totalHighestNumber);

    fclose(file);

    return 0;
}

