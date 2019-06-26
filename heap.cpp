#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct PriorityQue{
private:
        vector<int> q;
    int PARENT(int i){
        return  i  / 2 ;
    }
    int LEFT(int i){
        return 2 * i ;
    }
    int RIGHT(int i){
        return 2 * i + 1;
    }
    void down_heap(int i){
        // Get the left and right childs of the root i
        int left = LEFT(i);
        int right = RIGHT(i);
        int largest = i;
        // Find the largest leaf
        if(left < q.size() && q[left]> q[i])
            largest = left;
         if(right < q.size() && q[right] > q[i])
             largest = right;
         // Make Swaps
         if (largest !=i){
             swap(q[i], q[largest]);
           
             down_heap(largest);
         }
    }
    void heap_up(int i){
  
        if (q[PARENT(i)] < q[i])
        {
       

            swap(q[i], q[PARENT(i)]);
			
		
			heap_up(PARENT(i));
		}
        
    }

public: 
int size(){
    return q.size();
}
bool empty(){
    return q.size() == 0;

}
void push(int item){
    q.push_back(item);
    int index = size() - 1 ;

    heap_up(index);
}
void pop(){
    if(q.size() == 0){
        cout << "Heap Underflow" << endl;
    }
    //Replace root with last element
    q[0] = q.back();
    q.pop_back();
    
    // Call heapsort in root elem 

    down_heap(0);

}
void priority(){
    if(q.size() == 0){
        cout << "Queue is empty"<<endl;
    }
    else{
        cout<< q.at(0)<< endl ;
    }
}
void disp(){
    for (int i = 0; i < size(); i++)
        cout << q[i] << endl;
}
};


int main(void){
    PriorityQue p;
    p.push(1);
    p.push(2);
    p.push(5);
    p.push(10);
    p.push(11);
    p.priority();

    return 0;
}