/************************************************
*
* Name: Moesaeah King
*
* ID: 16150318
*
* LAB: Section D
*
* Description: Lab 2:
************************************************/
//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototypes
double* read_file(char* filename, int length);
/*
  This function return an array of doubles with 'length' number of elements,
  NULL if the file failed to open
*/
double find_max(double* array, int length);
/*
  This function will return the smallest value in the array
*/
double find_min(double* array, int length);
/*
 This function will return the largest value in the array
*/
double find_avg(double* array, int length);
/*
 This function will return the average of all the values in the array
*/
void write_to_file( char* filename, double* array, int length);
/*
 This function will write the values of the array to the file backwards. so the last item at array[length - 1] will be the first number written to the file, array[ length -2] the second, etc
*/



// our main program
int main ( int argc, char* argv[]){
	if (argc != 4){
		printf("Insufficient Argument");
		return 0;
	}
	//set variables to the things located in the arguments
	double* array;
	array = read_file(argv[2], atoi(argv[1]));
	int length = atoi(argv[1]);
	// printing our stuff
	printf("min: %lf\n",find_min(array, length));
	printf("max: %lf\n", find_max(array, length));
	printf("avg: %lf\n",find_avg(array, length));
	write_to_file(argv[3], array, length);
	// free space that we malloceded
	free(array);
	return 0;
}
double* read_file(char* filename, int length){
	FILE *cfptr = fopen(filename, "r");
	if((cfptr) == NULL){
		exit(1);
	}
	double* array = malloc(length * sizeof(double));
	int i = 0;
	for( i = 0; i < length; i++){
		fscanf(cfptr, "%lf", &array[i]);
	}
	fclose(cfptr);
	return array;
}
double find_max(double* array, int length){
	double max;
	int i = 0;
	max = array[0];
	for(i = 0; i < length; i++){
		if(array[i] > max){
			max = array[i];
		}
	}
	return max;

}
double find_min(double* array, int length){
	double min;
	int i;
	i = 0;
	min = array[0];
	for(i = 0; i < length; i++){
		if ( array[i] < min){
			min = array[i];
		}
	}
	return min;


}
double find_avg(double* array, int length){
	double average;
	int i;
	int sum = 0;
	for(i = 0; i < length; i++){
		sum += array[i];
	}
	average = (float)sum/length;

	return average;
}
void write_to_file(char* filename, double* array, int length){
	FILE *cfptr = fopen(filename, "w");
	int i = 0;
	for(i = 0; i < length; i++){
		fprintf(cfptr, "%lf", array[i]);
	}
	fclose(cfptr);
}
