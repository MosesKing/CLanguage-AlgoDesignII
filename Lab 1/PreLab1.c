/*****************************************
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Pre Lab 1 for 2050
 * ***************************************/
// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototypes
int* read_file(char* filename, int len);
/*
  This function will attempt to ope the file provided.
  The file will contain len number of numbrs. It will
  then malloc an array of appropriate size and fill it
  with the numbers in the file.
 */

void print_array(int* array, int len);
/*
  This function will iterate through the provided array
  and print each of the values to the screen
 */

void write_data(char* filename, int* array, int len);
/*
 This function will write stuff onto a .txt file
*/

// our main program
int main( int argc, char* argv[]){
    //check for enough arguments
    if(argc != 3){
	printf("Insufficient Arguments");
	return 0;
    }
    //set our variables to the things located in the arguments
    //---> ask about this:    int* len = malloc(atoi(argv[1]) * sizeof(int));
    //int filename = malloc(atoi(argv[2]) * sizeof(int));
    //now check dat???
    int* array;
    array = read_file(argv[2], atoi(argv[1]));
    int len = atoi(argv[1]);
    //call our functions
    print_array(array,len);
    write_data(argv[2], array, len);
}
int *read_file(char* filename, int len){
    FILE *cfptr = fopen(filename, "r");
    if( (cfptr) == NULL){
	exit(1);
    }
    int* array = malloc(len * sizeof(int));
    int i = 0;
    for( i = 0; i < (len); i++){
	fscanf(cfptr,"%d",  &array[i]);
    }
    fclose(cfptr);
    return array;
}
void print_array(int* array, int len){
    int  i;
    for( i = 0; i <(len); i++){
	printf("%d", *(array + i));
    }
}
void write_data(char* filename, int* array, int len){
  FILE *cfptr = fopen(filename, "w");
  int i = 0;
  for(i = 0; i < (len); i++){
	fprintf(cfptr, "%d", &array[i]);
  }
  fclose(cfptr);
}
