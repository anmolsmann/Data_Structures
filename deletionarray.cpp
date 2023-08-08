#include <iostream>
using namespace std;

int deleteElement(int arr[], int n, int pos){
    int temp = arr[pos];
    for(int i=pos; i<=n-2 ; i++){
        arr[i] = arr[i+1];
        //n--;
        //return temp;
    }
}
int main(){
    int i;
    int arr[] = {1,3,5,7,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos = 2;

    //for ( i = 0; i < n; i++)
    //{
    //    cout<<" "<<arr[i];
    //}
    
    deleteElement(arr, n, pos);
    n--;

    for (i = 0; i < n; i++)
    {
    cout<<" "<<arr[i];
    }
    
    return 0;
}