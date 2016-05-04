#include <stdio.h>
#include <stdlib.h>

int* readfile(char* filename, int size){
    FILE* file=fopen(filename, "r");
    if(file == NULL){
        return NULL;
    }
    
    char num[30];
    char buffer[30];
    int* days = malloc(sizeof(int)*size);
    int d = 0;
    
    while(fgets(buffer, 30, file) != NULL){
        int j = 0;
        int i = 0;
        for(i; i<strlen(buffer)-1; i++){
             if(isdigit(buffer[i]) > 0 || buffer[i] == '0'){
                  num[j] = buffer[i];
                    j++;
             }else{
                 return NULL;
             }
        }
        num[j] = '\0';
        days[d] = atoi(num);
        d++;
        
    }
    return days;
}