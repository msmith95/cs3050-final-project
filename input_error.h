/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   input_error.h
 * Author: Reiker
 *
 * Created on March 17, 2016, 6:40 PM
 */

#ifndef H_ERRORS_H
#define H_ERRORS_H

/* 
 * These errors should be handled properly by detecting thme and
 * returning the proper status code by calling exit(enum error)
 *
 * NOTE:
 *  The invalid format error should be raised when you encounter lines that  
 *  contain invalid characters or are not properly formatted. This could happen
 *  for example, when a line representing an edge from vertex 4 to vertex 5 with weight 10
 *  is written as (4,5,10 or as 4,5)10 or as 4, 5,10). 
 *  
 */

enum error {
    INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS = 1,
    INVALID_COMMAND_LINE_ARGUMENTS,
    FILE_FAILED_TO_OPEN,
    PARSING_ERROR_INVALID_FORMAT,
    PARSING_ERROR_EMPTY_FILE,
    
};

/*
 * EXAMPLE: If fopen fails to open the file, exit the program with
 * the proper error code in this way:
 * 		exit(FILE_FAILED_TO_OPEN);
 * Check that the code returned is correct by running your
 * program in GDB.  The above example would return exit status 2.
 */ 

#endif

