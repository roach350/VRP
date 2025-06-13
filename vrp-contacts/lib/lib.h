
void initStr(char *str, int len){
	/* initiate a string with a series of null terminators */
	for (int i = 0; i < len; i++){
		str[i] = 0;
	}
}


int countNonZero(char *str, int len){
	int count = 0;
	for (int i = 0; i < len; i++){
		if (str[i] != 0){
			count++;
		}
	}
	return 0;
	
}


void appendStr(char *base, const char *addition, int index){

	int len = strlen(addition); //length of string to add
	len += index; //where to end
	// len - index = where to end - where to start 

	for (int i = 0; i < len - index; i++){

		if (i == 0){
			base[i] = ':';
		}else{
			base[index + i] = addition[i];
		}
	}


}
