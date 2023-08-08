#include <iostream>
#define MAX 4
using namespace std;

int main(){
    int i, j, k=0, size= (MAX*(MAX+1))/2, a[size];
    cout<<"Elements of the row major are: "<<endl;
    for (i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    cout<<"Upper Triangular matrix is: "<<endl;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (i<=j)
            {
                cout<<a[k];
                k++;
            }
            else
            cout<<"0";
        }
        cout<<endl;
    }
    k=0;
    cout<<"Lower Triangular Matrix is: "<<endl;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (i>=j)
            {
                cout<<a[k];
                k++;
            }
            else
            cout<<"0";
        }
        cout<<endl;
    }
    return 0;
}