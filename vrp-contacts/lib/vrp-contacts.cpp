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
	int number_count = countChar(phone_index, ',') + 1;	
	int comma = 0;
	/*	
		backup phone_index and phone_numbers strings,
		find indexVal and match it with phone_index,
		overwrite indexVal and phone_index strings with a marker char,
		intialize phone_index and phone_numbers,
		copy backups to phone_index and phone_numbers excluding marker chars
		
		TODO: clean up comma logic, fix memory issues		
	*/	
	//backup 
	char phone_numbers_bk[256]; char phone_index_bk[256];
	char test[512];
	// Note some kind of memory issue is present may be related to strcmp, without the presecene of test, phone_index_bk gets overwritten by something.
	strncpy(phone_numbers_bk, phone_numbers, 256);
	strncpy(phone_index_bk, phone_index, 256);

	/* find indexVal */
	int index = 0; //index pointer for phone_index
	int j = 0; // index pointer for tempIndex
	char tempIndex[64];
	initStr(tempIndex, 64);

	//std::cout << "number count: " << number_count << '\n';
	for (int i = 0; i < number_count; i++){

		while (phone_index[index] != ','){
			tempIndex[j] = phone_index[index];
			index++;
			j++;	
		}
		//std::cout << tempIndex << '\n';
		if (strncmp(tempIndex, indexVal, 64) == 0){
	
			/* found indexVal */
			break;
		}else{

			comma++;
		}
		j = 0; index++; initStr(tempIndex, 64);	

	}

	//std::cout << "comma = " << comma << '\n';	
	/* overwrite */
	int comma_temp = 0;
	for (int i = 0; i < 256; i++){

		if (phone_numbers_bk[i] == ','){
			comma_temp++;
			continue;
		}

		if (comma_temp == comma){
			phone_numbers_bk[i] = '#';
		}
		
	}
	comma_temp = 0;
	for (int i = 0; i < 256; i++){
		if (phone_index_bk[i] == ','){
			comma_temp++;
			continue;
		}
		if (comma_temp == comma){
			phone_index_bk[i] = '#';
		}
	
		
	}
	
	/* copy */
	initStr(phone_index, 256);
	initStr(phone_numbers, 256);
	strncmpExclude(phone_index, phone_index_bk, '#', 256);
	strncmpExclude(phone_numbers, phone_numbers_bk, '#', 256);
	std::cout << "Deleted " << indexVal << '\n';
}
int contact_t::delEmail(const char *indexVal){
}



/* easy stuff */
void contact_t::setFirst(const char *first_in){
	strncpy(first, first_in, 64);
} 

void contact_t::setMiddle(const char *middle_in){
	strncpy(middle, middle_in, 64);
}
void contact_t::setLast(const char *last_in){
	strncpy(last, last_in, 64);
}
void contact_t::setNick(const char *nick){
	strncpy(nickname, nick, 64);
}
void contact_t::setTitle(const char *title_in){
	strncpy(title, title_in, 64);
}
void contact_t::setDOB(int d, int m, int y){
	day = d; month = m; year = y;
}
void contact_t::setOrg(const char *org_in){
	strncpy(org, org_in, 64);
}
void contact_t::setNote(const char *note_in){
	strncpy(note, note_in, 1024);
}
void contact_t::setAddress(const char *addr){
	strncpy(address, addr, 256);
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

