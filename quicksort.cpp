#include <iostream>
using namespace std;

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<A[i];
    }
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    while (A[i] <= pivot)
    {
        i++;
    }
    while (A[j] > pivot)
    {
        j--;
    }
    if(i<j){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    } while(i<j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int low, int high){
    int partitionIndex;

    if(low<high)
    {
    partitionIndex = partition(A, low, high);
    quicksort(A, low, partitionIndex-1); //left subarray
    quicksort(A, partitionIndex+1, high); //right subarray 
    }
}

int main(){
    int A[] = {5,2,3,8,6,9};
    int n = 6;
    printArray(A, n);
    quicksort(A, 0, n-1);
    cout<<endl;
    printArray(A, n);
    return 0;
}