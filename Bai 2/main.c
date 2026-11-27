#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

void appendDLL(struct Node** head, int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	if(*head == NULL){
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void convertToSingly(struct Node* head){
	struct Node* current = head;
	while(current != NULL){
		current->prev = NULL;
		current = current->next;
	}
}

void verifySingly(struct Node* head){
	struct Node* temp = head;
	printf("Trang thai sau khi chuyen ve SLL:\n");
	while(temp != NULL){
		printf("Node %d | prev = %s\n", temp->data, (temp->prev == NULL) ? "NULL" : "Con ton tai");
		temp = temp->next;
	}
}

int main(){
	struct Node* head = NULL;
	appendDLL(&head, 10);
	appendDLL(&head, 20);
	appendDLL(&head, 30);
	convertToSingly(head);
	verifySingly(head);
	return 0;
}
