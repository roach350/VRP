/*
	vrp-contatcs
	adressbook manager backend for the VRP project



*/

char *mode, *verb1, *verb2;


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "config.h"
#include "lib/vrp-contacts.h"


void printHelp(){
	std::cout << "vrp-contacts";
	std::cout << "\tVer: " << version_string << '\n';
	std::cout << "USAGE: ./vrp-contacts <mode> <arguments>\n\n";
	std::cout << "Modes:\n";
	std::cout << "\th\t(display help)\n";  std::cout << "\td\t(run as daemon with no output)\n"; std::cout << "\texport <dir>\t(export contacts to location)\n"; std::cout << "\tlist\t(list all loaded contacts)\n";



}



int main(int argc, char *argv[]){
	
	if (argc == 1){
		std::cout << "Must supply at least one argument run 'vrp-contacts help' for information.\n";
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
	



	if (strcmp(mode, "help") == 0){
		printHelp();
		
	}




	return 0;	
}
