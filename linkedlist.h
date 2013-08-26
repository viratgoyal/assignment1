#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct singlyll					/* Declaring the structure 										of node */
{
  int data;
  singlyll* next;
};

char *inputFile,*outputFile;
singlyll *L,*p,*q,*before;

int i,n;

int getElements(singlyll *start)   		/* Function to insert elements into linked list */
{
  singlyll *temp1,*temp2;
  ifstream indata;
  indata.open(inputFile);			/* Opens input file */
  if(!indata)					/* checks if file exists or not */
  {
    cout<<"File could not be opened"<<endl;
    exit(1);
  }
  
  start=(singlyll*)malloc(sizeof(singlyll));	/* Allocating memory for node */
  indata>>start->data;				/* Gets the first element from the input file */
  start->next=NULL;				
  temp1=start;
  
  i=1;
  while(!indata.eof())
  {
    temp2=(singlyll*)malloc(sizeof(singlyll)); 	/* creating nodes and allocating memory */
    indata>>temp2->data;			/* Taking next element into the node from file */
    //cout<<temp2->data<<" ";
    temp2->next=NULL;
    temp1->next=temp2;
    temp1=temp1->next;
    i++;
  }
  //cout<<i;
  L=start;
  return i;
}

singlyll* FIRST(singlyll *start)
{
  return start;					/* Returns starting address of the linked list	*/
}

singlyll* END(singlyll *start,int n)
{
return NULL;					/* Returns terminating condition of linked list */
}

singlyll* NEXT(singlyll* node,singlyll* start)
{
  return (node->next);				/* Returns next element address of the linked list */
}

int RETRIEVE(singlyll *node,singlyll *start)
{
  return (node->data);				/* Returns the data at node pointed by the pointer */
}

int DELETE(singlyll* node,singlyll* before,singlyll* start,int n)
{
  before->next= node->next;			/* Deleting the node */
  n=n-1;
  return n;
}

void output(singlyll* start,int n)		/* Function to write elements back into output file */
{
  
  ofstream outdata;
  outdata.open(outputFile);
  if(!outdata)
  {
    cout<<"File cannot be accessed"<<endl;
    exit(0);
  }
  singlyll *temp;
  temp=start;
  while(temp!=NULL)
  {
    outdata<<temp->data<<" ";			/* Ouputs elements to the output file */
    temp=temp->next;
  }
  
}