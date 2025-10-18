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

#include "vrp-contacts.h"
#include "database.h"

void printHelp(){
	printf("vrp-contacts");
	printf("\tVer: %s\n", VRP_VERSION);
	printf("USAGE: ./vrp-contacts <mode> <arguments>\n\n");
	printf("Modes:\n");
	printf("\th\t(display help)\n");  printf("\td\t(run as daemon with no output)\n"); printf("\texport <dir>\t(export contacts to location)\n"); printf("\tlist\t(list all loaded contacts)\n");

}



void test(){

	struct contact_t t;
	contact_init(&t);
	contact_set_name(&t, 0, "Malcolm","Harold McPherson","MeirBachtol");

	contact_set_nick(&t, "The Cream");
	contact_set_title(&t, "Masterbator");
	contact_set_DOB(&t, 9, 6, 1969);
	contact_set_org(&t, "The Crips");
	contact_set_note(&t, "If Bill Gates gets a .44 magnum, shoves it in his mouth, and blows his brains out the back of his head live on air, Alex Jones will follow suit the next day; also live on air. Challenge can also be completed by dumping a bucket of gasoline onto oneself (akin to the ALS ice bucket challenge), strapping TNT onto your body, and lighting yourself on fire.");
	contact_set_address(&t, "6121 Gold Ct SW, Tumwater, WA 98512");

	contact_add_number(&t, "+1-(350)-454-8100", "mobile");
	contact_add_number(&t, "+1-(360)-403-RTFM", "pager");
	contact_add_number(&t, "+1-(360)-420-6967", "drug phone");

	contact_add_email(&t, "m.cream@hotmail.com", "work");

	contact_add_email(&t, "going.down.on.eaton.for.columbine@msn.com", "personal");

	contact_print(&t);
	contact_free(&t);

	struct contact_database_t test_db;
	database_contact_init(&test_db, "test.db");
	database_contact_load(&test_db);

	
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
