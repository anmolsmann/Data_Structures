#include <iostream>
#define MAX 4

using namespace std;
int main(){
    int i, j, a[MAX];
    cout<<"Elements of the row major are: "<<endl;
    for (i = 0; i < MAX; i++)
    {
        cin>>a[i];
    }
    cout<<"The matrix is: "<<endl;
    for (i = 0; i < MAX; i++)
    {
       for (j = 0; j < MAX; j++)
       {
            if(i==j)
            cout<<a[i];
            else
            cout<<"0";
       }
       cout<<endl;
    }
    return 0;
}