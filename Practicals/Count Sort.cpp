#include <iostream>
using namespace std;

void display(int * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void Count_Sort(int * A,int size){
	int M=A[0];
	for(int i=1;i<size;i++){
		M=max(M,A[i]);
	}
	
	int FA[M+1]={0};
	for(int i=0;i<size;i++){
		FA[A[i]]++;
	}
	
	for (int i=1;i<=M;i++){
		FA[i]=FA[i]+FA[i-1];
	}
	
	
	int *  NA=new int[size];
	
	for (int i=size-1;i>=0;i--){
		NA[FA[A[i]]-1]=A[i];
		FA[A[i]]--;
	}
	
	
	for(int i=0;i<size;i++){
		A[i]=NA[i];
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
	
	Count_Sort(arr,size);

	
	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}
