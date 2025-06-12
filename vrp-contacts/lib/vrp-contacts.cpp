#include "vrp-contacts.h"
#include <cstring.h>



/* vrp-contacts */
void contact_t::setFirst(const char *first_in){
	strcpy(first, first_in);
} 

void contact_t::delNumber(const char *indexVal){
	

}
void contact_t::delEmail(const char *indexVal){
}
void contact_t::addNumber(const char *numb, const char *indexVal){
	

}
void contact_t::addEmail(const char *email, const char *indexVal){
}
void contact_t::setMiddle(const char *middle_in){
}
void contact_t::setLast(const char *last_in){
}
void contact_t::setNick(const char *nick){

}
void contact_t::setTitle(const char *title_in){
}
void contact_t::setDOB(int d, int m, int y){
}
void contact_t::setOrg(const char *org_in){
}
void contact_t::setNote(const char *note_in){
}
void contact_t::setAddress(const char *addr){
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
}
char* contact_t::getMiddle(){
}
char* contact_t::getLast(){
}
char* contact_t::getTitle(){
}
char* contact_t::getNick(){
}
int contact_t::getD(){
}
int contact_t::getM(){
}
int contact_t::getY(){
}
char* contact_t::getOrg(){
}
char* contact_t::getNote(){
}
char* contact_t::getAddress(){
}

