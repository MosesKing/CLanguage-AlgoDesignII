/*****************************************
 *
 * Name: Moesaeah King
 *
 * ID; 16150318
 *
 * Description: Lab 2 Program to use Song
 *                and understand structs
 * **************************************/

// let's include our libraries first
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// setting the largest calid size of a song name
#define MAXNAMESIZE 20
// let's define our struct for this program
typedef struct song{
	char name[MAXNAMESIZE];
	int rating;
	int numTimesPlayed;
} Song;
//let's put our prototypes now!
Song* readAlbum(const char* filename, int *lenPtr);
   /*
    * readAlbum will attempt to read a list og songs
    * from a file. the first line of the file will be number of song
    * it contains.
    */
void printAlbum(Song* album, int len);
  /*
   * this function will print each song in the array
   */
int changeRating(char* title, int rating, Song* album, int len);
  /*
   * finds the specified song and updates its rating
   */
int listenToSong(char* title, Song* album, int len);
  /*
   * find the specified song and increments its numTimesPlayed field
   * by one
   */
int main( int argc, char* argv[]){
/* Main will read in the inpur file as a command line argument,
 * call readAlbum and the call print Album.
 * It will the ask the user if hey want to listen to a song or
 * change a ratingand the call the apporpriate funcion. If a
 * song is updated it should be printed out to the console.
 * This will continue until he user decides to quit.
 */
	if(argc != 2){
		printf("insufficient number of functions\n");
		return 0;
	}
	const char* filename = argv[1];
	int len = 0;
	int* lenPtr = &len;
	//calling the functions
	Song* album = readAlbum(filename, lenPtr);
	printAlbum(album, len);
	// making our menu
	printf("-----------------------------\n");
	printf("|         MENU                |\n");
	printf("-----------------------------|\n");
	printf("| Press 1 to Listen to a song|\n");
	printf("| Press 2 to Change a Rating |\n");
	printf("| Press 0 to  Quit           |\n");
	printf("-----------------------------|\n");
	int menuchoice;
	char* title = malloc((MAXNAMESIZE) * sizeof(char));
	int rating;
	int index;
	scanf("%d", &menuchoice);
	// let's make this menu work
	while(menuchoice != 0){
		switch(menuchoice){
			case 0:
				return 0;
				break;
			case 1:
				printf("Enter the title: ");
				scanf("%s", title);
				index = listenToSong(title, album, len);
				if(index ==  -1){
					printf("Unable to find\n");
					break;
				}
				printf("%s %d %d\n", album[index].name, album[index].rating, album[index].numTimesPlayed);
				break;
			case 2:
				printf("Enter the title: ");
				scanf("%s", title);
				printf("Enter Rating: ");
				scanf("%d", &rating);
				index = changeRating(title, rating, album, len);
				if(index == -1){
					printf("Unable to find\n");
					break;
				}
				printf("%s %d %d\n", album[index].name, album[index].rating, album[index].numTimesPlayed);
				break;
			default:
				return 0;
				break;
		}
		printf("Enter a New Choice: ");
		scanf("%d", &menuchoice);
	}
	return 0;
}
Song* readAlbum(const char* filename, int *lenPtr){
	FILE *cfptr = fopen(filename, "r");
	if( (cfptr) == NULL){
		exit(1);
	}
	fscanf(cfptr, "%d", lenPtr);
	Song *array = malloc((*lenPtr) * sizeof(Song));
	int i = 0;
	for( i = 0; i < (*lenPtr); i++){
		fscanf(cfptr, "%s%d%d", array[i].name, &array[i].rating, &array[i].numTimesPlayed);
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
int changeRating(char* title, int rating, Song* album, int len){
	int i;
	for( i = 0; i < len; i++){
		if( strcmp(title, album[i].name) == 0){
			album[i].rating = rating;
			return i;
		}
	}
	return -1;
}
int listenToSong(char* title, Song* album, int len){
	int i;
	for( i = 0; i < len; i++){
		if( strcmp(title, album[i].name) == 0){
			album[i].numTimesPlayed++;
			return i;
		}
	}
	return -1;
}
