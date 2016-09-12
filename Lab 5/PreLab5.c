/**********************************************************
*
* Name: Moesaeah King
*
* ID: 16150318
*
* Description: Working on Structs and Enums. Pre-Lab 5
**********************************************************/
// let's include our libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Forming my structs now!!
typedef enum{
  PENNY = 1,
  NICKEL = 5,
  DIME = 10,
  QUARTER = 25,
} Denomination;
typedef struct{
  Denomination denomination;
  int quantity;
} Coin;
// making our Piggy Bank ヽ(｀(00)´)ノ
typedef Coin* PiggyBank;
// Protoypes for the functions this program will make!!
PiggyBank loadbank(const char* filename, int* lenPtr);
/*
This function will read a list of coins into a Piggy Bank. The first line is
the number of records in the array. The rest of the lines will contain two
numbers, the number type of coin in cents and the second is the quantity.
An example file is given in the lab document
*/
int totalMoney(PiggyBank bank, int length);
/*
Main will open the input file and should call loadBank and then find the total
amount of money.
*/

// let's begin our main program now!!
int main(int argc, char* argv[]){

/*
Main will open the input file and should call loadBank and then find the total
amount of money
*/
  if(argc != 2){
    printf("I'm sorry we couldn't find the Piggy because you either brought too many, or don't have enough arguments!\n\n Goodbye!!");
    return 0;
  }
  int* lenPtr = 0;
  //scanning in the length and malloc the size
  lenPtr = malloc(sizeof(int) * 4);

  Coin *piggybank = loadbank(argv[1], lenPtr);
  int total= totalMoney(piggybank, *(lenPtr));
  printf("You have %d cents\n", total);

  return 0;
}
PiggyBank loadbank(const char* filename, int* lenPtr){
  FILE *cfptr = fopen(filename, "r");
  if( (cfptr) == NULL){
    printf("Unable to Open this File!\n");
    return 0;
  }

  fscanf(cfptr, "%d", lenPtr);
  Coin *piggybank = malloc(sizeof(Coin*)* *lenPtr);
  //counters
  int i;
  // scanning and storing our coins in the piggybank
  for (i = 0; i < *(lenPtr); i++){
    fscanf(cfptr, "%u %d", &(piggybank+i)->denomination, &(piggybank + i)->quantity);
  }
  fclose(cfptr);
  return piggybank;
}
int totalMoney(PiggyBank bank, int length){
  int i;
  int total = 0;
  for (i= 0; i < length; i++){
    total += bank[i].denomination * bank[i].quantity;
  }

  return total;
}
