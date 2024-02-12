	#include <stdio.h>
int t,s;
void display(int arr[],int n)
{
	int i;t++;s=s+4;
	for(i=0;i<n;i++,t++)
	{
		printf("%d ",arr[i]);t++;
	}
}
void insert(int arr[],int n)
{
    int i;t++;s=s+4;
    printf("Enter the elements of the array to be sorted by insertion sort method\n");t++;
	for(i=0;i<n;i++,t++)
	{
		scanf("%d",& arr[i]);t++;
	}
	printf("The array before sorting is: ");t++;
    display(arr,n);t++;
}
void insertionsort(int arr[],int n)
{
	int i,j,key;t++;s=s+3*4;
	for(j=1;j<n;j++,t++)
	{
		key=arr[j];t++;
		i=j-1;t++;
		while (i>=0&&arr[i]>key)
		{
			t++;
			arr[i+1]=arr[i];t++;
			i=i-1;t++;
			arr[i+1]=key;t++;
		}
		t++;
	}
	printf("\nThe array after sorting is: ");t++;
	display(arr,n);t++;
}
int main()
{
	int n;t++;s=s+4;
	printf("Enter the number of elements in the array: ");t++;
	scanf("%d",& n);t++;
	int arr[n];t++;s=s+n*4;
    insert(arr,n);t++;
	insertionsort(arr,n);t++;
	t+=2;
    printf("\nThe time and space cmplexity of the program is %d & %d",t,s);
	return 0;
}