#include<iostream>
//#include "linkedlist.h"
#include "array.h"
using namespace std;

int main(int argc, char *argv[])	/* Main function definition with command line arguments */
{
  inputFile=argv[1];			/* Gets input file name from the command line argument list */
  outputFile=argv[2];			/* Gets output file name from the command line argument list*/
  n=getElements(L);			/* Inserts the elements and gets the count of number of elements inserted */
  p = FIRST(L);				/* Points to starting address of the first element */
  while (p!=END(L,n))			/* Loop to purge elements */
  {
    before=p;				/* Gets adress of the current pointer */
    q = NEXT(p,L);			/* Points to the adress of next element */
    while (q!= END(L,n))		
    {
      if (RETRIEVE(p,L)==RETRIEVE(q,L))	/* checking duplicates */
      {
	n=DELETE(q,before,L,n);		/* Delete if exists */
	q=NEXT(before,L);		/* Point to next node */
      }
      else				/* If elements are not equal, points forward to the next element */
      {
	before=q;
	q = NEXT(q, L);
      }
    }
    p = NEXT(p, L);
  }
  
  output(L,n);				/* output elements after purging */
  cout<<"\nNo. of elements after purging = "<<n<<"\n";	/* Displays the number of elements present in the list after purging, in the console */

  return 0;
}