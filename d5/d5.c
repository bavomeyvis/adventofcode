#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
	FILE *textfile = fopen("input_ole.txt", "r");

    char stack[10][2000] = {'\0'};

    char line[2000];
    int initialStackHeight = 7;

    long instruction[3] = {0};


    int lineInc = 0;

    while(fgets(line, 200, textfile)){
        if(initialStackHeight >= 0){
            for(int i = 1; i <= 9; i++){
                char value = line[(i*4)-3];
                if(line[(i*4)-3] == ' '){
                    value = '\0';
                }
                strncpy(&stack[i][initialStackHeight],&value,1);
            }
            initialStackHeight--;
            for(int i = 1; i <= 9;i++){
               //memset(&stack[i][8],'\0',62);
                strcat(&stack[i],"\0");
            }

        }



        //read numbers from text.
        char * p_line = line;
        int c = 0;
            while(*p_line){
                if(isdigit(*p_line) || ((*p_line=='-' || *p_line=='+') && isdigit(*(p_line+1)))){
                    long val = strtol(p_line,&p_line,10);
                    instruction[c] = val;
                    c++;
                }else{
                    p_line++;
                }
            }
            c = 0;
        if(lineInc >= 10){


            printf("\nInstruction: move %ld from %ld to %ld \n",instruction[0],instruction[1],instruction[2]);
            printf("StackFrom[%ld]: %s\n",instruction[1],stack[instruction[1]]);
            printf("StackTo  [%ld]: %s\n",instruction[2],stack[instruction[2]]);

            size_t fromStackLength = strlen(&stack[instruction[1]]);
            size_t toStackLength = strlen(&stack[instruction[2]]);




            //     PART 2

    /*

            if(fromStackLength > 0){
                printf("From stack length %ld\n",fromStackLength);
                if(instruction[0] > fromStackLength){
                    instruction[0] = fromStackLength;
                }
                strncat(&stack[instruction[2]],&stack[instruction[1]][fromStackLength - instruction[0]],instruction[0]);

                 //memset(&stack[instruction[2]][toStackLength-1],stack[instruction[1]][fromStackLength - 1],2);
                //memset(&stack[instruction[1]][fromStackLength-1],'\0',1);
                stack[instruction[1]][strlen(&stack[instruction[1]])-instruction[0]] = '\0';
                printf("New stack[%ld]: %s\n",instruction[1],stack[instruction[1]]);
                printf("New stack[%ld]: %s\n",instruction[2],stack[instruction[2]]);
            }else{
                printf("Don't move anything over.\n");
            }
    */





    /*         PART 1


            for(int i = 0; i < instruction[0]; i++){
                size_t fromStackLength = strlen(&stack[instruction[1]]);
                size_t toStackLength = strlen(&stack[instruction[2]]);


                if(fromStackLength > 0){
                    printf("From stack length %ld\n",fromStackLength);
                    strncat(&stack[instruction[2]],&stack[instruction[1]][fromStackLength - 1],1);

                    //memset(&stack[instruction[2]][toStackLength-1],stack[instruction[1]][fromStackLength - 1],2);
                    //memset(&stack[instruction[1]][fromStackLength-1],'\0',1);
                    stack[instruction[1]][strlen(&stack[instruction[1]])-1] = '\0';
                    printf("New stack[%ld]: %s\n",instruction[1],stack[instruction[1]]);
                    printf("New stack[%ld]: %s\n",instruction[2],stack[instruction[2]]);
                }else{
                    printf("Don't move anything over.\n");
                }
            }

    */
        }








        lineInc++;
        /*
        if(lineInc > 20){
            break;
        }
        */

        printf("\n");
    }

    //printf("%c",stack[4][1]);
    printf("Stack1: %s\n",stack[1]);
    printf("Stack2: %s\n",stack[2]);
    printf("Stack3: %s\n",stack[3]);
    printf("Stack4: %s\n",stack[4]);
    printf("Stack5: %s\n",stack[5]);
    printf("Stack6: %s\n",stack[6]);
    printf("Stack7: %s\n",stack[7]);
    printf("Stack8: %s\n",stack[8]);
    printf("Stack9: %s\n",stack[9]);


    return 0;
}

