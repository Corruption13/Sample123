/*
Write a menu driven program in C to implement a singly linked list and to perform the following
i) Insert a node at the beginning of the list
ii) Insert a node after a particular node in the list
iii) Insert a node at the end of the list
iv) Delete a node containing a particular item

S Sandeep Pillai
CS3A
59

*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	//char c_data[500];
	//float f_data;	
	struct node *next;

};

void print_node(struct node *first){

	struct node *temp = first;
	

	printf("\nLinked list:\n\n");
	while(temp->next != NULL){
		
		printf("%d \n", temp->data);
		temp = temp->next;

	}

}

struct node input_node()
{
	struct node *temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter struct node data: \n");
	scanf("%d", &temp->data);
	return *temp;
}

int compare_nodes(struct node A, struct node B)
{
	if(A.data == B.data)
		return 1; // True
	else
		return 0; // False
}



struct node insert_specific(struct node *first, struct node item)
{

	struct node value = input_node() ;
	struct node *temp;
	temp = first;
	while(temp->next != NULL)
	{
		if(compare_nodes(*temp, item) == 1)
		{
			item.next = temp->next;
			temp->next = &item;
			return *first;	//Item found.
		}
		
		temp = temp->next; //Else traverse list.
	}
	printf("\nItem not found!\n");
	


}

struct node insert_end(struct node *first)
{

	struct node value = input_node() ;
	printf("End D1: %d", value.data);
	struct node *temp;
	temp = first;
	//printf("\nh\n");
	while(temp->next != NULL){
		//printf("Traverse: %d\n", temp->data);
		temp = temp->next;
	}
	value.next = NULL;
	temp->next = &value;

	// temp = temp->next;
	printf("Test-1: %d\n", temp->next->data);
	
	printf("Test0: %d\n", temp->data);
	printf("Test1: %d\n", value.data);
	// print_node(first);
	return *first;
}


struct node insert_beg(struct node *temp){
	// struct node value = malloc(sizeof (struct node));
	
	
	struct node value = input_node() ;
	//struct node value;
	//scanf("%d", &value.data)	;
	
	value.next = temp->next ;
	temp = &value ;
	
	return *temp;
	
}



int main(){
	
	struct node start;
	//start = malloc(sizeof (struct node));
	start.data = 2;
	start.next == NULL;
	start = insert_beg(&start);
	printf("Debug1: %d", start.data);
	int ch;
	while(1)
	{	

		printf("\n\n*-*-*-*-*-*-\n[1] Enter node to beginning\n[2] Enter element to End\n");
		printf("[3]Enter at specific location\n[4]Delete Specific  Node\n[5]Print LL\n[0] Exit Program\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\ninput value: %d\n", start.data);
				start = insert_beg(&start);
				printf("Value: ", start.data);
				printf("\ninput_value: %d\n", start.data);
				break;	
			case 2:
				start = insert_end(&start);

				break;	
			case 3:	
				printf("Enter int value of the node you wish to insert after:\n");
				struct node item = input_node();
				start = insert_specific(&start, item);
				break;	
			case 4: 
			case 5:

				print_node(&start);
				printf("\nEnd of LL\n");
				break;
			//case 1:
				//insert_beg(start);
				//break;	
			case 0:
				return 0;			
		}
		
	}
		
	
	return -1;

}


