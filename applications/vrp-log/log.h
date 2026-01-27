#ifndef CALL_LOG_H
#define CALL_LOG_H

#include "../../lib/time_stamp.h"

struct call_log_entry_t{

	
	short type; // 0 incoming, 1 outgoing
	time_stamp_t stamp;
	char *phone_number;
	size_t duration; //in seconds
	contact_t *contact;


};



#endif
