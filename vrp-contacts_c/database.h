#pragma once
/*
	declerations for functions responsible for opening databases 
*/

#define MAX_NAME_LENGTH 64
#define FILE_NAME_LENGTH 128

struct contact_database_t{

	struct contact_t **contact_ptr;
	char name[MAX_NAME_LENGTH];
	char file_name[FILE_NAME_LENGTH];
	size_t db_size;
	short version;
	FILE *fptr;	


};



/* helper functions */
void database_contact_init(struct contact_database_t *db, const char *file_name);
int database_contact_load(struct contact_database_t *db);
int database_contact_write(struct contact_database_t *db);
int database_contact_copy(struct contact_database_t *db, const char *file_name);



