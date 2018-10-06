#include<stdio.h>
#include<stdlib.h>

void swap(int *num1, int *num2){

		int temp=*num1;
		*num1=*num2;
		*num2=temp;

}

void heapify(int arr[],int n,int i){
 
	 int left=2*i+1,right=2*i+2,largest=i;// forgot to assign largest to i

	 if (left<n && arr[i]<arr[left])
	 	largest=left;

	 if (right<n && arr[largest]<arr[right])
	 	largest=right;

	 if(largest!=i){
	 	swap(&arr[i],&arr[largest]);
	 	//here we have to write a condition for heapify next.. since the lower part of the heap may get disturbed
	 	heapify(arr,n,largest);
	 }


}

void heapsort(int arr[],int n){

	int i;
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

int main(){

	int i,arr[19]={12,13,10,9,4,5,6,2,1,11,102,56,4201,156,45,18,59,29,0},n=19;
	heapsort(arr,n);
	for (i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}

}