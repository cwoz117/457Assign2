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
#include "arrayMgmt.h"
#include "lcmTable.h"

struct threadPackage {
      int datBase;
      int datOffset;
      unsigned int subLCD;
      pthread tid;
      struct intArray critRegion;
};

void lcdFun(void *arg);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               Main

*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main (int argc, char *argv[]){
      struct intArray data;
      int i, n, range;
      unsigned int output;

      // Confirm the program was executed with # of params.
      if (argc != 2) {
            printf("Enter a filename, and the number of threads.\n");
            return 0;
      }


      // load the input data into memory
      data = loadIntFile(argv[1]);
      if (data == NULL){
            printf("Function loadIntFile did not return an integer array.\n");
            return 0;
      }

      // Divide up data into n groups, and start the thread.
      n = atoi(argv[2]);
      struct threadPackage tp = malloc (n*sizeOf(threadPackage));
      int range = strlen(tp);
      i = 0;
      range = (data->size / n) + 1;
      while (i < n){
            struct a *t = tp[i];
            t->datBase = i*range;
            t->datOffset = range;
            t->critRegion = data;
            pthread thread;
            t->tid = pthread_create(&thread, NULL, lcdFun, (void *)t);
            i++;
      }

      // Wait for threads to end computation
      for (i = 0; i < n; i++){
            pthread_join(tp[i]->tid, NULL);
      }

      // Return values into the final struct to compute
      unsigned int last[n];
      for (i = 0; i < n; i++){
            last[i] = tp[i]->subLCD;
      }
      struct intArray a;
      a->dataArray = (int)last;
      a->size = n;
      output = lcm(a);

      // output

      return 1;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               lcdFun

*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void lcdFun(void *arg){
      struct threadPackage t = (struct threadPackage)arg;
      int j;
      int k = 0;
      unsigned int subArray[t->datOffset];

      // load your threads dividend of the work.
      for (j = t->datBase; j < (t->datBase + t->datOffset); j++){
            if (j < arg->critRegion->size){
                  subArray[k] = arg->critRegion->dataArray[j];
                  k++;
            }
      }

      // Find the LCD
      arg->subLCD = lcm(t->intArray);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
