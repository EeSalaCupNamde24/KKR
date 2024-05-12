#include <iostream>
using namespace std;

void display(int * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void selection(int * arr, int n){
	for (int i=0;i<n-1;i++){
		int maxloc=0;
		for (int j=1;j<=n-i-1;j++){
			if(arr[maxloc]<arr[j])
			maxloc=j;
		}
		int temp=arr[maxloc];
		arr[maxloc]=arr[n-i-1];
		arr[n-i-1]=temp;
	}
}


int main(){
	int size;
	cout<<"Enter the size of the array : ";cin>>size;
	int * arr=new int [size];
	
	for (int i=0;i<size;i++){
		cout<<"Enter the "<<i<<" th element : ";cin>>arr[i];
	}
	
	cout<<"Array before sorting "<<endl;
	display(arr,size);
	
	selection(arr,size);

	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}
