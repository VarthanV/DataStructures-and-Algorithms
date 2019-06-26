#include<stdio.h>

int linearsearch(int arr[],int elem,int size){
    
    for (int i = 0; i < size; i++){
        if(arr[i] == elem){
            return 1;
        }

    }
    return -1;
}

int main(){
    int arr[] = {5,10,2,3,4,5,6,7,111,22,1000,100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = linearsearch(arr, 11,size);
    (ans == -1) ? printf("\n Elem not found ") : printf("\n Elem found");
    return 0;


}