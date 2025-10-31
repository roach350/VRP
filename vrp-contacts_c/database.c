#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../lib.h"

#include "config.h"
#include "database.h"
#include "vrp-contacts.h"





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
		
		/* allocate memory */
		db->contact_ptr = (struct contact_t **) malloc(sizeof(struct contact_t*) * db->db_size);

		for (int i = 0; i < db->db_size; i++){
			db->contact_ptr[i] = (struct contact_t *) malloc(sizeof(struct contact_t));
			contact_init(db->contact_ptr[i]); //initilize contacts
		}


		while(c != '#'){
			c = fgetc(db->fptr);
		}
		//found #START
		while(c != '\n'){
			c = fgetc(db->fptr);
		}	
		//advance to endline
			
		//start parsing contacts
	
		char first[MAX_NAME_LENGTH];
		char middle[MAX_NAME_LENGTH];
		char last[MAX_NAME_LENGTH];
		char nick[MAX_NAME_LENGTH];
		char title[MAX_NAME_LENGTH];
		char data_entry1[ENTRY_LENGTH];
		char data_entry2[ENTRY_LENGTH];
		for (int i = 0; i < db->db_size; i++){

			printf("Loading contact %d\n", i + 1); 
			//first middle last nickname title
			readLine(first, MAX_NAME_LENGTH, db->fptr);
			readLine(middle, MAX_NAME_LENGTH, db->fptr);
			readLine(last, MAX_NAME_LENGTH, db->fptr);
			readLine(nick, MAX_NAME_LENGTH, db->fptr);
			readLine(title, MAX_NAME_LENGTH, db->fptr);

			printf("found: %s %s %s %s %s\n", first, middle, last, nick, title);
			contact_set_name(db->contact_ptr[i], 0, first, middle, last);
			contact_set_nick(db->contact_ptr[i], nick);
			contact_set_title(db->contact_ptr[i], title);
			//phone numbers
			c = fgetc(db->fptr);
			if (c != '#'){
				printf("Parse error\n");
				return 0;
			}
			fgetc(db->fptr); //advance pointer	
			initStr(data_entry1, ENTRY_LENGTH);
			initStr(data_entry2, ENTRY_LENGTH);
			while(data_entry1[0] != '#'){
				readLine(data_entry1, ENTRY_LENGTH, db->fptr);
				readLine(data_entry2, ENTRY_LENGTH, db->fptr);
				if (data_entry1[0] == '#' || data_entry2[0] == '#'){
					printf("done adding phone numbers\n");
					break;
				}
				
				printf("adding: %s %s\n", data_entry1, data_entry2);
				contact_add_number(db->contact_ptr[i], data_entry2, data_entry1);
				printf("added\n");	

			}


			initStr(data_entry1, ENTRY_LENGTH);
			initStr(data_entry2, ENTRY_LENGTH);
			while(data_entry1[0] != '#'){
				readLine(data_entry1, ENTRY_LENGTH, db->fptr);
				readLine(data_entry2, ENTRY_LENGTH, db->fptr);
				if (data_entry1[0] == '#' || data_entry2[0] == '#'){
					printf("done adding email addresses\n");
					break;
				}
				
				printf("adding: %s %s\n", data_entry2, data_entry1);
				contact_add_email(db->contact_ptr[i], data_entry2, data_entry1);
				printf("added\n");	

			}



		}






		

	}else{
		printf("Contact DB version %d is not supported in this version.\n", db->version);
		return 0;
	}



	return 1;

}

