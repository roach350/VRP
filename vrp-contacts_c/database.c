#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../lib.h"


#include "database.h"






void database_contact_init(struct contact_database_t *db, const char *file_name){

	db->db_size = 0;
	initStr(db->file_name, FILE_NAME_LENGTH);
	strncpy(db->file_name, file_name, FILE_NAME_LENGTH);
}


int database_contact_load(struct contact_database_t *db){

	db->fptr = fopen(db->file_name, "r");

	if (db->fptr == NULL){
		printf("Contact Database file: %s could not be opened\n", db->file_name);
		return 0;
	}

	printf("Loading %s\n",db->file_name);
	/* parse the file*/


	//read first line and get version
	char c = 0;

	while(!charIsInt(c)){
		c = fgetc(db->fptr);
	}
	
	db->version = c - '0';
	printf("Contact DB version %d found\n", db->version); 

	fgetc(db->fptr); //advance file pointer
	if (db->version == 1){

		//get next line, number of contacts in file
		char db_size_str[16];
		fgets(db_size_str, 16, db->fptr);
		db->db_size = atoi(db_size_str);
		printf("%d contact(s) found\n", db->db_size);
		

	}else{
		printf("Contact DB version %d is not supported in this version.\n", db->version);
		return 0;
	}



	return 1;

}

