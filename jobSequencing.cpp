#include<iostream>
using namespace std;

void sort(int p[],int d[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j+1]>p[j])
            {
                swap(p[j+1],p[j]);
                swap(d[j+1],d[j]);
            }
        }
    }
}

int main()
{
    int p[]={100,19,27,25,15};
    int d[]={2,1,2,1,3};
    int n=5;
    int result[n];
    bool slot[n];
    sort(p,d,6);
    for(int i=0;i<n;i++)
    {
        slot[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j= d[i]-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
            result[j]=p[i];
            slot[j]=true;
            break;
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        if(slot[i])
        {
            cout<<result[i]<<endl;
        }
    }
}