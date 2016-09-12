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
 #define assert_with_msg(expression, msg) { \
 	if (!(expression)) { \
 		printf("\x1b[31m%s", msg);\
 		assert(expression);\
 	}\
 }

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
 int totalMoney(Node* node);
 int delete(Node* node, int choice);
 void insert(Node* node, int choice);
 int main(void) {
 	int i;
 	//Generates an input file for you to use
 	//with the numbers [1, 5)
 	const char* filename = "prelab6_input_file.txt";
 	FILE* fp = fopen(filename, "w");
 	for (i = 0; i < 5; i++) {
 		fprintf(fp, "%d\n", i);
 	}
 	fclose(fp);

 	//Calls your build_list function
 	Node* head = build_list(filename);
	totalMoney(head);
	int choice;
	printf("Select a Number you'd like to delete:");
	scanf("%d", &choice);
	printf("\n");
	delete(head, choice);
	totalMoney(head);
	printf("What do you wanna insert?: ");
	int choice2;
	scanf("%d", &choice2);
	insert(head, choice2);
	totalMoney(head);
 	//This code tests your linked list
 	//for correctness. It will check
 	//that each node has the correct
 	//value and free your memory as
 	//it goes along. If the boolean
 	//condition in one of the assert
 	//statements is false then it will
 	//crash your program.
 	for (i = 4; i >= 0; i--) {
 		char msg[100];
 		sprintf(msg, "linked list is to short\ns %d nodes but should be 4\n", 4 - i);
 		assert_with_msg(head != NULL, msg);

 		sprintf(msg, "linked list nodes are not in correct order\nexpected current node to be %d but was actually %d\n", i, head->data);
 		assert_with_msg(head->data == i, msg);
 		Node* prev = head;
 		head = head->next;
 		free(prev);
 	}

 	printf("Congratulations! You finished the prelab!\n");
 	return 0;
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
int totalMoney(Node* node){
	int total = 0;
	while(node->next != NULL){
		total += node->data;
		node = node->next;
	}

	printf("total equals %d\n", total);
return total;
}
int delete( Node* node, int choice){
	Node *current = malloc(sizeof(Node));
	Node *previous = malloc(sizeof(Node));
	Node *temp = malloc(sizeof(Node));
	/* delete first nodes case */
	if (choice == node->data){
		temp = node;
		node = node->next;
		free(temp);
		return choice;
	}
	else{
		previous = node;
		current = node->next;
		while(current != NULL && current->data != choice){
			previous = current;
			current = current->next;
		}
		if(current != NULL){
			temp = current;
			previous->next = current->next;
			free(temp);
			return choice;
		}
	}
	return '\0';
}
void insert(Node* node, int choice){
	Node *New;
	Node *previous;
	Node *current;

	New = malloc(sizeof(Node));

	if( New != NULL){
		New->data = choice;
		New->next = NULL;

		previous = NULL;
		current = node;

		while( current != NULL && choice > current->data){
			previous = current;
			current = current->next;
		}
		if( previous == NULL){
			New->next = node;
			node = New;
		}
		else{
			previous->next = New;
			New->next = current;
		}
	}
	else{
		printf("%c not inserted. No memory available. \n", choice);
	}
}
