/*
	Name    :- Harsh Kumar
	SRN     :- PES1UG19EE038
	PESU ID :- PES1201900555
*/
#include "queue.h"
static node *create_node(int id, int time, node *link)
{
//TODO
	node* newNode = (node*)malloc(sizeof(node));
	newNode->id = id;
	newNode->time = time;
	newNode->link = link;
	return newNode;
}
void list_initialize(List *ptr_list)
{
//TODO
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
	ptr_list->number_of_nodes = 0;
}
const int node_get_id(node *node_ptr)
{
//TODO	
	return node_ptr->id;
}

const int node_get_time(node *node_ptr)
{
//TODO		
	return node_ptr->time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
//TODO	
	node* newNode = create_node(id,time,NULL);
	if(ptr_list->tail == NULL){
		ptr_list->head = newNode;
		ptr_list->tail = newNode;
	}
	else{
		ptr_list->tail->link = newNode;
		ptr_list->tail = newNode;
	}
	ptr_list->number_of_nodes++;
}

void list_delete_front(List *ptr_list)
{
//TODO	
	if(ptr_list->head == NULL){
		return;
	}
	else{
		node* temp = ptr_list->head;
		ptr_list->head = temp->link;
		free(temp);
	}
	ptr_list->number_of_nodes--;
}

void list_destroy(List *ptr_list)
{
//TODO	
	free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
//TODO	
	list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
//TODO	
	list_insert_rear(ptr->ptr_list,id,time);
}

void queue_dequeue(Queue *ptr)
{
//TODO	
	if(!queue_is_empty(ptr)){
		list_delete_front(ptr->ptr_list);
	}
	else{
		return;
	}	
}

int queue_is_empty(Queue *ptr)
{
//TODO	
	if(ptr->ptr_list->tail == NULL){
		return 1;
	}	
	else{
		return 0;
	}
}

void queue_peek(Queue *ptr)
{
//TODO	
	if(ptr->ptr_list->tail == NULL){
		printf("Empty Queue\n");
		return;
	}	
	else{
		printf("%d %d\n", ptr->ptr_list->head->id,ptr->ptr_list->head->time);
	}
}

void queue_destroy(Queue *ptr)
{
//TODO		
	free(ptr);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
//TODO	
	int sum = 0;
	while(sum<=t){
		sum+=node_get_time(ptr_queue->ptr_list->tail);
		queue_dequeue(ptr_queue);
	}	
	if(ptr_queue->ptr_list->tail == NULL){
		printf("Empty Queue\n");
	}
	else{
		printf("%d\n",ptr_queue->ptr_list->tail->id);
	}
	return ptr_queue->ptr_list->tail->id;
}