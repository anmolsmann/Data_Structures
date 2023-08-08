#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    /* cout<<v[0]<<endl<<v[1]<<endl<<v[2]<<endl;

    v[1] = 100;
    cout<<v[0]<<endl<<v[1]<<endl<<v[2]<<endl;

    cout<< v.at(2);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    */

    for (int i = 0; i < 100; i++)
    {
        v.push_back(i+1);
        cout<<v[i]<<endl;
    }
    
    return 0;
}