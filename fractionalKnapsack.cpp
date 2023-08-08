#include <iostream>
using namespace std;

class Item{
    public:
    int weight, profit;
    Item(int Weight, int Profit){
        this->weight = Weight;
        this->profit = Profit;
    }
};

static bool cmp(Item a, Item b){
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    return r1>r2;
}

double fractionalKnapsack(int W, Item arr[], int N){
    sort(arr,arr+N,cmp);
    double finalProfit = 0.0;
    for (int i = 0; i < N; i++)
    {
        if(arr[i].weight<=W){
            W -= arr[i].weight;
            finalProfit += arr[i].profit;
        }
        else{
            finalProfit += arr[i].profit * ((double)W/(double) arr[i].weight);
            break;
        }
    }
    return finalProfit;
}

int main(){
    int W = 83;
    Item arr[] = {{15,13},{8,8},{7,4},{10,11},{20,18},{25,15},{18,10},{10,12}};
    int N = 8;
    cout<<fractionalKnapsack(W,arr,N);
    return 0;
}