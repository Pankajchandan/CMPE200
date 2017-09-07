#include<stdio.h>
#include<stdlib.h>
struct node_t { 
	int data; 
	struct node_t* next; 
};
            
struct list_t { 
	struct node_t* head;
	struct node_t* tail;
};

void list_head_append(struct list_t* list, struct node_t*  node) {
	if(list->head==NULL){
		list->head=list->tail=node;
		list->head->next=NULL;
	}
	else{
		struct node_t* buf;
		buf=list->head;
		list->head=node;
		node->next=buf;
	}
                     
}

void list_tail_append(struct list_t* list, struct node_t*  node) {
	if(list->tail==NULL){
		list->head=list->tail=node;
		list->tail->next=NULL;
	}
	else{
		struct node_t* buf;
		buf=list->tail;
		list->tail=node;
		node->next=buf;
	}                    

}

void print_list(struct list_t* list){
	struct node_t* buf; 
	buf=list->head;
	while(buf!=NULL){
		printf("%d-->",buf->data);
		buf=buf->next;
	}
	printf("null");
}

void init_node(struct node_t* node,int data){
	node->data=data;
}

int main(void){
	struct list_t list1;
	struct node_t node1,node2;
	printf("initializing node1 \n");
	init_node(&node1,10);
	printf("initializing node2 \n");
	init_node(&node2,20);
	list_head_append(&list1,&node1);
	list_head_append(&list1,&node2);
	printf("printing list \n");
	print_list(&list1);
	return 0;
}
