#include <helper.h>
#include <bigint.h>
#include <stdio.h>

/* implementation of the helper functions */
int addnode(int data, bigint_t *head)   // add node to link list
{
  bigint_t tmp = malloc(sizeof(struct big_int));
  if(!tmp)  return -1;
  
  tmp -> data = data;
  tmp -> next = *head; 
  *head = tmp;

  return 0;   
}

void show(bigint_t head) // print link list
{
	 while(head!=NULL)  
	  {
	    printf("%d", head -> data);
	    head = head ->next ; 
	  }
}
  
void deletelist(bigint_t head)
{
  /* implement me */
	while(head) { 			//to go untill the list is over
    	bigint_t temp;
	temp=((head)->next);
	free(head);			//freeing the memory at each node
	head = temp;
	}
}

bigint_t rev (bigint_t a)  // reverse link list
{
	bigint_t head=NULL;	  
	while (a)
	{
		addnode(a->data,&head);
		a = a->next;
	}
	return head;
}

