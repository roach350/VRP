#ifndef CALL_LOG_DATABASE_H
#define CALL_LOG_DATABASE_H











struct call_log_database_t{

	char name[MAX_NAME_LENGTH];
	char file_name[FILE_NAME_LENGTH];
	size_t db_size;
	short version;
	FILE *fptr;	


};




#endif
