#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void convertToDoubly(struct Node* head){
	struct Node* current = head;
	struct Node* previous = NULL;
	while (current != NULL){
		current->prev = previous;
		previous = current;
		current = current->next;
	}
}

void printReverse(struct Node* head){
	if(head == NULL){
		return;
	}
	struct Node* temp = head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	printf("Danh sach in nguoc(DLL): ");
	while(temp != NULL){
		printf("%d <-> ", temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
}

int main(){
	struct Node* head = createNode(10);
	head->next = createNode(20);
	head->next->next = createNode(30);
	convertToDoubly(head);
	printReverse(head);
	return 0;
}
