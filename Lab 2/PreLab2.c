/*************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Pre Lab for Lab 2 beginning our
 *                 work with structs this
 *              program will focus on song names
 *                       in a jukebox
 * **********************************************/
// let's include our libraries first
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// setting the largest valid size of a song name
#define MAXNAMESIZE 20
//let's define a struct for our program
typedef struct song{
	char name[MAXNAMESIZE];
	int rating;
	int numTimesPlayed;
} Song;
//let's build our prototypes now!
Song* readAlbum(const char* filename, int* lenPtr);
  /*
   * readAlbum will attempt to read a list of songs
   * from a file. the first line of the file will be
   * number of songs it contains. See below for sample
   * input.
   */
void printAlbum(Song* album, int len);
 /*
    this function will print each song in the array
  */

// let's begin our main program now!
int main (int argc, char* argv[]){
/* Main will read in the input file as a command line
   argument, call readAlbum and then call printAlbum.
 */
	if(argc != 2){
		printf("insufficient number of functions\n");
		return 0;
	}
	const char* filename = argv[1];
	int len = 0;
	int* lenPtr = &len;
	Song* album = readAlbum(filename, lenPtr);
	printAlbum(album, len);

//extra stuff
	printf("We're going to change 'Roses to guns'.\n");
	Song secondSong = album[1];
	printf("Before: %s %d %d\n", secondSong.name, secondSong.rating, secondSong.numTimesPlayed);
	strcpy(secondSong.name, "Guns");
	printf("After: %s\n", secondSong.name);

	secondSong.rating = 0;
	printf("%s %d %d\n", secondSong.name, secondSong.rating, secondSong.numTimesPlayed);

	printf("%s %d %d\n", album[1].name, album[1].rating, album[1].numTimesPlayed);

		free(&album[0]);
	return 0;
}
Song* readAlbum(const char* filename, int* lenPtr){
	FILE *cfptr = fopen(filename, "r");
	if( (cfptr) == NULL){
	       exit(1);
	}
	fscanf(cfptr, "%d", lenPtr);
	Song *array = malloc((*lenPtr) * sizeof(Song));
	int i = 0;
	for( i = 0; i < (*lenPtr); i++){
		fscanf(cfptr,"%s%d%d", array[i].name, &array[i].rating, &array[i].numTimesPlayed);
	}
	fclose(cfptr);
	return array;
}
void printAlbum(Song* album, int len){
	int i;
	for( i = 0; i < len; i++){
		printf("%s %d %d\n", album[i].name, album[i].rating, album[i].numTimesPlayed);
	}
}
