#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "findstrategy.h"
#include "input_error.h"

/*
 *This function will take in a file and an array size
 * the data in the file will be saved to an array then returned to be worked with
 * This function will exit with error codes if it encounters any problems or bad data input
 */

int* readfile(char* filename, int size){
    FILE* file=fopen(filename, "r");
    if(file == NULL){
        exit(FILE_FAILED_TO_OPEN);
    }
    
    char num[30];
    char buffer[30];
    int* days = malloc(sizeof(int)*size);
    int d = 0;
    
    while(fgets(buffer, 30, file) != NULL){
        int j = 0;
        int i = 0;
        for(i=i; i<strlen(buffer)-1; i++){
             if(isdigit(buffer[i]) > 0 || buffer[i] == '0'){
                  num[j] = buffer[i];
                    j++;
                    
             }else{
                 free(days);
                 exit(PARSING_ERROR_INVALID_FORMAT);
             }
        }
        num[j] = '\0';
        days[d] = atoi(num);
        d++;
        
    }
    if(d != size){
        free(days);
        exit(INVALID_COMMAND_LINE_ARGUMENTS);
    }
    if(d == 0){
        free(days);
        exit(PARSING_ERROR_EMPTY_FILE);
    }
    int close = fclose(file);
    if(close != 0){
        exit(FILE_FAILED_TO_CLOSE);
    }
    return days;
}