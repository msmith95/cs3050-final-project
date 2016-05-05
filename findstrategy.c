#include <stdio.h>
#include <stdlib.h>
#include "findstrategy.h"

int* r1(int* prices, int n) {     
  int max = prices[1] - prices[0];
  int i, j;
  int strategy[2];
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
  return strategy;
}
struct BuySellPair* rPlus(int* prices, int n) {
    int count = 0;
    
    struct BuySellPair strategy[n/2 + 1];
    int i = 0;
    while(i < n - 1) {
        while((i < n - 1) && (prices[i + 1] <= prices[i])) {
            i++;
        }
        
        if(i == n - 1) {
            break;
        }
        
        strategy[count].buy = i++;
        
        while((i < n) && (prices[i] >= prices[i - 1])) {
            i++;
        }
        
        strategy[count].sell = i - 1;
        
        count++;   
    }
    return strategy;
            
}