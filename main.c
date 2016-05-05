/* 
 * File:   main.c
 * Author: Michael
 *
 * Created on May 4, 2016, 6:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "findstrategy.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int arr[] = {10, 9, 8, 7, 6, 5};
    int* buyselldays;
    buyselldays = r1(arr, 6);
    printf("When r is 1: \n %d\n %d\n~~~~~~~", buyselldays[0] + 1, buyselldays[1] + 1);
    
    struct BuySellPair* days = rPlus(arr, 6);
    printf("When r > 1: \n");
    for (int i = 0; i < 2; i++)
          printf(" %d\n %d\n", days[i].buy + 1, days[i].sell + 1);
    return (EXIT_SUCCESS);
}

