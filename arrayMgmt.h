/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               loadIntFile

*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

struct intArray {
      int *dataArray[];
      int size;
};

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
            printf("The file %s could not be opened.\n", file);
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
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
