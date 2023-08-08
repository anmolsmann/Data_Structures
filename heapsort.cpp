#include<iostream>
using namespace std;

void maxHeapify(int a[],int i,int n)
{
	int left,right,largest;
	left=2*i;
	right=2*i+1;
	if(left<=n && a[left]>a[i])
	{largest=left;	
		}	
		else{largest=i;
		}
			
	if(right<=n && a[right]>a[largest])
		{largest=right;	
		}
		
	if(largest!=i)
	
	{	
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
	
	
	maxHeapify(a,largest,n);	
	}
	
}
int Heap_extractmax(int a[],int n)
{
	int max1;
	if(n<1)
	{
		cout<<"Underflow"<<endl;
	}
	max1=a[1];
	a[1]=a[n];
	n=n-1;
	maxHeapify(a,1,n);
	return max1;
	
}
void build_MaxHeap(int a[], int n)
{
	for(int i=(n/2);i>=1;i--)
	{
		
		maxHeapify(a,i,n);
	}
	
}
void heapsort(int a[],int n)
{
	build_MaxHeap(a,n);
	for(int i=1;i<=n; i++)
	{
		cout<<a[i]<<"\t";
	}
	
	for(int i=n;i>=2;i--)
	{
		int temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		n=n-1;
		maxHeapify(a,1,n);
	}
//	maxHeapify(a,i,n);
	
	
}
//Heap_increaseKey(int a[],int n,int i,int key)
//{
//	if(key<a[i])
//	{
//		cout<<"wrong Operation";
//	}
//	a[i]=key;
//	while(i>1 && a[(i/2)]<a[i])
//	{
//		int temp=a[i];
//		a[i]=a[(i/2)];
//		a[(i/2)]=temp;
//		i=i/2;
//	}
//}

int main()
{
	int n,a[20],i,k,key;
	cout<<"enter the number of elements"<<endl;
	cin>>n;
	cout<<"enter the elements"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	heapsort(a,n);
//	build_MaxHeap(a,n);
//	cout<<"enter the index value of increase key"<<endl;
//	cin>>k;
//	cout<<"enter the key value"<<endl;
//	cin>>key;
//	
//	Heap_increaseKey(a,n,k,key);
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
//	int max2=Heap_extractmax(a,n);
//	cout<<"Extract Max=="<<max2;
	return 0;
}