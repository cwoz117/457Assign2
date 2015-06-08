#include "lcmTable.h"

int main(int argc, char *argv[]){
	int ary[1] = {87780};
	struct intArray test;
	test.dataArray = ary;
	test.size = 1;
	printf("running lcm now:\n");
	unsigned int i = lcm(test);

	printf("%u\n", i);
}
