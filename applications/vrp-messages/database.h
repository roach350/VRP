#ifndef DATABASE_H
#define DATABASE_H
/*
	VRP messages database
	must be quick to search when loaded into memory
	
*/


struct messages_database_h{

	char name[MAX_NAME_LENGTH];
	char file_name[FILE_NAME_LENGTH];
	size_t db_size;
	short version;
	FILE *fptr;	


}



#endif
