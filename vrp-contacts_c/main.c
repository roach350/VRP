/*
	vrp-contacts
	adressbook manager backend for the VRP project
	implmented in C


*/

char *mode, *verb1, *verb2;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "lib/vrp-contacts.h"


void printHelp(){
	printf("vrp-contacts");
	printf("\tVer: %s\n", VRP_VERSION);
	printf("USAGE: ./vrp-contacts <mode> <arguments>\n\n");
	printf("Modes:\n");
	printf("\th\t(display help)\n");  printf("\td\t(run as daemon with no output)\n"); printf("\texport <dir>\t(export contacts to location)\n"); printf("\tlist\t(list all loaded contacts)\n");

}



void test(){


}


int main(int argc, char *argv[]){
	
	if (argc == 1){
		printf("Must supply at least one argument run 'vrp-contacts help' for information.\n");
		return 0;
	}
	switch (argc){
		case 2:
			mode = argv[1];	
			break;
		case 3:
			verb1 = argv[2];
			break;
		case 4:
			verb2 = argv[3];
			break;
	}
	



	if (strncmp(mode, "help", 4) == 0){
		printHelp();
		
	}
	if (strncmp(mode, "test", 4) == 0){
		test();
		
	}
	


	return 0;	
}
