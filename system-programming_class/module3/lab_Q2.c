#include <stdio.h>
#include <string.h>

int fib();
char input[BUFSIZ];

int main(int argc, char* argv[]){
   //2.Modified this program to take command line argument for fibbonaci sequence
  if(argc != 2){
    printf("Invalid, please only enter 1 arguments.\n");
    return 1;
  }

  int n = atoi(argv[1]);
  for(int i=0; i<n; i++){
    printf("%d, ",fib(i));
  }
  printf("...\n");
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