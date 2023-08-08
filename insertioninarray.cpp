#include <iostream>
using namespace std;

void insertElement(int arr[], int n, int x, int pos)
{
	for (int i = n - 1; i >= pos; i--)
		arr[i + 1] = arr[i];

	arr[pos] = x;
}

int main()
{
	int arr[] = { 2, 4, 1, 8, 5 };
	int n = 5;

	cout<<"Before insertion : "<<endl;
	for (int i = 0; i < n; i++)
		cout<<" "<<arr[i];

	cout<<endl;

	int x = 10, pos = 2;

	insertElement(arr, n, x, pos);
	n++;

	cout<<"After insertion : "<<endl;
	for (int i = 0; i < n; i++)
		cout<<" "<<arr[i];

	return 0;
}

