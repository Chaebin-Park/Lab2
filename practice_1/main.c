/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/calc.h"

int main(int argc, char *argv[]){	
	printf("main run\n");
	if (!strcmp(argv[2],"+"))	add(atoi(argv[1]), atoi(argv[3]));
	else if (!strcmp(argv[2],"-"))	subtract(atoi(argv[1]), atoi(argv[3]));
 	else if (!strcmp(argv[2],"x"))	multiply(atoi(argv[1]), atoi(argv[3]));
	else if (!strcmp(argv[2],"/"))	divide(atoi(argv[1]), atoi(argv[3]));
	else	printf("wrong\n");
}


