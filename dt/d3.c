#include <stdio.h>
#include <string.h>

//int letterInt(char a);

int main(){
	FILE *textfile = fopen("input.txt", "r");

    char line[60] = {0};

    char word[3][60] = {0};


    int i = 0;
    while(fgets(line, 60, textfile)){
        line[strcspn(line, "\n")] = 0;
        memset(word[i], 0, 60);
        strcpy(word[i],line);

        //printf("Line:    %s\n",line);
        //printf("Word[%d]: %s\n",i,word[i]);

        if(i >= 2) {
            size_t len = strlen(word[0]);
            printf("length of word0: %ld\n",len);
            for(int c = 0; c < len-1; c++){
                //char firstChar = word[0][c];
                char *firstChar[2] = {0};
                firstChar[0] = "t";
                char *isInWord1 = strpbrk(firstChar[0], word[1]);
                printf("Letter: %c\n", isInWord1[0]);
                //char isInWord2 = *strpbrk(word[2],&firstChar);

                /*
                if(isInWord1 == NULL || isInWord2 == NULL){
                    fins ikke bokstaven i begge.
                }else{
                    bokstaven fins i begge-
                }
                */
            }
            i=0;
        }
        else {
            i++;
        }
    }


    return 0;
}

int letterInt(char a){
    int result;

    if(a >= 'a' && a <= 'z'){
        result = a - 96;
    }else if(a >= 'A' && a <= 'Z'){
        result = a - 38;
    }
    return result;
}

