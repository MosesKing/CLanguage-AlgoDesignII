/**********************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Pre Lab 6
 *********************************************/
 #include <stdlib.h>
 #include <stdio.h>
 #include <assert.h>
 #include <string.h>
  typedef struct node_ {
 	int data;
 	struct node_* next;
 } Node;

 /*
  * Parameters:
  * filename - The name of an input file
  *
  * Return: The head of a linked list
  *
  * This function will build a linked list
  * from the numbers in the input file.
  * Unlike previous weeks, the length of
  * this file is UNKNOWN. Every number
  * in the file should be included in
  * the linked list.
  */
 Node* build_list(const char* filename);

 /*
  * Because this is your first exposure to
  * linked lists, test code has been provided.
  * After implementing build_list, simply run
  * ./a.out and if you can get the message at
  * the bottom to print you are finished.
  */
 void print_list(Node* node);
 void multiply_by(Node* node, int value);
 void free_list(Node* node);
 Node* reverse_list(Node* node);
 int main(int argc, char* argv[]){

/*
Main will open the input file and should call loadBank and then find the total
amount of money
*/
  if(argc != 2){
    printf("I'm sorry we couldn't find the Piggy because you either brought too many, or don't have enough arguments!\n\n Goodbye!!");
    return 0;
  }
  Node* node = build_list(argv[1]);
  print_list(node);
  int value;
  printf("Enter a number to multiply be: ");
  scanf("%d",&value);
  multiply_by(node, value);
  print_list(node);
  Node* reverse;

  reverse = reverse_list(node);
  print_list(reverse);
  free_list(node);
  free_list(reverse);




 return 0;
 }



 void print_list(Node* node){
	 while(node != NULL){
		 printf("%d->", node->data);

		 node = node->next;
	}
	if(node == NULL){
		 printf("NULL\n");
	}

}

 Node* build_list(const char* filename) {
    Node* first;    // first node
    Node* current; //current node

    FILE *cfptr = fopen(filename, "r");
    if( cfptr == NULL){
	    printf("Can't Open the File");
	    return 0;
    }
    first = NULL;
    while(1){
	    current = malloc(sizeof(Node));
	    fscanf(cfptr, "%d", &current->data);
	    if(feof(cfptr)){
		    break;
	    }
	    current->next = first;
	    first = current;
    }
    fclose(cfptr);
    return first;
 }
void multiply_by(Node* node, int value){
	while(node != NULL){
		node->data *= value;

		node = node->next;
	}
}
void free_list( Node* node){
	Node* temp;
	while(node != NULL){
		temp = node;
		node = node->next;
		free(temp);
	}

}
Node* reverse_list(Node* node){

	Node *temp, *temp1, *var;
	temp = node;
	var = NULL;
	while(temp != NULL){
		temp1 = var;
		var = temp;
		temp = temp->next;
		var-> next = temp1;
	}
	node = var;



	/*Node* previous = NULL;
	Node* current = node;
	Node* next;
	while(current != NULL){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	node = previous;
	*/

	return node;
}
