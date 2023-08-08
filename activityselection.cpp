#include <iostream>
using namespace std;

void sort(int s[], int f[], int n){
    int i, j;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(f[j]>f[j+1]){
                swap(f[i],f[i+1]);
                swap(s[i],s[i+1]);
            }
        }
    }
}

void maxActivites(int s[], int f[], int n){
    int i,j;
    i=0;
    cout<<i;
    for(j=1;j<n;j++){
        if(s[j]>=f[i]){
            cout<<j<<" ";
            i=j;
        }
    }

}

int main(){
    int s[] = {10,12,25,38};
    int f[] = {15,20,30,48};

    int n = 4;
    sort(f,s,n);
    maxActivites(s,f,n);
    return 0;
}