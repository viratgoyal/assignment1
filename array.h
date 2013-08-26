#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int L[100],n,*p,*q,*before;

int i;

char *inputFile,*outputFile;
int getElements(int* x)				/* Function to fetch elements into array from the input file */
{
  ifstream indata;
  indata.open(inputFile);			
  if(!indata)					/* Checking if the file exists or not */
  {
    cout<<"File could not be opened"<<endl;
    exit(1);
  }
  i=0;
  while(!indata.eof())				/* Taking elements from input file, until end of file */
  {
    indata>>*x++;
    i++;
  }
  return i;
}

int* FIRST(int *x)
{
  return x;					/* Getting starting address of the pointer array	*/
}

int* END(int* x,int n)
{
  return (&x[n]);				/* Returning the end pointer address */
}

int* NEXT(int* y,int* x)
{
  return (++y);					/* Returning next element address of the array */
}

int RETRIEVE(int* y,int* x)
{
  return(*y);					/* Returns the array value pointed by the pointer */
}

int DELETE(int* y,int* prev,int* x,int n)
{
  int* temp;
  n=n-1;
  while(y!=END(x,n))				/* Delete the duplicates in array */
  {
    temp=y;
    temp++;
    *y=*temp;
    y=temp;
  }
  return(n);
}

void output(int* x,int n)
{
  ofstream outdata;
  outdata.open(outputFile);
  if(!outdata)					/* checking whether output file exists or not */
  {
    cout<<"File cannot be accessed"<<endl;
    exit(1);
  }
  
  i=0;
  while(i<n)
  {
    outdata<<x[i]<<" ";				/* writing the elements of array back into the output file */
    i++;
  }
  
}