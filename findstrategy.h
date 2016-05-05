/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   if_r_is_one.h
 * Author: Carmichael
 *
 * Created on May 4, 2016, 7:10 PM
 */

#ifndef FINDSTRATEGY
#define FINDSTRATEGY

#ifdef __cplusplus
extern "C"
    
#endif

struct BuySellPair {
    int buy;
    int sell;
};

int* r1(int arr[], int arr_size);
struct BuySellPair* rPlus(int* prices, int n);


#ifdef __cplusplus

#endif

#endif /* IF_R_IS_ONE_H */

