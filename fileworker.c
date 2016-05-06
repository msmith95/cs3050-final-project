#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "findstrategy.h"
#include "input_error.h"

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
    fclose(file);
    return days;
}

void printFile(char* filename, int* tradeDays, int size){
    FILE* file=fopen(filename, "w");
    if(file == NULL){
        return;
    }
    
    int i;
    if(tradeDays[0]== -1){
        fprintf(file, "%s\n", "No profitable trading solution found");
    }else{
        for(i=0; i<size; i++){
             fprintf(file, "%d\n", tradeDays[i]);
         }
    }
    
    fclose(file);
}

void printFileR2(char* filename, struct BuySellPair* days, int size){
    FILE* file=fopen(filename, "w");
    if(file == NULL){
        return;
    }
    
    int i;
    if(days[0].buy == -1){
        fprintf(file, "%s\n", "No profitable trading solution found");
    }else{
        for(i=0; i<size; i++){
             fprintf(file, "%d\n %d\n", days[i].buy, days[i].sell);
         }
        printf("%d\n", days[0].buy);
        fprintf(file, "%s\n", "End of file");
    }
    
    fclose(file);
}