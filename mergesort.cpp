
#include<iostream>
using namespace std;
void merge(int *Arr, int start, int mid, int size);
void mergeSort(int *Arr, int start, int end);

int main(){
    int arr[]={5,4,3,2,1};
    mergeSort(arr,0,5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<endl;
    }
    return 0; 
}

void merge(int *Arr, int start, int mid, int size) {



	int i = start, j = mid+1, k = 0;
    int temp[size-start+1];

	while(i <= mid && j <= size) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k++;
            i++;
		}
		else {
			temp[k] = Arr[j];
            k++;
            j++;
		}
	}

	while(i <= mid) {
		temp[k] = Arr[i];
	    k++;
        i++;
	}

	while(j <= size) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}
    for(i = start; i <= size; i += 1) {
		Arr[i] = temp[i - start];
	}




}



void mergeSort(int *Arr, int start, int size) {

	if(start < size) {
		int mid = (start + size) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, size);
		merge(Arr, start, mid, size);
	}
}