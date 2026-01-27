#ifndef MESSAGE_H
#define MESSAGE_H

#include "../../lib/time_stamp.h"


/* 
	VRP Messages
		the messaging backend for the vrp project
		based on ModemManager
	
	status:
		sets the status of a message
		0: draft
		1: succesfully recieved
		2: successfully sent
		-1: send failure




*/

struct sms_t{


	struct time_stamp_t time_stamp;
	char *recipient;
	char *sender;
	char *contents;
	short status;

}




struct mms_t{

	char *type;
	struct time_stamp_t time_stamp;
	char *recipient;
	char *sender;
	char *contents;
	short status;
}


#endif
