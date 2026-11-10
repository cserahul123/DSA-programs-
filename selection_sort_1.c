#include<stdio.h>
#include<stdlib.h>
void selection(int a[], int n){
  int i,j,temp,min;
  for(i=0;i<n-1;i++)
  {
    min=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[min])
      min=j;
    }
    {
      temp=a[i];
      a[i]=a[min];
      a[min]=temp;
    }
  }
}
int main() {
  int *a,n,i;
  printf("Enter the no of elements : ");
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  if(a==NULL){
    printf("memory allocation failed");
    return 1;
  }
  printf("Enter the array elements : ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  selection(a,n);
  printf("Sorted array is : ");
  for(i=0;i<n;i++)  
  printf("%d\t",a[i]);
  printf("\n");
  free(a);
  return 0;
}
