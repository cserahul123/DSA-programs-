#include<stdio.h>
#include<stdlib.h>
int *queue;
int rear,front,max,count=0;
void enqueue(int item){
  if(count==max){
    printf("queue is full");
  }
  else{
    rear=(rear+1)%max;
    queue[rear]=item;
    count++;
  }
}
int dequeue(){
  if(count==0){
    printf("queue underflow or queue is empty");
    return -999;
  }
  else{
    front=(front+1)%max;
    count--;
    return queue[front];
  }
}
void display() {
  int i;
  if(count==0){
    printf("queue is empty");
  }
  else{
    printf("queue elements are:");
    for(i=0;i<count;i++){
     printf("%d ",queue[(front+i+1)%max]);
    }
  }
}
int main(){
  int choice,item,ele;
  printf("Enter the size of queue:");
  scanf("%d",&max);
  queue=(int*)malloc(max*sizeof(int));
  rear=max-1;
  front=max-1;
  while(1){
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("Enter the element to be enqueued:");
        scanf("%d",&item);
        enqueue(item);
        break;
      case 2:
        ele=dequeue();
        if(ele!=-999)
          printf("Dequeued element is %d",ele);
        break;
      case 3:
        display();
        break;
      case 4:
        free(queue);
         exit(0);
      default:
        printf("Invalid choice");
    } }
    return 0;
}