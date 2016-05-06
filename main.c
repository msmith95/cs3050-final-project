/* 
 * File:   main.c
 * Author: Michael
 *
 * Created on May 4, 2016, 6:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "findstrategy.h"
#include "fileworker.h"
#include "main.h"
#include "input_error.h"

/*
 * 
 */
int main(int argc, char** argv) {

    if(argc != 4){
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    }
    int r =  atoi(argv[2]);
    int n =  atoi(argv[1]);
    int* inputDays = readfile(argv[3], n);
    int* buyselldays;
    int numTrades;
    int i;
    if(inputDays == NULL){
        return -5;
    }
   if(r == 1){
         buyselldays = r1(inputDays, n);
         if(buyselldays[0] == -1){
             printf("No profitable trades found.");
         }else{
             printf("%d\n%d\n", buyselldays[0]+1, buyselldays[1]+1);
         }
         cleanupR1(inputDays, buyselldays);
    }else if(r > 1){
         struct BuySellPair* days = rPlus(inputDays, n, r, &numTrades); 
         int i;
         if(numTrades == 0){
             printf("No profitable trades found.");
         }
         for(i=0; i<numTrades; i++){
             printf("%d\n%d\n", days[i].buy+1, days[i].sell+1);
         }
         cleanupR2(inputDays, days);
    }
    
    return (EXIT_SUCCESS);
}


void cleanupR1(int* input, int* days){
    free(input);
    free(days);
}

void cleanupR2(int* input, struct BuySellPair* days){
    free(input);
    free(days);
}

