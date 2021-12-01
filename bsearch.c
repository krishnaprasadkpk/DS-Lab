#include<stdio.h>
int main()
{
  int n,num,a[50],temp;
  int f,l,m,flag=0;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  printf("Enter the elements\n");
  for(int i=0;i<n;i++){
  scanf("%d",&a[i]);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[i]<a[j]){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        
      }
    }
  }
  printf("Enter the element to search: ");
  scanf("%d",&num);
  f=0;l=n-1;
  while(f<=l)
  {
   m=(f+l)/2;
  
   if(a[m]==num)
   {flag=1;break;}
   if(a[m]<num)
    f=m+1;
   else
    l=m-1;
  }
  if(flag==1)
    printf("Element %d is found at %d\n",num,m+1);
  else
    printf("Element is not found\n");
  
  
return 0;
}
