#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t* node=(node_t*)malloc(sizeof(node_t));
	node->data=data;
	node->prev=NULL;
	if(is_empty(list)){
		node->next=NULL;
		list->head=node;
		list->tail=node;
	} else {
		node->next=list->head;
		list->head->prev=node;
		list->head=node;
	}
	(list->size)++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t* node=(node_t*)malloc(sizeof(node_t));
	node->data=data;
	node->next=NULL;
	if(is_empty(list)){
		node->prev=NULL;
		list->head=node;
		list->tail=node;
	} else {
		node->prev=list->tail;
		list->tail->next=node;
		list->tail=node;
	}
	(list->size)++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* node=(node_t*)malloc(sizeof(node_t));
	node->data=data;
	node_t* temp=search(list,prev);
	if(temp){
		temp->next->prev=node;
		node->prev=temp;
		node->next=temp->next;
		temp->next=node;
		list->size++;
	}
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	if(!is_empty(list)){
		node_t* node=list->head;
		if(size(list)==1){
			list->head=NULL;
			list->tail=NULL;
		} else {
			list->head=list->head->next;
			list->head->prev=NULL;
		}
		free(node);
	}
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	if(!is_empty(list)){
		node_t* node=list->tail;
		if(size(list)==1){
			list->head=NULL;
			list->tail=NULL;
		} else {
			list->tail=list->tail->prev;
			list->tail->next=NULL;
		}
		free(node);
	}
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	if(!is_empty(list)){
		node_t* node=search(list,data);
		if(list->head==node){
			delete_front(list);
		} else if(list->tail==node){
			delete_back(list);
		} else {
			node->prev->next=node->next;
			node->next->prev=node->prev;
			free(node);
		}
	}
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
	if(!is_empty(list)){
		node_t* node=list->head;
		while(node!=NULL && node->data!=data){
			node=node->next;
		}
		return node;
	}
	return NULL;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

