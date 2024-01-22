#include<stdio.h>
#include<stdlib.h>
void accept(int a[],int n)
{
	int i;
	printf("\nenter %d numbers:\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
}
void heapify(int a[],int n,int i){
	int parent=i;
	int left,right,temp;
	left=(2*i);
	right=(2*i)+1;
	while(left<=n && a[left]>a[parent])
	{
		parent=left;
	}
	while(right<=n && a[right]>a[parent])
	{
		parent=right;
	}
	if(parent != i)
	{
		temp=a[i];
		a[i]=a[parent];
		a[parent]=temp;
		heapify(a,n,parent);
	}
}
void build(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--){
		heapify(a,n,i);
	}
}
void heapsort(int a[],int n)
{
	int i,temp;
	build(a,n);
	printf("\nBuilding Heap:\n");
	display(a,n);
	for(i=n;i>=1;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		printf("\nAfter %d itratation:\n",n+1-i);
		display(a,n);
		printf("\nMax heap tree:\n");
		heapify(a,i-1,1);
		display(a,i-1);
	}
}
void main()
{
	int n;
	printf("Enter how many num array you want to create:\n");
	scanf("%d",&n);
	int a[n];
	accept(a,n);
	printf("\nNoramal array:\n");
	display(a,n);
	heapsort(a,n);
	printf("\n\nSorted array:\n");
	display(a,n);
}
