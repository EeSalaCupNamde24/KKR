#include <iostream>
using namespace std;

void display(int * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void bubble(int * arr, int n){
	for (int i=0;i<n-1;i++){
		bool flag=false;
		for (int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				flag=true;
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		if (flag==false)
		break;
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
	
	bubble(arr,size);
	
	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}
