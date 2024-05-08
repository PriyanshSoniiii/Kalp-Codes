#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
	void *data; 
	struct Node *next; 
}; 


void insert(struct Node** head_ref, void *val, size_t data_size) 
{  
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	new_node->data = malloc(data_size); 
	new_node->next = (*head_ref); 

	
	int i; 
	for (i=0; i<data_size; i++) 
		*(char *)(new_node->data + i) = *(char *)(val + i); 
	(*head_ref) = new_node; 
} 

void display(struct Node *node, void (*fptr)(void *)) 
{ 
	while (node != NULL) 
	{ 
		(*fptr)(node->data); 
		node = node->next; 
	} 
} 

void printInteger(void *n) 
{ 
printf(" %d\n", *(int *)n); 
} 
 
void printFloat(void *f) 
{ 
printf(" %.1f\n", *(float *)f); 
} 

void printChar(void *c) 
{ 
printf(" %c\n", *(char *)c); 
} 

int main() 
{ 
	struct Node *head = NULL; 
 
	int arr[] = {4, 5, 6, 7, 8, 9}, i; 
	for (i=0; i<=5; ++i) 
	insert(&head, &arr[i], sizeof(arr[i])); 
	display(head, printInteger); 
 
	head = NULL; 
	float arr2[] = {5.4, 7.6, 2.4, 1.6, 9.3}; 
	for (i=0; i<=4; ++i) 
	insert(&head, &arr2[i],  sizeof(arr2[i])); 
	display(head, printFloat); 

 
	head = NULL; 
	char arr3[] = {'a', 'b', 'c', 'd', 'e'}; 
	for (i=0; i<=4; ++i) 
	insert(&head, &arr3[i],  sizeof(arr3[i])); 
	display(head, printChar); 

	return 0; 
} 
