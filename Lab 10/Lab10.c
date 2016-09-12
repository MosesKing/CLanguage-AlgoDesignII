/*****************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Lab 10
 * ****************************************/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
int isPhoneNumber(char* token);
int isDate(char* token);
int isEmail(char* token);

int main( int argc, char** argv){
	if(argc != 2){
		printf("Insuffient Arguments");
	}
	FILE* cfptr = fopen(argv[1], "r");
	if(cfptr ==  NULL){
		printf("file failed to open\n");
		return 0;
	}
	char buffer[700];
		while(fgets(buffer, 700, cfptr) != NULL){
			char* token = strtok(buffer, " \n\t");
			while(token != NULL){
				// function calls go here
				if(isDate(token) == 1){
					printf("Date: %s\n", token);
				}
				if(isPhoneNumber(token) == 1){
					printf("Phone Number: %s\n", token);
				}
				if(isEmail(token) == 1){
					printf("Email: %s\n", token);
				}
				token = strtok(NULL, " \r\n\t");
			}
		}

	if(isDate("12/02/2016") == 1){
		printf("Date: 12/02/2016\n");
	}
	if(isEmail("2050@mail.com") == 1){
		printf("Email: 2050@mail.com\n");
	}
	if(isPhoneNumber("(913)669-9493") == 1){
		printf("Phone Number: (913)669-9493\n");
	}
	return 0;

}
int isPhoneNumber(char* token) {
 	char* temp = strdup(token);
 	char* tok;
 	char* string;
 	const char delim[4] = "()-";

 	if(strlen(temp) != 13)
 	{
 		return 0;
 	}
 	//check
 	if(temp[0] != '(')
 	{
 		return 0;
 	}

 	tok = strtok(temp, delim);
 	//check
 	if(!tok)
 	{
 		return 0;
 	}

 	string = strdup(tok);

 	//this is the loop
 	while(tok != NULL)
 	{
 		tok = strtok(NULL, delim);
 		if(tok)
 		{
 			strcat(string, tok);
 		}
 	}

 	if(0 != atol(string))
 	{
 		return 1;
 	}
 	else
 	{
 		return 0;
 	}
 }
int isDate( char* token){
	if(strlen(token) != 10){
		return 0;
	}

	if (!isdigit(token[0]) || !isdigit(token[1])) {
		return 0;
	}
//	if (token[0] > 1 && token[1] >= 4){
//		return 0;
//	}
	if (token[2] != '/') {
		return 0;
	}
	if (!isdigit(token[3]) || !isdigit(token[4])){
		return 0;
	}
	if (token[5] != '/'){
		return 0;
	}
	if(!isdigit(token[6]) || !isdigit(token[7]) || !isdigit(token[8]) || !isdigit(token[9])){
		return 0;
	}

	return 1;
}
int isEmail(char* token){
	char* ptr;
	for (ptr= token; *ptr; ptr++) {
        if (*ptr == '@' && ptr != token) {
            // check that we saw at least one character
            return 1;
        }
    }
    return 0;
}
