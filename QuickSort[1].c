    #include <stdio.h>
void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]); 
	}
}
void insert(int arr[],int n)
{
    int i;
    printf("Enter the elements of the array to be sorted by quick sort method\n"); 
	for(i=0;i<n;i++)
	{
		scanf("%d",& arr[i]); 
	}
	printf("The array before sorting is: "); 
    display(arr,n); 
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int n;
	printf("Enter the number of elements in the array: "); 
	scanf("%d",& n); 
	int arr[n];
    insert(arr,n); 
    quickSort(arr, 0, n - 1);
    printf("\nThe array after sorting is: ");
    display(arr,n);
    return 0;
}