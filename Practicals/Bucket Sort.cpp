#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(float * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}


void Bucket_sort(float * arr,int n){
	vector<vector<float> > bucket(n,vector<float>());
	
	for(int i=0;i<n;i++){
		int idx=arr[i]*n;
		bucket[idx].push_back(arr[i]);
	}
	
	for(int i=0;i<n;i++){
		if(!bucket[i].empty()){
			sort(bucket[i].begin(),bucket[i].end());
		}
	}
	
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<bucket[i].size();j++){
			arr[k]=bucket[i][j];
			k++;
		}
	}
}



int main(){
	int size;
	cout<<"Enter the size of the array : ";cin>>size;
	float * arr=new float [size];
	
	for (int i=0;i<size;i++){
		cout<<"Enter the "<<i<<" th element : ";cin>>arr[i];
	}
	
	cout<<"Array before sorting "<<endl;
	display(arr,size);
	

	Bucket_sort(arr,size);
	
	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}
