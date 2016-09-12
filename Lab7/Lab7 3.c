#include <stdlib.h>
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct node_ {
	int data;
	struct node_* next;
} Node;

/*
 * Parameters:
 * head - The current head of the queue
 * data - The data to be enqueued
 *
 * Return:
 * The new head of the queue
 *
 * The function will take in the head of
 * a queue and a new piece of data
 * and enqueue (insert at the end)
 * that data into the queue
 */
Node* enqueue(Node* head, int data);

int main(void) {
	Node* queue = NULL;
	int i;
	for (i = 0; i < 4; i++) {
		queue = enqueue(queue, i);
	}

	for (i = 0; i < 4; i++) {
		if (queue == NULL) {
			printf(ANSI_COLOR_RED "The queue is to short!\n" ANSI_COLOR_RESET);
			return 1;
		}

		if (queue->data != i) {
			printf(ANSI_COLOR_RED "The queue is out of order!\n" ANSI_COLOR_RESET);
			return 2;
		}

		Node* prev = queue;
		queue = queue->next;
		free(prev);
	}

	printf(ANSI_COLOR_GREEN "You have completed the prelab!\n" ANSI_COLOR_RESET);
	return 0;
}

Node* enqueue(Node* head, int data) {
  Node *new_node, *p;

    new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (!head){
        return new_node;
    }

    p = head;
    while (p->next){
        p = p->next;
    }
        p->next = new_node;
    return head;
}
Node* insert(Node* head, int data){
	Node *temp;

    temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (!head)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }

}
void display(Node* head){
	printf("\n The queue is: ");
	if(head == NULL){
		printf("\n Queue is empty\n");
	}
	else{
		while(head != NULL){
			printf("->%d" head->data);
			head = head->next;

		}
	}
}
