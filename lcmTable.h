/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               lcdFun

*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "arrayMgmt.h"

unsigned int lcm(struct intArray *ia){
      struct intArray primeArray = loadIntFile("primes.txt");
      unsigned int val = 1;
      int j = 0;
      int currentPrime = pa->dataArray[j];
      int i;
      bool currentPrimeRemains = FALSE;
      bool allValuesReduced = FALSE;

      // If we have an array with values greater than 1
      while (! allValuesReduced){
            // Loop through the array
            for (i = 0; i < ia->size; i++){
                  // if the value is not one
                  if (ia->dataArray[i] != 1){
                        // AND is divisible by the current prime number
                        if (ia->dataArray[i] % currentPrime == 0){
                              // We use the same prime again, and divide the
                              // result.
                              currentPrimeRemains = TRUE;
                              ia->dataArray[i] = ia->dataArray[i] / currentPrime;
                        }
                  }
            }
            // If the current prime needs to be reused
            if (currentPrimeRemains){
                  val = val * (unsigned int)currentPrime;
                  currentPrimeRemains = FALSE;
            } else {
                  // Otherwise, are we done?
                  if (allValuesReduced){
                        return val;
                  } else {
                        // Not done but non-reduced values means we
                        // step to the next prime and continue.
                        j++;
                        currentPrime = primeArray[j];
                        currentPrimeRemains = TRUE;
                  }
            }
      }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
