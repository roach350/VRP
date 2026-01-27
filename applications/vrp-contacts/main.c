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

#include "contacts.h"
#include "database.h"

void printHelp(){
	printf("vrp-contacts CLI interface");
	printf("\tVer: %s\n", VRP_VERSION);
	printf("USAGE: ./vrp-contacts <mode> <arguments>\n\n");
	printf("Modes:\n");
		printf("\thelp\t(display help)\n");
		printf("\tlist <contacts.db>\t(load contacts.db and list all entries)\n");
		printf("\tsearch <contacts.db> <key>\t(perform a search operation on contacts.db)\n");
}



void search(const char *filename, const char *key){
	printf("Attempting to load %s\n", filename);

	struct contact_database_t test_db;
	database_contact_init(&test_db, filename);
	database_contact_load(&test_db);


	struct contact_t *ptr = database_contact_search(&test_db, key);

	if (ptr != NULL){
		printf("First found \"%s\" in:\n", key);
		contact_print(ptr);
	}


}

void list(const char *filename){
	printf("Attempting to load %s\n", filename);

	struct contact_database_t test_db;
	database_contact_init(&test_db, filename);
	database_contact_load(&test_db);
	size_t db_size = database_contact_size(&test_db);
	
	for (size_t i = 0; i < db_size; i++){
		contact_print(database_contact_get(&test_db, i));
	}


}


void test(){
	/*
	struct contact_t t;
	contact_init(&t);
	contact_set_name(&t, 0, "Malcolm","H","M");

	contact_set_nick(&t, "The Cream");
	contact_set_title(&t, "Mr");
	contact_set_DOB(&t, 9, 6, 1969);
	contact_set_org(&t, "VRP");
	contact_set_note(&t, "look here look listen");
	contact_set_address(&t, "6121 Gold Ct SW, Tumwater, WA 98512");

	contact_add_number(&t, "+1-(350)-454-8100", "mobile");
	contact_add_number(&t, "+1-(360)-403-RTFM", "pager");
	contact_add_number(&t, "+1-(360)-420-6967", "work");

	contact_add_email(&t, "mhm@hotmail.com", "work");

	contact_add_email(&t, "malcolm@msn.com", "personal");

	contact_print(&t);
	contact_free(&t);
	*/
	struct contact_database_t test_db;
	database_contact_init(&test_db, "test.db");
	database_contact_load(&test_db);
	size_t db_size = database_contact_size(&test_db);
	
	for (size_t i = 0; i < db_size; i++){
		contact_print(database_contact_get(&test_db, i));
	}

	
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
			mode = argv[1];	
			verb1 = argv[2];
			break;
		case 4:
			mode = argv[1];	
			verb1 = argv[2];
			verb2 = argv[3];
			break;

	}
	
	if (argc > 4){
		printf("Invalid argument, run 'vrp-contacts help' for help.\n"); 
	}


	if (strncmp(mode, "help", 4) == 0){
		printHelp();
		return 0;
		
	}
	if (strncmp(mode, "list", 4) == 0){
		list(verb1);
		return 0;
		
	}
	if (strncmp(mode, "search", 6) == 0){
		search(verb1, verb2);
		return 0;
	}

	if (strncmp(mode, "test", 4) == 0){
		test();
		return 0;
	}
	
	printf("Invalid argument, run 'vrp-contacts help' for help.\n");	


	return 0;	
}
