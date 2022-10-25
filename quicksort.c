#include<stdio.h>
void quicksort(int [],int,int);
int main(){
int size,i;
printf("Enter size of the array: ");
scanf("%d",&size);

int a[size];

printf("Enter %d elements: ",size);
for(i=0;i<size;i++)
    scanf("%d",&a[i]);

quicksort(a,0,size-1);
printf("Sorted elements: ");
for(i=0;i<size;i++)
printf(" %d",a[i]);

return 0;
}

void quicksort(int a[],int first,int last){
int pivot,j,temp,i;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(a[i]<=a[pivot]&&i<last)
        i++;
while(a[j]>a[pivot])
        j--;

if(i<j){
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    }
}
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
quicksort(a,first,j-1);
quicksort(a,j+1,last);
}
}
