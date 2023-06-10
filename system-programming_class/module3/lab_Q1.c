#include <stdio.h>
#include <string.h>

int fib();
char input[BUFSIZ];

int main(){
  while(1){ //this loop will print out the sequence and ask for input to print our more sequence
    //1.write out a function to print the fibonacci sequence
  int n;
  printf("Enter the number of fibonacci sequence: ");

  if(fgets(input,sizeof(input),stdin) == NULL){
    printf("Error reading inputs\n");
  }

  int result = sscanf(input,"%d",&n);

  //if user enter non-integer or whitespace it will keep asking for input
  while(result != 1 || strlen(input) == 0){ 
    printf("Invalid, please enter a number: ");
    fgets(input,sizeof(input),stdin);
    result = sscanf(input,"%d",&n);
  }
  
  for(int i=0; i<n; i++){
    printf("%d, ",fib(i));
  }
  printf("...\n");
  }

  return 0;
}

//function definition below
int fib(int n){

  if(n <= 1){
    return n;
  }
  else{
    return fib(n-1)+fib(n-2);
  }
}