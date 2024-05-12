#include <iostream>
using namespace std;

void display(int * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void merge(int * arr,int start,int mid,int end){
	int l=mid-start+1;
	int r=end-mid;
	int * L= new int [l];
	int * R= new int [r];
	
	memcpy(L,arr+start,l*4);
	memcpy(R,arr+mid+1,r*4);
	
	int i=0; int j=0;int k=start;
	
	while(i<l && j<r){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	if(i==l){
		while(j<r){
			arr[k]=R[j];
			k++;
			j++;
		}
	}
	
	else{
		while(i<l){
			arr[k]=L[i];
			i++;
			k++;
		}
	}
}

void mergesort(int * arr,int start,int end){
	if (start<end){
		int mid=(start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid,end);
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
	

	mergesort(arr,0,size-1);

	
	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}
