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
int insert(int arr[],int n)
{
    int i;t++;s=s+4;
    printf("Enter the elements of the array to be sorted by selection sort method\n");t++;
	for(i=0;i<n;i++,t++)
	{
		scanf("%d",& arr[i]);t++;
	}
	printf("The array before sorting is:");t++;
	display(arr,n);t++;
}
void selectionsort(int arr[],int n)
{
	int i, j, min,temp; 
	for (i=0; i<n;i++) 
    	{ 
        	min=i; 
        	for (j=i+1; j<=n;j++) 
        	{
            		if (arr[j]<arr[min]) 
            		{
                		min=j; t++;
             		}
					t++;
         	}
		temp=arr[i];t++;
		arr[i]=arr[min];t++;
		arr[min]=temp;t++;
	}
	printf("\nThe array after sorting is:");t++;
	display(arr,n);t++;
}
int main()
{
	int n,i;t++;s=s+8;
	printf("Enter the number of elements in the array: ");t++;
	scanf("%d",& n);t++;
	int arr[n];t++;s=s+n*4;
    insert(arr,n);t++;
	selectionsort(arr,n);t++;
    t+=2; 
	printf("\nThe time and space cmplexity of the program is %d & %d",t,s);
	return 0;
}