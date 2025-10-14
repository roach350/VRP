/* 
	defines functions that do operations on the contacts database

*/

#include  "contact_list.h"






struct contact_t{

		/* names */
	char first[64];
	char middle[64];
	char last[64];
	char nickname[64];
	char title[64];
	/*	
		phone numbers
	*/
	char **contact_names; //names	
	char **phone_numbers;
	size_t phone_count;
	/*	
		email addresses
	*/

	char **email_entrees
	char **email_addresses 
	size_t email_count;

		
	/* DOB */
	int day; int month; int year;

	/* other data */
	char org[64]; //organization
	char note[1024]; // note associated
	char address[256]; // home address
		
		
};	

void contact_init(struct contact_t *c);

	
/* setters */



int contact_del_number(struct contact_t *c, int index);
int contact_del_email(struct contact_t *c, const char *indexVal)		
int contact_add_number(struct contact_t *c, const char *numb);
int contact_add_email(struct contact_t *c, const char *email);
void contact_set_first(struct contact_t *c, const char *first_in);
void cotnact_set_middle(struct contact_t *c, const char *middle_in);
void contact_set_last(struct contact_t *c, const char *last_in);
void contact_set_nick(struct contact_t *c, const char *nick);
void contact_set_title(struct contact_t *c, const char *title_in);
void contact_set_DOB(struct contact_t *c, int d, int m, int y);
void contact_set_org(struct contact_t *c, const char *org_in);
void contact_set_note(struct contact_t *c, const char *note_in);
void contact_set_address(struct contact_t *c, const char *addr);

/* getters */
int contact_get_number_count(struct contact_t *c);
int contact_get_email_count(struct contact_t *c);
	
char* contact_get_number(struct contact_t *c, const char *indexVal);
char* contact_get_email(struct contact_t *c, const char *indexVal);	
char* contact_get_first(struct contact_t *c);
char* contact_get_iddle(struct contact_t *c);
char* contact_get_last(struct contact_t *c);
char* contact_get_title(struct contact_t *c);
char* contact_get_nick(struct contact_t *c); 
int contact_get_d(struct contact_t *c,);
int contact_get_m(struct contact_t *c,);
int contact_get_y(struct contact_t *c);
char *contact_get_org(struct contact_t *c);
char *contact_get_note(struct contact_t *c);
char *contact_get_address(struct contact_t *c);
		
/*other*/
void contact_print(struct contact_t *c);




