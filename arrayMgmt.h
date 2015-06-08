/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                              File: arrayMgmt.h                             *
*                            Course: CPSC457                                 *
*                            Author: Chris Wozniak                           *
*                               SID: 10109820                                *
*                                                                            *
*              This module contains functions used for loading data          *
*              from files into structures to provide similar String          *
*              functionality that the <string.h> module provides.            *
*                                                                            *
*              NOTE: Module is incomplete, functions and structs are         *
*                    included as-needed for assignments.                     *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <stdlib.h>

struct intArray {
      int size;
      unsigned int *dataArray;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               loadIntFile                                  *
*                                                                            *
*              The loadIntFile function loads a file from memory and         *
*              turns them into an array of integers, stored in the           *
*              struct to also provide a size modifier.                       *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct intArray loadIntFile(char file[]){
      struct intArray a;
      a.size = 1000;
      a.dataArray = (int *)malloc(a.size*sizeof(int));
      int i = 0;
      char buf[16];
      // open and confirm we have the file
      FILE *fd = fopen(file, "r");
      if (fd == NULL){
            printf("The file %s could not be opened.\n", file);
            return;
      }
      // read from the file, expanding memory as required.
      while (fscanf(fd, "%s", buf) != EOF){
            a.dataArray[i] = atoi(buf);
            if ( i > a.size){
                  
                  // double the size of the array if the ary is full.
                  struct intArray tmp; 
		  tmp.size = a.size * 2;
		  tmp.dataArray = realloc(a.dataArray, tmp.size *sizeof(int));
		  
                  // if the array could not be doubled, exit.
		  if(tmp.dataArray == NULL){
			printf("realloc could not expand the size of the array\n");
		        exit(0);
		  } else {
			free(a.dataArray);
			a.dataArray = tmp.dataArray;
			a.size = tmp.size;
		  }
            }
            i++;
      }
      // strip away any extra memory.
      a.size = i;
      a.dataArray = realloc(a.dataArray, i*sizeof(int));
      close(fd);
      return a;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               loadIntFile                                  *
*                                                                            *
*              The loadIntFile function loads a file from memory and         *
*              turns them into an array of integers, stored in the           *
*              struct to also provide a size modifier.                       *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printIntArray(struct intArray ia, int base, int offset){
	int i;
	printf("{");
	for (i=base; i < offset-1; i++){
		printf("%d, ", ia.dataArray[i]);
	}
	printf("%d}",ia.dataArray[offset-1]);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
