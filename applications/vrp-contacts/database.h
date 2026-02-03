#ifndef DATABASE_H
#define DATABASE_H

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
size_t database_contact_size(struct contact_database_t *db);
struct contact_t *database_contact_get(struct contact_database_t *db, size_t index);
size_t database_contact_search(struct contact_database_t *db, struct contact_t ***search_ptr, const char *key); //make sure to free this pointer after calling it



//struct contact_t *database_contact_fast_search(struct contact_database_t *db, const char *key);

#endif
