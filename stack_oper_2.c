#include<stdio.h>
#include<stdlib.h>
int *stack;
int max;
int top=-1;
void push(int item);
int pop();
void display();
int main() {
  int choice,item,ele;
  printf("Enter the size of stack:");
  scanf("%d",&max);
  stack=(int*)malloc(max*sizeof(int));
  while(1){
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the element to be pushed:");
        scanf("%d",&item);
        push(item);
        break;
      case 2:
        ele=pop();
        if(ele!=-1)
          printf("Popped element is %d",ele);
        break;
      case 3:
        display();
        break;
      case 4:
        free(stack);
         exit(0);
      default:
        printf("Invalid choice");
    } }
    return 0;
  }
    void push(int item) {
      if(top>=max-1){
        max=max*2;
        printf("array size doubled");
      stack=(int*)realloc(stack,max*sizeof(int));
          }
          stack[++top]=item;
    }
    int pop() {
      if(top==-1){
        printf("Stack is empty");
        return -999;
      }
      else{
        return stack[top--];
      }
    }
    void display(){
      int i;
      if(top==-1){
        printf("Stack is empty");
      }
      else{
        printf("Stack elements are:");
        for(i=top;i>=0;i--){
          printf("%d ",stack[i]);
        }
      }
    }
