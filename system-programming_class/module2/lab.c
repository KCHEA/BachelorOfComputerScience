#include <stdio.h>
#include <stdlib.h>

typedef char DATA;
struct node{
  DATA d;
  struct node *next;
};

void backward_list();
void normal_list();
void print_list();
void reverse_list();

int main(){
  //1. Build a link list that adds new item to the beginning of the list
  struct node* head = NULL; 
  backward_list(&head);

  //2. Add a function to print the list
  print_list(&head);
  
  //3. Build the link list so that new item is added at the end of the list
  printf("\n\nBelow is the list in normal order.\n\n");
  normal_list(&head);
  print_list(&head);
  
  //4.write a function to reverse the list and print both version of the list
  printf("\n\nBelow is the list in its original order\n\n");
  normal_list(&head);
  print_list(&head);

  printf("\n\nBelow is the list in its reverse order\n\n");
  normal_list(&head);
  reverse_list(&head);
  print_list(&head);

  return 0;
}

//function definition below

void backward_list(struct node **head){ //this need to be a pointer to a pointer so we can assign it a new value
  for(int i=0; i<26; i++){ //this list will print store all 26 alphabets
    //this is the node that will be generated every loop that will be link to our head node  
    struct node* new = malloc(sizeof(struct node));
    
    //initialize the DATA so we increment our alphabet each loop (A,B,C ....)
    new->d = 'A'+i;
    new->next = NULL;

    if(*head == NULL){ //this will only happen once in the first loop
      *head = new;
    }
    else{//every subsequent loop will follow this condition
      /*
      everytime a new node is created it will become the previous node and head become the 
      subsequent node, then we assign head to new so we can generate a backward link list
      */
      new->next = *head;
      *head = new;
    }
  }
}

void print_list(struct node **head){
  struct node *temp =  *head;

  while(temp != NULL){
    printf("%c\n",temp->d);
    temp = temp->next;
  }

  //free up memory allocated to the link list
  while(*head != NULL){
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

void normal_list(struct node **head){
  struct node *current = NULL; //this is a temporary pointer that will be use to link head to new node

  for(int i=0; i<26; i++){
    struct node *new = malloc(sizeof(struct node));
    new->d = 'A'+i;
    new->next = NULL;

    if(*head == NULL){
      *head = new;
      current = new;
    }
    else{
      //current is only a temporary pointer so we can use it to link subsequent new node
      current->next = new;
      current = new;
    }
  }
}

void reverse_list(struct node **head){
  /*
    What we need to do is to:
    -Create another list the same size as the original
    -Then link the node in the new list in reverse order
  */

  struct node *new_head = NULL;
  struct node *temp = *head;

  while(temp != NULL){
    //We are creating a backward list that get its DATA attribute from temp/head
    struct node *new = malloc(sizeof(struct node));
    new->d = temp->d;
    new->next = NULL;

    if(new_head == NULL){
      new_head = new;
    }
    else{
      new->next = new_head;
      new_head = new;
    }

    temp = temp->next;
  }

  //free up memory for original link list
  temp = *head;
  while(temp != NULL){
    struct node *free_temp = temp;
    temp = temp->next;
    free(free_temp);
  }

  *head = new_head;
}