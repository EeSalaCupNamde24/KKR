#include <iostream>
using namespace std;

void display(int * arr,int n){
	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void Max_Heapify(int * A, int i,int Heapsize){
	int L=(2*i)+1;
	int R=(2*i)+2;
	
	int largest=i;
	
	if(L<Heapsize && A[L]>A[largest])
	largest=L;
	
	else
	largest=i;
	
	if(R<Heapsize && A[R]>A[largest])
	largest=R;
	
	if(largest!=i){
		swap(A[i],A[largest]);
		Max_Heapify(A,largest,Heapsize);
	}
}

void Build_Max_Heap(int * A,int Heapsize){
	for(int i=Heapsize/2 - 1;i>=0;i--)
	Max_Heapify(A,i,Heapsize);
}

void Heap_Sort(int * A,int Heapsize){
	Build_Max_Heap(A,Heapsize);
	for(int i=Heapsize-1;i>=0;i--){
		swap(A[0],A[i]);
		Heapsize--;
		Max_Heapify(A,0,Heapsize);
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
	
	Heap_Sort(arr,size);
	
	cout<<"Array after sorting "<<endl;
	display(arr,size);
	
	return 0;
}
