#include "vrp-contacts.h"
#include <cstring>



/* vrp-contacts */

void contact_t::addNumber(const char *numb, const char *indexVal){
	// check current number list and index list
	// append if space is avalible

}
void contact_t::addEmail(const char *email, const char *indexVal){
}


void contact_t::delNumber(const char *indexVal){
	

}
void contact_t::delEmail(const char *indexVal){
}



/* easy stuff */
void contact_t::setFirst(const char *first_in){
	strcpy(first, first_in);
} 

void contact_t::setMiddle(const char *middle_in){
	strcpy(middle, middle_in);
}
void contact_t::setLast(const char *last_in){
	strcpy(last, last_in);
}
void contact_t::setNick(const char *nick){
	strcpy(nickname, nick);
}
void contact_t::setTitle(const char *title_in){
	strcpy(title, title_in);
}
void contact_t::setDOB(int d, int m, int y){
	day = d; month = m; year = y;
}
void contact_t::setOrg(const char *org_in){
	strcpy(org, org_in);
}
void contact_t::setNote(const char *note_in){
	strcpy(note, note_in);
}
void contact_t::setAddress(const char *addr){
	strcpy(address, addr);
}


int contact_t::numberCount(){
}
int contact_t::emailCount(){
}

char* contact_t::getNumber(const char *indexval){
}
char* contact_t::getEmail(const char *indexval){
}


char* contact_t::getFirst(){
	return first;
}
char* contact_t::getMiddle(){
	return middle;
}
char* contact_t::getLast(){
	return last;
}
char* contact_t::getTitle(){
	return title;
}
char* contact_t::getNick(){
	return nickname;
}
int contact_t::getD(){
	return day;
}
int contact_t::getM(){
	return month;
}
int contact_t::getY(){
	return year;
}
char* contact_t::getOrg(){
	return org;
}
char* contact_t::getNote(){
	return note;
}
char* contact_t::getAddress(){
	return address;
}

