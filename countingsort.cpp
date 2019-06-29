#include<iostream>
# define RANGE 20
// ? Counting Sort works best in defined range 
using namespace std;
void countsort(char arr[]){
    // ! Output char must be of the range input 
    char out[strlen(arr)];
    // ? Initialize Count array in RANGE +1 ;
    int count[RANGE + 1];
    memset(count, 0, sizeof(count)); //? Populate the array with 0
    for (int i = 0; arr[i]; i++){
        ++count[arr[i]]; // ? Store count of each array
    }
     for(int i = 0; arr[i]; ++i)  
        ++count[arr[i]];  
  
    // Change count[i] so that count[i] now contains actual  
    // position of this character in output array  
    for (int i = 1; i <= RANGE; ++i)  
        count[i] += count[i-1];  
  
    // Build the output character array  
    for (int i = 0; arr[i]; ++i)  
    {  
        out[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  
  
 
    for (int i = 0; arr[i]; ++i){  
        arr[i] = out[i];  
}  
}

int main(void){

    return 0;
}