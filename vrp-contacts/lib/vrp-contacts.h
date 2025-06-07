/* 
	defines functions that do operations on the contacts database

*/




class contact_t{

	private:
		/* names */
		char first[64];
		char middle[64];
		char last[64];
		char nickname[64];
		char title[64];
		/*	
			phone numbers
		 	comma seperated
		*/
		char phone_index[256]; //index data (e.g. mobile, home , etc.)
		char phone_numbers[256]; //the numbers themselves
		/*	
			email addresses
		 	comma seperated
		*/
		char email_index[512]; //index data (e.g. personal, work))
		char email_addresses[512]; //the adresses themselves
		
		/* DOB */
		int day; int month; int year;

		/* other data */
		char org[64]; //organization
		char note[1024]; // note associated
		char address[256]; // home address

	public:
		/* constructors */

		// build simple contact
		contact_t(char *first, char *last);
		
		
		/* setters */
		void delNumber(const char *indexVal);
		void delEmail(const char *indexVal);		
		void addNumber(const char *numb, const char *indexVal);
		void addEmail(const char *email, const char *indexVal);
		void setFirst(const char *first_in);
		void setMiddle(const char *middle_in);
		void setLast(const char *last_in);
		void setNick(const char *nick);
		void setTitle(const char *title_in);
		void setDOB(int d, int m, int y);
		void setOrg(const char *org_in);
		void setNote(const char *note_in);
		void setAddress(const char *addr);

		/* getters */
		int numberCount();
		int emailCount();
		
		/* other */
		char* getNumber(const char *indexVal);
		char* getEmail(const char *indexVal);	
		char* getFirst();
		char* getMiddle();
		char* getLast();
		char* getTitle();
		char* getNick(); 
		int getD();
		int getM();
		int getY();
		char* getOrg();
		char *getNote();
		char *getAddress();
		

		void print();


};



