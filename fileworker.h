/* 
 * File:   fileworker.h
 * Author: Michael
 *
 * Created on May 5, 2016, 8:39 PM
 */

#ifndef FILEWORKER_H
#define	FILEWORKER_H

#ifdef	__cplusplus
extern "C" {
#endif

int* readfile(char* filename, int size);
void printFileR2(char* filename, struct BuySellPair* days, int size);
void printFile(char* filename, int* tradeDays, int size);


#ifdef	__cplusplus
}
#endif

#endif	/* FILEWORKER_H */

