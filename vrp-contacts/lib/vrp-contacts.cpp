#include <iostream>
#include <cstring>
#include "vrp-contacts.h"
#include "lib.h"
/* vrp-contacts */


/* consructor */

contact_t::contact_t(){

	initStr(phone_index, 256);
	initStr(phone_numbers, 256);
	initStr(email_index, 512);
	initStr(email_addresses, 512);
	month = 1; day = 1; year = 1970;
	initStr(note, 1024);
	initStr(address, 256);
	initStr(org, 64);
	initStr(title, 64);
	initStr(nickname, 64);		

}

int contact_t::addNumber(const char *numb, const char *indexVal){
	// check current number list and index list
	// append if space is avaliable
	int aval_index_size = 256 - countNonZero(phone_index, 256);
	int aval_number_size = 256 - countNonZero(phone_numbers, 256);
	

	if (strlen(indexVal) < aval_index_size){
		// append index
		appendStr(phone_index, indexVal, strlen(phone_index));
		
	}else{
		return 0; //failure
	}

	if (strlen(numb) < aval_number_size){
		// append index
		appendStr(phone_numbers, numb, strlen(phone_numbers));
		
	}else{
		return 0; //failure
	}

	return 1; //success
	

}
int contact_t::addEmail(const char *email, const char *indexVal){
	// check current number list and index list
	// append if space is avaliable
	int aval_index_size = 256 - countNonZero(email_index, 256);
	int aval_email_size = 256 - countNonZero(email_addresses, 256);
	

	if (strlen(indexVal) < aval_index_size){
		// append index
		appendStr(email_index, indexVal, strlen(email_index));
		
	}else{
		return 0; //failure
	}

	if (strlen(email) < aval_email_size){
		// append index
		appendStr(email_addresses, email, strlen(email_addresses));
		
	}else{
		return 0; //failure
	}

	return 1; //success
	

}


int contact_t::delNumber(const char *indexVal){
	int number_count = countChar(phone_index, ',');	
	
	
}
int contact_t::delEmail(const char *indexVal){
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

/* print */

void contact_t::print(){

	std::cout << "Contact Card\n";
	std::cout << "\tName: " << first << ' ' << middle << ' ' << last << "\n\n";

	std::cout << "\tPhone Index: " << phone_index << '\n';
	std::cout << "\tPhone Numbers: " << phone_numbers << '\n';	
	std::cout << "\tEmail Index: " << email_index << '\n';
	std::cout << "\tEmail Addresses: " << email_addresses << "\n\n";

	std::cout << "\tDate Of Birth: " << month << '/' << day << '/' << year << '\n';
	std::cout << "\tTitle: " << title << '\n';
	std::cout << "\tNickname: " << nickname << '\n';
	std::cout << "\tOrganization: " << org << '\n';


}

