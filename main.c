#include <bigint.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main()
{
  int i, f,p;  
  bigint_t a, b, fib;   
  for(f = 1; f <= 100; f++)
   {  
	    for(i=2, a = new_bigint(1), b = new_bigint(1), fib =new_bigint(1) ; i < f; i++)
	     {     
		   add(&fib,a,b);
		     free_bigint(a);// free memory
		    a = b; 
		    b = fib; 
    	     }
	    printf("%d the Fib is ", f );
	    show_bigint(fib);
	    printf("\n");
	    
	    free_bigint(fib);// free memory
	    free_bigint(a);
	    
  } 
  return 0; 
}
  
  
