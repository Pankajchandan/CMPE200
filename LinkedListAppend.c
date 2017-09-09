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
    if(list->head->data==NULL){
        list->head=node;
        list->head->next=NULL;
        list->tail=list->head;
    }
    else{
        node->next=list->head;
	    list->head=node;   
    }
}

void list_tail_append(struct list_t* list, struct node_t*  node) {
    if(list->tail->data==NULL){
        list->tail=node;
        list->tail->next=NULL;
        list->head=list->tail;
    }
    else{
	    list->tail->next=node;
	    list->tail=node;
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

int main(void){
    //init list
	struct list_t list1;
	list1.head=(struct node_t*)malloc(sizeof(struct node_t));
	list1.tail=(struct node_t*)malloc(sizeof(struct node_t));
	list1.head->data = list1.tail->data = NULL;

    //init nodes
	struct node_t node1,node2;
	printf("initializing node1 \n");
	node1.data = 10;
	printf("initializing node2 \n");
	node2.data = 20;
	
	//append nodes
	list_tail_append(&list1,&node1);
	list_head_append(&list1,&node2);
	
	//print nodes
	printf("printing list \n");
	print_list(&list1);
	
	return 0;
}
