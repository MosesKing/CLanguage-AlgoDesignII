/*************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description:  Lab 3
 * **********************************************/
//let's include our libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Let's make our structures
typedef struct student {
	int id;
	char name[20];
	float gpa;
} Student;
// let's make our prototypes for our functions
Student findStudent(FILE* fp, int studentId);
Student* getClass(const char* classFile, const char* studentFile, int* len);
void bubbleSort( Student* students, int len);
void storeClass( const char* filename, Student* students, int len);
void printClass( Student* students, int len);
// Let's begin our main program
int main(int argc, char* argv[]){
/*
 * Main will open the input file and should call findStudent
 * with several differen studentID's and print out the results
 */
	if(argc != 2){
		printf("Insufficient Arguments");
		return 0;
	}
	FILE *fp;
	fp = fopen("student.dat", "wb");
	if(!fp){
		printf("Unable to open file!");
		return 1;
	}
	return 0;
//	const char* classFile =(argv[1]);
}
Student findStudent(FILE* fp, int studentId){
	fseek(fp, studentId * sizeof(Student), SEEK_SET);
	Student ptr;
	fread(&ptr, sizeof(Student), 1, fp);
	return ptr;
}
Student* getClass(const char* classFile, const char* studentFile, int* len){
	FILE *class;
	class = fopen("class.txt", "r");
	if(!class){
		printf("Unable to open file!");
		exit(-1);
	}
	int i;
	int id;
	FILE *student;
	fscanf(class, "%d", len);
	student = fopen("studentFile", "rb");
	if(!student){
		printf("Unable to open file!");
		exit(-1);
	}

	Student *classes = malloc(sizeof(Student) * *len);
	for( i = 0; i <(*(len)); i++){
		fscanf(class, "%d", &id);
		classes[i] = findStudent(student, id);
	}
	return classes;
}
void bubbleSort(Student* students, int len){
/*
	int i;
	int count;
	Student *exmp = malloc(sizeof(char)*1000);

	for( i = -; i < len - 1; i++){
		for(i = 0; i < len - 1; count++){
			if(students(count).gpa > students(count).id){
*/
}
void storeClass(const char* filename, Student* studenta, int len){

}
