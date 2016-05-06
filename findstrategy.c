#include <stdio.h>
#include <stdlib.h>
#include "findstrategy.h"


/*
 * This function will fun through every index in the array that it is given
 * it will also search every i + 1 indexs and search for the best combination
 * it will save the best combination and return
 */
int* r1(int* prices, int n) {     
  int max = prices[1] - prices[0];
  int i, j;
  int* strategy = malloc(sizeof(int) * 2);
  for(i = 0; i < n; i++)
  {
    for(j = i+1; j < n; j++)
    {        
      if(prices[j] - prices[i] > max) {  
        max = prices[j] - prices[i];
        strategy[0] = i;
        strategy[1] = j;
      }
    }    
  }
  if(prices[strategy[1]] - prices[strategy[0]] < 0){
     strategy[0] = -1; 
  }
  return strategy;
}


/*
 *This function will handle all cases where r > 1
 * it will look for patterns, it the set of prices is going down 
 * it will keep looking until it hits a number where the price goes up
 * it will save that lowest number as a buy day, then it will do the opposite for 
 * sell days. The function will search while the prices are going up and when it hits a 
 * number that is lower than one it previously looked it, it will save the higher number 
 * as a sell day. This will repeat for r times
 */
struct BuySellPair* rPlus(int* prices, int n, int r, int* size) {
    int count = 0;
    struct BuySellPair* strategy = malloc(sizeof(struct BuySellPair) *(n/2 + 1));
    int i = 0;
    while(i < n - 1) {
        while((i < n - 1) && (prices[i + 1] <= prices[i])) {
            i++;
        }
        
        if(i == n - 1) {
            if(count == 0){
                strategy[0].buy = -1;
            }
            break;
        }
        
        strategy[count].buy = i++;
        
        while((i < n) && (prices[i] >= prices[i - 1])) {
            i++;
        }
        
        strategy[count].sell = i - 1;
        
        count++;
        if(count >= r){
            break;
        }
    }
    *size = count;
    return strategy;
            
}