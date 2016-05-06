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

/*
 * 
 */
int main(int argc, char** argv) {

    int r =  atoi(argv[2]);
    int n =  atoi(argv[1]);
    char* outputFile = argv[4];
    int* inputDays = readfile(argv[3], n);
    int* buyselldays;
    int numTrades;
    int i;
    if(inputDays == NULL){
        return -5;
    }
   if(r == 1){
         buyselldays = r1(inputDays, n);
         printFile(outputFile, inputDays, 2);
         cleanupR1(inputDays, buyselldays);
    }else if(r > 1){
         struct BuySellPair* days = rPlus(inputDays, n, r, &numTrades); 
         printFileR2(outputFile, days, numTrades);
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

