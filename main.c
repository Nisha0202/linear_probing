// Code implementing linear probing

#include <stdio.h>  
#include<stdlib.h>  
#define TABLE_SIZE 10 //here we have taken the table size as 10
int h[TABLE_SIZE];
 
 void insert() { // here the inserting function
  int key,index,i = 0, hkey;  
  printf("enter a value to insert into hash table :  ");  
  scanf("%d",&key);  
  hkey=key%TABLE_SIZE;  
  while(i<TABLE_SIZE) {
    index=(hkey+i)%TABLE_SIZE;  
    if(h[index] == NULL) {
     h[index]=key;  
      break;  
    } 
    i++;
   }  
  if(i == TABLE_SIZE)  
    printf("\ntable is full\n");  
 }  

 void search() {  // here the search function
  int key,index,i = 0,hkey;  
  printf("\nenter search element :  ");  
  scanf("%d",&key);  
  hkey=key%TABLE_SIZE;  
  while(i<TABLE_SIZE)  {
     index=(hkey+i)%TABLE_SIZE;  
   if(h[index]==key)  
   {  
    printf("\n value is found at index %d",index);   
    break;  
   }  i++;
  }  
  if(i == TABLE_SIZE)  
   printf("\n value is not found\n");  
 } 

void display() { // here the display function to display the table
  int i;  
  printf("\nelements in the hash table : \n");  
  for(i=0;i< TABLE_SIZE; i++)  
  printf("\nat index %d \t value = %d",i,h[i]);  
 }  

void delete_data(){ //delete an element from hash table
  int key,index,i = 0,hkey;  
  printf("\nenter the element you want to delete :  ");  
  scanf("%d",&key);  
  hkey=key%TABLE_SIZE;  
  while(i<TABLE_SIZE)  {
     index=(hkey+i)%TABLE_SIZE;  
   if(h[index]==key) { 
    h[index] = 0; // we put 0 as a value to represent the index is empty now
    printf("value is found at index %d and deleted",index);   
    display();
    break;  
   }  i++;
  } 
  if(i == TABLE_SIZE)  
   printf("\n value is not found\n"); 
}

 
  int main()  { // main funtion giving choices for the operation
   int choice,i;  
   while(1)  {
     printf("\nPress : 1. Insert\t 2. Display \t3. Search  \t4. Delete \t5. Exit\n");  
     scanf("%d",&choice);  
     switch(choice) { 
       case 1:  
         insert(); 
         printf("\n");
         break;  
       case 2:  
         display();
         printf("\n");
         break;  
       case 3:  
         search();  
         printf("\n");
         break; 
       case 4:
         delete_data();
         break;
       case 5:exit(0);
     }  
   }  
   return 0;  
 }  
