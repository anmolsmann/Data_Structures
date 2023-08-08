#include <iostream>
using namespace std;

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<A[i];
    }
}

void insertionSort(int *A, int n){
    int j, key;
    for (int i = 1; i <= n-1; i++) // loop for passes
    {
        cout<<"Number of passes: "<<i<<endl;
        key = A[i]; // loop for each pass
        j = i-1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    
}
int main(){
    int A[] = {4,6,2,8,3,9};
    int n = 6;
    printArray(A, n);
    cout<<endl; 
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}