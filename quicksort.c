#include<stdio.h>

void printArr(int* A, int n){
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }

        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i <j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex; //index of pivot after partition
    if(low < high){
    partitionIndex = partition(A, low, high);
    quickSort(A, low, partitionIndex - 1);  //sort left sub array
    quickSort(A, partitionIndex + 1, high); //sort right sub array
    }
}

void main(){
    int a[10], n;
    printf("Enter array length: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("Enter array element: ");
        scanf("%d", &a[i]);
    }
    printArr(a, n);
    quickSort(a, 0, n-1);
    printArr(a, n);


}