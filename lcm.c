/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                              File: lcm.c                                   *
*                            Course: CPSC457                                 *
*                            Author: Chris Wozniak                           *
*                               SID: 10109820                                *
*                                                                            *
*          This program is a multi-threaded system that determines the       *
*      lowest common multiple when provided with a file of integers.         *
*       It also allows the user to expand how many threads the               *
*       application is capable of running. If left blank the function        *
*      will default to 3.                                                    *
*                                                                            *
*      EXAMPLE: ./lcm <file-of-int> <number-of-threads>                      *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int main (int argc, char *argv[]){
      FILE *input;
      char buffer[32];

      // Confirm the program was executed with # of params.
      if (argc != 2) {
            printf("Enter a filename, and the number of threads.\n");
            return 0;
      }

      // Open the file, and confirm it is loaded.
      input = fopen(arg[1], "r");
      if (input == NULL){
            printf("The file name requested could not be opened.\n");
            return 0;
      }

      // Read the data in from the file.
	while (fscanf(input, "%s", buffer) != EOF ){

	}
      fclose(input);

      // Divide up data into argv[2] groups (mod)
      for (i = 0; i < atoi(argv[3]); i++){

      }

      // Give the separate lists to the thread, and have it process.


      // Return values into the final struct to compute


      // output



      return 1;
}










/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
