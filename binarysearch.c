#include<stdio.h>
#include <stdlib.h>

int binarysearch(int arr[],int l, int r ,int x){
    int mid = l + (r - 1) / 2;
    if (arr[mid] == x)
    {
        return mid;
   }
    if(arr[mid]>x){
       return binarysearch( arr,  l,  arr[mid - 1],x);
   }
    if(arr[mid] <x){
       return binarysearch( arr,  arr[mid + 1],  r,x);

   }
   return -1;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int ans = binarysearch(arr, 0, size-1, 1);
    (ans == -1 ) ? printf("\n Elem not found ") : printf("\n Elem found");
    return 0;
}