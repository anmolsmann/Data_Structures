#include <iostream>
using namespace std;
template <typename T, typename V>

class Pair{
    T x;
    V y;
    public: 
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }
    void setY(V y){
        this->y = y;
    }
    V getY(){
        return y;
    }
};

int main(){
    Pair <int, char> p;
    p.setX(100);
    p.setY('a');

    cout<<p.getX()<<" "<<endl<<p.getY()<<" "<<endl;

    Pair<Pair<int,int>,char> p1;
    p1.setY('b');
    Pair<int,int> p2;
    p2.setX(20);
    p2.setY(40);

    p1.setX(p2);
    
    cout<<p1.getX().getX()<<" "<<endl;

    return 0;
}