#include <iostream>
using namespace std;

void ArrayTraverse(int* arr, int n){
    int i;
    for (i = 0; i < n; i++)
    {
      cout<<"\t"<<arr[i];
    }
};

int main()
{
    int arr[] = {2, -1, 5, 6, 0, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    ArrayTraverse(arr, n);
    return 0;
}