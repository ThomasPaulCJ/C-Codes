#include <stdio.h> 
void display(int arr[], int n) { 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
}   
void insert(int arr[], int n) {
    int i;
    printf("Enter the elements of the array to be sorted by merge sort method\n");
    for(i=0;i<n;i++) {
        scanf("%d",& arr[i]);
    }
}
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m;
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++){ 
        L[i] = arr[l + i]; 
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j]; 
    }
    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) { 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        merge(arr, l, m, r);
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
int main() { 
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",& n);
    int arr[n];
    insert(arr,n);
    printf("The array after sorting is: "); 
    display(arr, n); 
    mergeSort(arr, 0, n - 1); 
    printf("\nThe array after sorting is: "); 
    display(arr, n); 
    return 0; 
}