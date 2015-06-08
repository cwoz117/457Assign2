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

struct intArray {
      int *dataArray[];
      int size;
};
struct threadPackage {
      int datBase;
      int datOffset;
      unsigned int subLCD;
      struct intArray critRegion;
};

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

}
int gcdr(int m, int *n[]){
      int tmp;

}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               loadIntFile

*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct intArray loadIntFile(char *file){
      FILE fd;
      int *dat[] = (int *)malloc(10*sizeOf(int));
      int i = 0;

      // open and confirm we have the file
      FILE fd = fopen(file, "r");
      if (input == NULL){
            printf("The file name requested could not be opened.\n");
            return NULL;
      }

      // read from the file, expanding memory as required.
      while (fscanf(fd, "%d", dat[i]) != EOF){
            i++;
            if ( i > strlen(dat)){

                  // double the size of the array if the ary is full.
                  dat = realloc(dat, strlen(dat)*2);
            }
      }
      // strip away any extra memory.
      dat = realloc(dat, i);
      close(fd);

      struct intArray a;
      a->dataArray = dat;
      a->size = i;
      return a;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               Main

*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main (int argc, char *argv[]){
      struct intArray data;
      int i, n, range;

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
            ptthread_t thread;
            pthread_create(&thread, NULL, lcdFun, (void *)t);
            i++;
      }

      // Give the separate lists to the thread, and have it process.


      // Return values into the final struct to compute


      // output



      return 1;
}










/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
