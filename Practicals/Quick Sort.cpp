#include <iostream>
using namespace std;

void display(int * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

int Partition(int *A,int p,int r){
	int x=A[r];
	int i=p-1;
	for (int j=p;j<r;j++){
		if(A[j]<=x){
			i=i+1;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void quicksort(int * A,int p,int r){
	if(p<r){
		int q=Partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
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
	
	quicksort(arr,0,size-1);
	
	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}
