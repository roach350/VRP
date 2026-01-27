#ifndef _LL_CONTACT_
#define _LL_CONTACT_


#define FIELD_SIZE 128

//for phone numbers on other short character strings


struct node_contact_t{

	char data[FIELD_SIZE];
	struct node_contact_t* next;

	


};



void setNode(struct node_contact_t *node, const char *data){

	strncpy(node->data, data, FIELD_SIZE);
	node->next = NULL;

}



struct ll_contact_t{


	struct node_contact_t *head;
	struct node_contact_t *tail;
	size_t length;




};

size_t ll_size(struct ll_contact_t *list);

void ll_clear(struct ll_contact_t *list){

	int size = ll_size(list);
	
	struct node_contact_t *node = list->head;

	struct node_contact_t *next;	
	for (int i = 0; i < size; i++){

		next = node->next;
		free(node);
		node = next;
	}
	

}

void ll_push_back(struct ll_contact_t *list, int val){

	//create new node with data	
	struct node_contact_t *node = (struct node_contact_t*)malloc(sizeof(struct node_contact_t));
	node->data = val;
	node->next = NULL;
	
	if (list->length == 0){
		

		
		list->head = node;
		list->tail = node;

	}else{

		//tail now points to the new node
		list->tail->next = node; //previous tail node now  points to new node	
		list->tail = node;
	}


	list->length++;
}

void ll_contact_init(struct ll_contact_t *list){
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

}






size_t ll_contact_size( struct ll_contact_t *list){

	return list->length;

}

void ll_contact_print(struct ll_contact_t *list){

	int size = ll_contact_size(list);
	
	struct node_contact_t *node = list->head;
	
	for (int i = 0; i < size; i++){
		printf("%s\n ", node->data);
		node = node->next;

	}
	
	printf("\n");

}

#endif

