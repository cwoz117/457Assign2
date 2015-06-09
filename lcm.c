/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                              File: lcm.c                                   *
*                            Course: CPSC457                                 *
*                            Author: Chris Wozniak                           *
*                               SID: 10109820                                *
*                                                                            *
*          This program is a multi-threaded system that determines the       *
*      lowest common multiple when provided with a file of integers.         *
*      It also allows the user to expand how many threads the                *
*      application is capable of running. If left blank the function         *
*      will default to 3.                                                    *
*                                                                            *
*      EXAMPLE: ./lcm <file-of-ints> <number-of-threads>                     *
*                                                                            *
*      NOTE: Compilation requires both the -pthread and -lm flags for        *
*            linux based machines, as these packages are statically          *
*            undefined by gcc.                                               *
*                                                                            * 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "lcmTable.h"

// Info package for each thread.
struct threadPackage {
      int datBase;
      int datOffset;
      unsigned int subLCD;
      pthread_t tid;
      struct intArray critReg;
};

void lcdFunct(void *arg);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                  Main                                      *
*                                                                            *
*     The main program provided by lcm is our thread generator. We           *
*     take the values provided in the file, and split it into n              *
*     threads to solve. We have some basic error checking to                 *
*     confirm things such as file output.                                    *
*                                                                            *
*     The data management style used was similar to a barrier, where         *
*     each thread was passed a threadPackage struct which defined            *
*     the constraints of what/where the thread was allowed to access.        *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main (int argc, char *argv[]){
      struct intArray data;
      int i, n, range;
      double dividend;
      unsigned int output;

      // Confirm the program was executed with # of params.
      if (argc != 3) {
            printf("Enter a filename, and the number of threads.\n");
            return 0;
      }


      // load the input data into memory
      data = loadIntFile(argv[1]);
      if (data.dataArray == NULL){
            printf("Function loadIntFile did not return an integer array.\n");
            return 0;
      }
      // Divide up data into n groups, and start the thread.
      n = atoi(argv[2]);
      struct threadPackage *tp = malloc (n*sizeof(struct threadPackage));
      dividend = ((float)data.size / n);
      range = ceil(dividend);
      for (i=0; i < n; i++){
	    pthread_t thread;
            tp[i].datBase = i*range;
            tp[i].datOffset = range;
            tp[i].critReg = data;
            tp[i].tid = thread;
            int j = pthread_create(&tp[i].tid, NULL, &lcdFunct, (void *)&tp[i]);
      }
      // Wait for threads to end computation
      for (i = 0; i < n; i++){
            pthread_join(tp[i].tid, NULL);
      }
      // Return values into the final struct to compute
      unsigned int last[n];
      for (i = 0; i < n; i++){
            last[i] = tp[i].subLCD;     
      }
      // wrap the returned values in an intArray struct
      struct intArray a;
      a.dataArray = last;
      a.size = n;

      // Find the final LCM
      output = lcm(a);

      // Reset output since pass by reference
      for (i = 0; i < n; i++){
            last[i] = tp[i].subLCD;     
      }
	
      // Formatted output
      for (i = 0; i < n; i++){
            printf("thread %u: \t",tp[i].tid);
	    printIntArray(tp[i].critReg, tp[i].datBase, tp[i].datOffset, data.size);
	    printf(", LCM = %u\n", tp[i].subLCD);
      }
      printf("Last Pass: %u: \t",tp[i].tid);
      printIntArray(a, 0, a.size, a.size);
      printf(", LCM = %u\n", output);
      printf("Final LCM: %u\n", output);


      return 1;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               lcdFunct                                     *
*                                                                            *
*     lcdFunct is the primary function that defines what a specific          *
*     thread is doing. After organizing data from the                        *
*     critical-region defined in its threadPackage, the function             *
*     finds the LCD of its assigned valules.                                 *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void lcdFunct(void *arg){
      struct threadPackage *t = arg;
      int j;
      int k = 0;
      unsigned int subArray[t->datOffset];
      // Load your threads dividend of the work.
      for (j = t->datBase; j < (t->datBase + t->datOffset); j++){
            if (j < t->critReg.size){
                  subArray[k] = t->critReg.dataArray[j];
                  k++;
            }
      }
      // Struct wrapper so we could use lcm
      struct intArray tmp;
      tmp.dataArray = subArray;
      tmp.size = k;

      // Find the LCD
      t->subLCD = lcm(tmp);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
