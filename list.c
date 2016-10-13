#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int val;
	struct node *next;
	
};

struct node *createlist(int n){
	
	struct node *head, *prev, *cur;
	int i;
	if(n != 0){
		head = malloc(sizeof(struct node));
		head -> val = 1;
		prev = head;
		
		for(i = 2; i <= n; i++){
			
			cur = malloc (sizeof(struct node));
			cur -> val = i;
			prev -> next = cur;
			prev = cur;
			
		}
		
		prev -> next = NULL;
		return head;
		
	}
	
	else
		return 0;
	
}

struct node *createlistinverse(int n){
	
	struct node *head, *prev, *cur;
	int i;
	if(n != 0){
		head = malloc(sizeof(struct node));
		head -> val = 7;
		prev = head;
		
		for(i = 6; i >= 1; i--){
			
			cur = malloc (sizeof(struct node));
			cur -> val = i;
			prev -> next = cur;
			prev = cur;
			
		}
		
		prev -> next = NULL;
		return head;
		
	}
	
	else
		return 0;
	
}

void print(struct node *head){
	
	struct node *t;
	t = head;
	while (t != NULL){
		
		printf("%d\n", t -> val);
		t = t -> next;
		
	}
	
}

void deletenode(struct node *head, int key){
	
	struct node *prev, *cur;
	
	prev = head;
	cur = head -> next;
	while (cur != NULL){
		
		if(cur -> val == key){
			
			prev -> next = cur -> next;
			free(cur);
			break;
			
		}
		
		prev = cur;
		cur = cur -> next;
		
	}
	
}

int length(struct node *head){
	
	struct node *cur;
	int i = 0;
	
	cur = head;
	
	while (cur != NULL){
		++i;
		cur = cur -> next;
	}
	
	return i;
}

struct node *insertbegin(struct node *head, int value){
	
	struct node *newnode = malloc(sizeof(struct node));
	newnode -> val = value;
	newnode -> next = head;
	return newnode;
	
}

void insertmiddle(struct node *head, int value){
	
	struct node *newnode, *cur;
	int i;
	
	newnode = malloc(sizeof(struct node));
	newnode -> val = value;
	cur = head;
	
	for(i = 2; i <= (length(head)/2); i++)
		cur = cur -> next;
	
	newnode -> next = cur -> next; 
	cur -> next = newnode;
	
}

void sortlist(struct node *head){
	
	struct node *cur, *next;
	int size = length(head);
	int i, j, value;
	
	for(i = 0; i < length(head); i++, size-- ){
		cur = head ;
		next = head -> next ;
		
		for(j = 1; j < size; j++ ){ 
			
			if(cur -> val > next -> val){
				value = cur -> val ;
				cur -> val = next -> val;
				next -> val = value ;
			}
			
			cur = cur -> next;
			next = next -> next;    
			
		}
	}   
}

void concatenatelist(struct node *head1, struct node *head2){
	
	struct node *cur1, *cur2;
	int i;
	
	cur1 = head1;
	cur2 = head2;
	
	for(i = 2; i <= length(head1); i++)
		cur1 = cur1 -> next;
	
	cur1 -> next = cur2;
	
}

int main(){
	
	struct node *node1 = createlist(8);
	struct node *node2 = createlistinverse(7);
	
	/*deletenode(node1, 5);*/
	/*node1 = insertbegin(node1, 5);*/
	/*insertmiddle(node1, 9);*/
	/*sortlist(node2);*/
	/*concatenatelist(node1, node2);*/
	print(node1);
	/*print(node2);*/
	
	return 0;
}
