#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char DATA;
struct node{
  DATA d;
  struct node *next;
  struct node *prev;
};

void double_link();
void print_list();

int main(){
  //1. Build a doubly link list using a loop
  struct node *head = NULL;
  struct node *feet = NULL;

  double_link(&head,&feet);
  print_list(&head,feet);

  //2.print out pyramid of stars, ask user for number of row to be printed
  printf("\nBelow is a pyramid of stars\n");
  printf("Enter the number of rows: ");
  int rows;
  int result;
  char input[BUFSIZ];

  result = scanf("%d",&rows);

  while(result != 1 || strlen(input) == 0){ //this will loop until the user enter a number
    printf("Invalid input. Please enter a number: ");
    fgets(input,sizeof(input),stdin);
    result = sscanf(input,"%d",&rows); 
  }
 
  //this for loop will print a pyramid of stars
  for(int i=1; i<=rows; i++){
    for(int j=rows; j>i; j--){
      printf(" ");
    }
    for(int k = 1; k <= 2 * i - 1; k++){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

//function definition below
void double_link(struct node **head, struct node **feet){
  /*
    we will create a link list that can be traverse back and forth in both directions using next
    and prev so we wil have two pointers to two nodes, head and feet
  */
  struct node *current = NULL; //this is a temporary pointer that will be use to link head to new node

  for(int i=0; i<26; i++){ 
    struct node *new = malloc(sizeof(struct node));
    new->d = 'A'+i;
    new->next = NULL;
    new->prev = NULL;

    if(*head == NULL){
      *head = new;
      current = new;
    }
    else{
      current->next = new;
      new->prev = current;
      current = new;
    }
  }
  
  *feet = current; //after the loop, current will point to the last node which will be our list's feet
}

void print_list(struct node **head, struct node *feet){
  struct node *temp =  *head;

  printf("\n\nBelow we print the list in normal order using next\n\n");
  while(temp != NULL){
    printf("%c\n",temp->d);
    temp = temp->next;
  }

  printf("\n\nBelow we print the list in reverse using prev\n\n");

  temp = feet;
  while(temp != NULL){
    printf("%c\n",temp->d);
    temp = temp->prev;
  }

  //free up memory allocated to the link list
  while(*head != NULL){
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}