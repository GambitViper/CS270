#include <stdio.h>
#include <stdlib.h>
#include "int_stack.h"

/*struct is_node {
    int *contents;
    int next_index;
    struct is_node *next;
};

struct int_stack {
    size_t size;
    size_t node_capacity;
    struct is_node *head;
};*/

typedef struct int_stack stack;
typedef struct is_node node;

node *build_node(int);
void free_node(struct is_node *);

/* Operations on a stack */
struct int_stack *make_stack(int node_capacity){
	//Allocate Memory for the stack
	stack *stk = malloc(sizeof(stack));
	
	//Memory errors checking
	if(stk == NULL){
		fprintf(stderr, "Memory error\n");
		exit(-1);
	}
	
	//Declare and set the head node
	stk->head = build_node(node_capacity);

	//Set default values
	stk->size = 0;
	stk->node_capacity = node_capacity;

	return stk;	
}

node *build_node(int node_capacity){
	//Allocate memory for the node
	node *n = malloc(sizeof(node));
	
	//Memory errors checking
	if(n == NULL){
                fprintf(stderr, "Memory error\n");
                exit(-1);
        }

	//Allocate space in the array
	n->contents = malloc(node_capacity * sizeof(int));
	
	//Memory errors checking
	if(n->contents  == NULL){
                fprintf(stderr, "Memory error\n");
                exit(-1);
        }

	//Set default values
	n->next_index = 0;
	n->next = NULL;

	return n;
}

void free_stack(struct int_stack *stk){
	//Free stack
	reset_stack(stk);

	//Free head node and actual stack
	free_node(stk->head);

	//Free memory
	free(stk);
}

void reset_stack(struct int_stack *stk){
	node *curnode = stk->head->next;
	
	//Free loop
	while(curnode != NULL){
		node *next_n = curnode->next;
		free_node(curnode);
		curnode = next_n;
	}
	
	//Null the head
	stk->head->next = NULL;
	stk->head->next_index = 0;
	stk->size = 0;
}

void push(struct int_stack *stk, int v){
	node *curnode = stk->head;
	
	if(curnode->next_index == stk->node_capacity){
		//If first node is full create a new top
		curnode = build_node(stk->node_capacity);
		curnode->next = stk->head;
		stk->head = curnode;
	}
	//Add the data v
	curnode->contents[curnode->next_index] = v;
	curnode->next_index++;
	stk->size++;
}

int pop(struct int_stack *stk){
	int return_val = -1;
	if(!is_empty(stk)){
		node *curnode = stk->head;
		
		return_val = curnode->contents[curnode->next_index-1];
		
		//Decrease values for 1 less element from the pop
		curnode->next_index--;
		stk->size--;
		
		if(curnode->next_index == 0 && curnode->next != NULL){
			//Delete the node and add to head
			stk->head = curnode->next;

			free_node(curnode);
		}
	}
	return return_val;
}

int top(struct int_stack *stk){
	//Return the top node so long as the stk is not empty
	if(!is_empty(stk)){
		return stk->head->contents[stk->head->next_index-1];
	}else {
	//stk is empty return fail value
		return -1;
	}
}

void free_node(struct is_node *curnode){
	//Reset the node
	curnode->next = NULL;
	//Free the memory
	free(curnode->contents);
	free(curnode);
}

int is_empty(struct int_stack *stk){
        return stk->size == 0;
}

void print_stack(struct int_stack *stk){
	int iter;
	node *curnode = stk->head;
	if(!is_empty(stk)){
		//Corner case if first node is not full
		if(curnode->next_index < stk->node_capacity){
			printf("(");
			for(iter = curnode->next_index-1; iter > 0; iter--){
				printf("%d,",curnode->contents[iter]);
			}
			printf("%d]",curnode->contents[0]);
			curnode = curnode->next;
		}

		//BASE CASE
		while(curnode != NULL){
			printf("[");
			for(iter = curnode->next_index-1; iter > 0; iter--){
				printf("%d,",curnode->contents[iter]);
			}
			printf("%d]",curnode->contents[0]);
			curnode = curnode->next;
		}
	} else {
		printf("(]");
	}
	printf("\n");		
}

