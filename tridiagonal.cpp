#include <iostream>
#define MAX 4
using namespace std;
int main(){
    int i, j, k=0, size=3*MAX-2, a[size];
    cout<<"Enter elements (Row Major): "<<endl;
    for (i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    cout<<"The matrix is: "<<endl;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (i-j ==-1 || i-j==0 || i-j == 1)
            {
                cout<<a[k];
                k++;
            }
            else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
    return 0;
}