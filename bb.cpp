#include<iostream>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int main()
{
if(fork()||fork())
{
fork();
}
cout<<"hello";
return 0;
}
