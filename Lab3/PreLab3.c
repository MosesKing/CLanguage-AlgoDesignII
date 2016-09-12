/***************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Pre Lab 3
 * *************************************************/
// let's include our libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// let's make our structure
typedef struct student {
	int id;
	char name[20];
	float gpa;
} Student;
// let's make our prototypes for our functions
Student* findStudent(FILE* fp, int studentId);
// let's begin our main program
int main(int argc, char* argv[]){
/*
 * Main will open the input file and should call findStudent
 * with several different studentId's and print out the
 * results.
 */
	if( argc != 2){
		printf("Insufficient Arguments");
		return 0;
	}
	FILE *fp;
	fp = fopen("student.dat","wb");
	if(!fp){
		printf("Unable to open file!");
		return 1;
	}
	int studentId;
	 Student *ptrA  = findStudent(fp, studentId);
	printf("%d %s %lf\n", ptrA->id, ptrA->name, ptrA->gpa);
	return 0;
}
Student* findStudent(FILE* fp, int studentId){
/*
 * The given file contains 5000 students with id's from 1 to
 * 5000 inclusive.Given a studentId you should read the
 * specified student using fseek and fread.
 * This function should not contain any loops.
 */
	fseek(fp, studentId * sizeof(Student), SEEK_SET);
	Student *ptr = malloc(sizeof(Student));
	fread(ptr, sizeof(Student), 1, fp);

	return ptr;
}
