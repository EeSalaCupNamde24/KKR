# include <iostream>
using namespace std;

void display(int * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void insertion(int * arr, int n){
	for (int i=1;i<n;i++){
		int temp=arr[i];
		int j=i;
		while(j>0 && temp<arr[j-1]){
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=temp;
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
	
	insertion(arr,size);

	
	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}

