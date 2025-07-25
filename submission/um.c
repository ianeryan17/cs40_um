/*
        segments.c
        Ian Ryan (iryan01) and Caden Chang (cchang15)
        10/20/23
        HW#6
        Summary: calls program_reader function to get program words from file,
                 and gives program to um with run()
                 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "seq.h"
#include "assert.h"
#include <stdint.h>
#include <bitpack.h>
#include "um_driver.h"
#include "uarray.h"
#include <sys/stat.h>

UArray_T program_reader(char* program);

int main(int argc, char *argv[])
{
        if (argc != 2){
                return EXIT_FAILURE;
        }
        char *program = argv[1];
        UArray_T program_words = program_reader(program);
        if (program_words == NULL){
                fprintf(stderr, "The given file %s was unable to be", program);
                fprintf(stderr, " read as it is not in the proper format.\n");
                fprintf(stderr, "Please try again with a proper .um file.\n");
                return EXIT_FAILURE;
        }
        run(program_words);
        
        return EXIT_SUCCESS;
}

/********** program_reader ********
 * Purpose: opens the given .um file, separates the contents into a 32-bit
            words, inserts them into a UArray and returns the UArray
 * Inputs:  char* program: name of the .um file containing the program      
 * Return:  UArray_T that contains the program in uint32_t words
 * Expects: the given char* to represent a valid .um file
 ************************/
UArray_T program_reader(char* program)
{
        FILE *program_ptr = fopen(program, "r");
        if (program_ptr == NULL){
                return NULL;
        }
        
        /* use stat to find size of um program to size UArray */
        struct stat st;
        stat(program, &st);
        int num_words = (st.st_size)/4;
        UArray_T um_program = UArray_new(num_words, sizeof(uint32_t));
        
        
        char curr_char;
        int counter = 0;
        uint32_t word_holder = 0;
        int index = 0;
        while (fscanf(program_ptr, "%c", &curr_char) == 1) {
                counter++;
                int c_int = curr_char;
                assert(c_int < 256);
                word_holder = (uint32_t)Bitpack_news((uint64_t)word_holder, 8,
                                                      32 - (8 * counter), 
                                                      c_int);
                if (counter == 4){
                        uint32_t new_val = word_holder;
                        *((uint32_t *)UArray_at(um_program, index)) = new_val;
                        counter = 0;
                        word_holder = 0;
                        index++;
                }
        }

        fclose(program_ptr);
        return um_program;
}