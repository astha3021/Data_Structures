#include<stdio.h>
#define max 20
void sort(int arr[max],int n);
int main()
{
   int arr[max],i,j,n;

   printf("Enter the number of elements in an array :");
   scanf("%d",&n);

   printf("enter the elements :");
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   sort(arr,n);

}
void sort(int arr[max],int n)
{
  int i,j,temp,value,start_index = -1 ,last_index=-1;
  for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
  }
    printf("the sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nenter the value whose start and end position is to be known :");
    scanf("%d",&value);
    for(i=0;i<n;i++){
        if(arr[i]==value){
            start_index = i;
            break;
        }
    }
    last_index =start_index;
    for(i=start_index;i<n;i++){
    if(arr[i]==value){
        last_index+=1;
      }
    }
    printf(" start occurrence : %d , last occurrence :%d ",start_index,(last_index-1));

}
