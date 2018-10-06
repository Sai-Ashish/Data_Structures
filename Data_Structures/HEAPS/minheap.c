#include<stdio.h>
#include<stdlib.h>

void swap(int *num1, int *num2){

		int temp=*num1;
		*num1=*num2;
		*num2=temp;

}
//function to heapify
void heapify(int arr[], int n, int flag){

	int largest = flag;
	int left = 2*flag +1;
	int right= 2*flag +2;
	int temp;
	
	if(left<n &&  arr[left]>arr[largest])
		largest=left;
	
	if(right<n && arr[right]>arr[largest])
		largest=right;
	
	if(largest!=flag){
		
		swap(&arr[largest],&arr[flag]);
		heapify(arr,n,largest);

	}
}
