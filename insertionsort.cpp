#include<iostream>
using namespace std; 

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }
    cout << "Sorted Array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}  


int main()  
{
    int size = 0;
    cout << "Enter the size you want";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    insertionSort(arr, size);  
  
  
    return 0;  
}  