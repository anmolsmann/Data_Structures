#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int num){
    int i;
    for (i = 0; i < n; i++)
    {
        if(arr[i]==num)
        {
            return i;
        return -1;
        }
    }
};

int main(){
    int arr[]={3,5,7,9};
    int num=7;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<" "<<linearSearch(arr, n, num);
    return 0;
}