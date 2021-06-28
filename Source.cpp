//Add a node after a given node:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
	int data;
	struct Node *next;
}*head = NULL;

struct Node* push(struct Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
	}
	return head_ref;
}

void insertAfter(int prev_node, int new_data)  
{												//Given a node data prev_node, insert a new node after the given prev_node
	struct Node *ptr = head;
	while (ptr->data != prev_node)
		ptr = ptr->next;

	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}

void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main()
{
	head = push(head, 11);
	// while(1)  // - for checking Stack Overflow condition
	head = push(head, 7);
	head = push(head, 3);
	head = push(head, 1);
	printf("\n Created Linked list is : \n");
	printList(head);
	//	while(1)  // - for checking Stack Overflow condition
	insertAfter(7, 9);
	printf("\n Created Linked list after insertion is : \n");
	printList(head);

	_getch();
}