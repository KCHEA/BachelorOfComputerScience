#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char stackitem;

struct stack{
  stackitem d;
  struct stack *next;
};

typedef struct stack ELEMENT;
typedef ELEMENT *POINTER;


//function prototype below
void push(POINTER *Top, stackitem a);
void pop(POINTER *Top);
void push_string(POINTER *Top,char *string);
void delete_stack(POINTER *Top);
void print_stack(POINTER Top);

//optional work, function prototype
void exchange_top(POINTER Top);
void reverse(POINTER *Top);

main(){
    POINTER top;
		top= (POINTER) NULL;
		stackitem A='A';
		stackitem B='B';
		char *C="12345";
		//printf("C is %s\n", C);
		push(&top,A);
		push(&top,B);
		print_stack(top);
		pop(&top);
		pop(&top);
		print_stack(top);
		push_string(&top,C);
		print_stack(top);
		delete_stack(&top);
		print_stack(top);

    //optional work
    printf("\nNow the two top elements are exchange\n");
    push_string(&top,C);
    exchange_top(top);
    print_stack(top);

}

//function definition below
//a. push a character onto the stack
void push(POINTER *Top, stackitem a){
    POINTER temp;
		temp = malloc(sizeof(ELEMENT));
		temp->d = a;
		temp->next = *Top;
		*Top = temp;
		printf("Insert element %c\n", temp->d);
}

//b. pop the top character from the stack
void pop(POINTER *Top)
/* Remove the top item */
     {
		POINTER Top1 = *Top;
		if (Top != NULL)
		{
		  *Top = Top1->next;
		  printf("Remove element %c\n", Top1->d);
		  free(Top1);
		}
		else
		  printf("Empty stack.\n");
     }

//c. push a string of characters into a stack, should make use of the push() fuction
void push_string(POINTER *Top,char *string){
  int length = strlen(string);

  for(int i=length-1;i>=0;i--){
    //this loop will push each character in the string into stack
    //we reverse this loop to push in the last character in first 
    push(Top,string[i]);
  }
}

//d. Delete, remove all item from the stack, should make use of the pop() function
void delete_stack(POINTER *Top){
  POINTER temp = *Top;

  while(temp != NULL){ //we loop through the stack and pop all of the nodes
    temp = temp->next;
    pop(Top);
  }
}

//e. print the content of the stack
void print_stack(POINTER Top){
  if(Top == NULL){
    printf("The content of the stack is empty\n");
  }
  else{
    printf("The content of the stack is:\n");

    POINTER temp = Top;
    while(temp != NULL){
      printf("%c\n",temp->d);
      temp = temp->next;
    }
  }
}

//Optional work 
//1.a. function to exchange the top two elements of the stack
void exchange_top(POINTER Top){
  stackitem a = (Top)->d;
  Top->d = (Top->next)->d;
  (Top->next)->d = a;

}

//1.b. function to reverse the stack
void reverse(POINTER *Top){
  
}