all:
	gcc lcm.c lcmTable.h arrayMgmt.h -pthread -lm -o lcm
