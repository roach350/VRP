#ifndef TIME_STAMP_H
#define TIME_STAMP_H

struct time_stamp_t{

	short month;
	short day;
	short year;
	short hours;
	short minutes;
	short seconds;

};








void time_stamp_set(time_stamp_t *stamp);


#endif
