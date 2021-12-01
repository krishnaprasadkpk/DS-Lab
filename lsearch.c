#include<stdio.h>
int main()
{
int a[20];
int n,num,i,found=0;
printf("Enter number of elements: ");
scanf("%d",&n);
printf("Enter the elements: \n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
printf("Enter the element to be searched: \n");
scanf("%d",&num);
for(i=0;i<n;i++)
{
	if(a[i]==num){
	printf("Element at Location %d\n",i+1);
	found=1;
	break;
}
}
if(found==1)
	printf("Element is Present\n");
else
	printf("Element is not found\n");
return 0;
}
