#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}
	return -1;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int x = 5;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	if(result == -1){
	cout << "Element is not present in the array"<<endl;
    }
    else{
    cout << "Element is present at index: " << result<<endl;
    }

	return 0;
}
