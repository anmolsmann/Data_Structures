#include <iostream>
using namespace std;

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<A[i];
    }
}

void selectionSort(int *A, int n){
    int indexofMin, temp;
    cout<<"Running selection sort..."<<endl;
    for (int i = 0; i < n-1; i++)
    {
        indexofMin = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[indexofMin])
            {
                indexofMin = j;
            }
        }  
            temp = A[i];
            A[i] = A[indexofMin];
            A[indexofMin] = temp;
    }
}
int main(){
    int A[] = {2,7,4,9,13,5};
    int n = 6;
    printArray(A, n);
    cout<<endl;
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}