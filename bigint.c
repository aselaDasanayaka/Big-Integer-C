#include <bigint.h>
#include <helper.h>
#include <stdlib.h>
#include <stdio.h>

/* implement the functions in *.h 
 * Given are broken code!!!!!!!
 */ 


bigint_t new_bigint(int a) 
{ 
     bigint_t head = NULL;  //create new big int
     
     while (a!=0)
     {
     	int k = a%10; 
     	addnode(k,&head);
     	a=a/10;   
     }
     return head;
}

int add(bigint_t *s, bigint_t a, bigint_t b)
{
	int carry=0;
	int sum=0;
	int k;	
	bigint_t heada = NULL;  // create 
	bigint_t headb = NULL;
	bigint_t head = NULL;
	
	heada = rev(a); free_bigint(a);   // reverse list
	headb = rev(b);
	
	while (heada !=NULL || headb !=NULL )
	{	
		if(heada != NULL && headb==NULL ) // a isnot over and b is over
		{
			sum=carry + heada-> data ;
			k=sum%10;
				//*** debguing***printf("sum 1 : %d\n",k);
			addnode(k,&head);
			carry=sum/10;
			heada= heada->next;
		}		
		else if(heada == NULL && headb !=NULL )// b isnot over and a is over
		{
			sum=carry  + headb->data;
			k=sum%10;
				//*** debguing***printf("sum 2 : %d\n",k);
			addnode(k,&head);
			carry=sum/10;
			headb= headb->next;
		}		
		else
		{
			sum=carry + heada-> data + headb->data;
			k=sum%10;
				//*** debguing***printf("sum 3 : %d\n",k);
			addnode(k,&head);
			carry=sum/10;
			heada= heada->next;
			headb= headb->next;				
	   	}	   	
  	}  	
  	if(carry==1)
	addnode(1,&head);
	
  	*s=head;
  	return 0;
}


void show_bigint(bigint_t head) //print big int
{
	while(head!=NULL)  
  	{
   		 printf("%d", head -> data);
		head = head ->next ; 
  	}
}
  
void free_bigint(bigint_t n) // free big int
{	
     deletelist(n);       
}




