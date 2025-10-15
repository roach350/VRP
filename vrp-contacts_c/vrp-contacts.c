/*
	implmentation of vrp-contacts.h

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "config.h"
#include "../lib.h"


#include "vrp-contacts.h"



void contact_init(struct contact_t *c){

	c->contact_titles = (char**)malloc(sizeof(char*) * ENTRIES_PER_CONTACT);	
	c->phone_numbers = (char**)malloc(sizeof(char*) * ENTRIES_PER_CONTACT);
	c->email_titles = (char**)malloc(sizeof(char*) * ENTRIES_PER_CONTACT);	
	c->email_addresses = (char**)malloc(sizeof(char*) * ENTRIES_PER_CONTACT);	


	for (int i = 0; i < ENTRIES_PER_CONTACT; i++){

	
		c->phone_numbers[i] = (char*)malloc(sizeof(char) * ENTRY_LENGTH);
		c->contact_titles[i] = (char*)malloc(sizeof(char) * ENTRY_LENGTH);	
		c->email_titles[i] = (char*)malloc(sizeof(char) * ENTRY_LENGTH);
		c->email_addresses[i] = (char*)malloc(sizeof(char) * ENTRY_LENGTH);
	


	}
	
	for (int i = 0;  i < ENTRIES_PER_CONTACT; i++){
		initStr(c->phone_numbers[i], ENTRY_LENGTH);
		initStr(c->contact_titles[i], ENTRY_LENGTH);
		initStr(c->email_addresses[i], ENTRY_LENGTH);
		initStr(c->email_titles[i], ENTRY_LENGTH);


	}


	c->phone_count = 0;
	c->email_count = 0;
	
}





void contact_free(struct contact_t *c){

	//not enough

	for (int i = 0; i < ENTRIES_PER_CONTACT; i++){

		free(c->contact_titles[i]);	
		free(c->phone_numbers[i]);	
		free(c->email_titles[i]);	
		free(c->email_addresses[i]);	

	}


	free(c->contact_titles);
	free(c->phone_numbers);
	free(c->email_titles);
	free(c->email_addresses);



}




void contact_set_name(struct contact_t *c, int mode, const char *f, const char *m, const char *l){

		
	switch(mode){
	
		case 0:
			//all fields
			strncpy(c->first, f, MAX_NAME_LENGTH);
			strncpy(c->middle, m, MAX_NAME_LENGTH);
			strncpy(c->last, l, MAX_NAME_LENGTH);
			break;
		case 1:
			strncpy(c->first, f, MAX_NAME_LENGTH);
			break;

		case 2: 
			strncpy(c->middle, m, MAX_NAME_LENGTH);
			break;
		case 3:
			strncpy(c->last, l, MAX_NAME_LENGTH);
			break;

	}

}

void contact_set_nick(struct contact_t *c, const char *nick){

	strncpy(c->nickname, nick, MAX_NAME_LENGTH);
}
void contact_set_title(struct contact_t *c, const char *title_in){

	strncpy(c->title, title_in, MAX_NAME_LENGTH);

}
void contact_set_DOB(struct contact_t *c, int d, int m, int y){
	c->day = d;
	c->month = m;
	c->year = y;

}
void contact_set_org(struct contact_t *c, const char *org_in){

	strncpy(c->org, org_in, 64);
}
void contact_set_note(struct contact_t *c, const char *note_in){

	strncpy(c->note, note_in, 1024);
}
void contact_set_address(struct contact_t *c, const char *addr){

	strncpy(c->address, addr, 256);
}



int contact_del_number(struct contact_t *c, int index);
int contact_del_email(struct contact_t *c, const char *index);



int contact_add_email(struct contact_t *c, const char *email, const char *index){

	int i = c->email_count;
	strncpy(c->email_titles[i], index, ENTRY_LENGTH);
	strncpy(c->email_addresses[i], email, ENTRY_LENGTH);
	c->email_count++;

}
		
int contact_add_number(struct contact_t *c, const char *numb, const char *index){
	
	int i = c->phone_count;
	strncpy(c->contact_titles[i], index, ENTRY_LENGTH);
	strncpy(c->phone_numbers[i], numb, ENTRY_LENGTH);
	c->phone_count++;
}









void contact_print(struct contact_t *c){

	printf("CONTACT CARD\n");
	printf("\tNAME: %s %s %s\n", c->first, c->middle, c->last);
	printf("\tNICKNAME: %s\n", c->nickname);
	printf("\tTITLE: %s\n", c->title);
	printf("\tD.O.B. %d/%d/%d\n", c->day, c->month, c->year);
	printf("\tORGINIZATION: %s\n", c->org);
	printf("\tNOTE: %s\n", c->note);
	printf("\tHOME ADDRESS: %s\n", c->address);
	printf("\tPHONE NUMBERS (%d):\n", c->phone_count);
	for (int i = 0; i < (c->phone_count); i++){
		printf("\t\t%s: %s\n", c->contact_titles[i], c->phone_numbers[i]);
	}

	printf("\tEMAIL ADDRESSES (%d):\n", c->phone_count);
	for (int i = 0; i < (c->email_count); i++){
		printf("\t\t%s: %s\n", c->email_titles[i], c->email_addresses[i]);
	}
	printf("END CONTACT CARD\n");

}






