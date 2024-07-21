#include <stdio.h>  

void selectionSort(int arr[], int n)  
{  
    for (int i = 0; i < n-1; i++)  
    {  
        int minIdx = i;  
        for (int j = i+1; j < n; j++)  
            if (arr[j] < arr[minIdx])  
                minIdx = j;  
  
        // Swap the found minimum element with the first element  
        int temp = arr[minIdx];  
        arr[minIdx] = arr[i];  
        arr[i] = temp;  
    }  
}  

void printArray(int arr[], int size)  
{  
    for (int i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  

int main()  
{  
    int arr[] = { 12, 31, 25, 8, 32, 17 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Before sorting, array elements are:\n");  
    printArray(arr, n);  
    selectionSort(arr, n);  
    printf("After sorting, array elements are:\n");  
    printArray(arr, n);  
    return 0;  
}  