#include <iostream>
using namespace std;

int arrayMinElement(int arr[], int n){
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]<arr[min]){
        min = i;
        }
        return arr[min];
    }
};

int main(){
    int arr[] = {1,3,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<" "<<arrayMinElement(arr, n);
    return 0;
}