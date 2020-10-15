/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "./lib/calc.h"


int main(int argc, char *argv[]){	
	printf("main run\n");
	
	void *handle;
	void (*add)(int, int), (*subtract)(int, int), (*multiply)(int, int), (*divide)(int, int);
	char *error;

	handle=dlopen("./lib/libtest.so", RTLD_LAZY);
	if(!handle){
		fputs(dlerror(), stderr);
		exit(1);
	}
	
	add=dlsym(handle,"add");
	if((error=dlerror())!=NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}

	subtract=dlsym(handle,"subtract");
	if((error=dlerror())!=NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}

	multiply=dlsym(handle,"multiply");
	if((error=dlerror())!=NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}

	divide=dlsym(handle,"divide");
	if((error=dlerror())!=NULL){
		fprintf(stderr, "%s", error);
		exit(1);
	}

	if (!strcmp(argv[2],"+"))	(*add)(atoi(argv[1]), atoi(argv[3]));
	else if (!strcmp(argv[2],"-"))	(*subtract)(atoi(argv[1]), atoi(argv[3]));
 	else if (!strcmp(argv[2],"x"))	(*multiply)(atoi(argv[1]), atoi(argv[3]));
	else if (!strcmp(argv[2],"/"))	(*divide)(atoi(argv[1]), atoi(argv[3]));
	else	printf("wrong\n");
	
	dlclose(handle);
}


