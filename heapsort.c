#include<stdio.h>
void heapsort(int a[],int n);
void buildheap(int a[],int n);
void extractmax(int a[],int n);
void heapify(int a[],int i, int n);
void swap (int a[],int i, int j);

void heapsort(int a[],int n)
{
//build heap structure
buildheap(a,n);
//extract maxima
extractmax(a,n);
}
void buildheap(int a[],int n)
{
//let heap grow from half size to entire size
for(int i=n/2-1; i>=0; i--)
{
heapify(a,i,n);
}
}
void extractmax(int a[],int n)
{
//n is separator between heap and sorted part
while (n>1)
{
n--;
//put maximum at the end of heap
swap(a,0,n);
//restore heap
heapify(a,0,n);
}
}

//restore heap invariant
void heapify(int a[],int i, int n)
{
int k=2*i+1; //first child of i
while (k<n)
{
//if another child exists and that child is the maximum
if (k+1<n && a[k+1]>a[k]) k++;
if (a[i]>=a[k])
{
return; //heap invariant restored
} 
else
{
//swap element with its child
swap(a,i, k);
//continue with next iteration
i=k;
k=2*i+1;
}
}
}
void swap (int a[],int i, int j)
{
int t;
t= a[i];
a[i] = a[j];
a[j] = t;
}

int main()
{
int size,i;
printf("Enter size of the array: ");
scanf("%d",&size);

int a[size];
printf("Enter %d elements: ",size);
for(i=0;i<size;i++)
scanf("%d",&a[i]);

heapsort(a,size);

printf("Sorted elements: ");
for(i=0;i<size;i++)
printf(" %d",a[i]);

return 0;
}
