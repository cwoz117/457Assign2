/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                              File: lcmTable.h                              *
*                            Course: CPSC457                                 *
*                            Author: Chris Wozniak                           *
*                               SID: 10109820                                *
*                                                                            *
*             This module contains the primary support functions             *
*             for the 'table' method of finding the LCM of a list            *
*             of integers. Unsigned integers are used for output.            *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "arrayMgmt.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               lcm                                          *
*                                                                            *
*              lcm follows the method found on the assignment                *
*              which describes a 'table method' for determining              *
*              the lowest common multiple found in the following             *
*              link:                                                         *
*              http://wikipedia.org/wiki/least_common_multiple               *
*                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
unsigned int lcm(struct intArray ia){
      struct intArray primeArray = loadIntFile("primes.txt");
      unsigned int val = 1;
      int j = 0;
      int currentPrime = primeArray.dataArray[j];
      int i;
      int currentPrimeRemains = 0;
      int allValuesReduced = 0;

      // If we have an array with values greater than 1
      while (! allValuesReduced){
	    allValuesReduced = 1;
	    currentPrimeRemains = 0;
            // Loop through the array
            for (i = 0; i < ia.size; i++){
                  // if the value is not one
                  if (ia.dataArray[i] != 1){
                        // AND is divisible by the current prime number
                        if (ia.dataArray[i] % currentPrime == 0){
                              // We use the same prime again, and divide the
                              // result.
                              currentPrimeRemains = 1;
                              ia.dataArray[i] = ia.dataArray[i] / currentPrime;
                        } else {
				allValuesReduced = 0;
			}
                  }
            }
            // If the current prime needs to be reused
            if (currentPrimeRemains){

                  val = val * (unsigned int)currentPrime;
                  currentPrimeRemains = 0;
		  allValuesReduced = 0;
            } else {
                  // If we're not done
                  if (!allValuesReduced){
                        // non-reduced values means we step
                        // to the next prime and continue.
                        j++;
                        currentPrime = primeArray.dataArray[j];
                        currentPrimeRemains = 1;
                  }
            }
      }
      return val;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
