#include <iostream>
using namespace std;
const int MAX=100;
template <class T>
class queue_array{
    int first;
    int length;
    int last;
    int size;
    T queue[MAX];
public:
    queue_array(int s){
        size=s;
        first=0;
        last=0;
        length=0;
    }
    void enqueue(T new_element){
        if(length!=size){
            queue[last++]=new_element;
            length++;
        }else{
            throw runtime_error("Cannot enqueue to an queue that is full");
        }
    }
    T dequeue(){
        if(length==0){
            throw runtime_error("Cannot dequeue from an empty queue");
        }else{
            T left_element;
            left_element=queue[last--];
            length--;
            return left_element;
        }
    }
    void print() {
        for (int i = length-1; i >=0; i--) {
            cout << queue[i ] << " ";
        }
    }

    bool isEmpty(){
        if(length==0) return true;
        else return false;
    }
    int queueSize(){
        return length;
    }
    void clear(){
        length=0;
    }
};
int main(){
    queue_array<int> queue(4);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.print();
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(5);
    queue.enqueue(6);
    cout<<"\n";
    queue.print();
    queue.clear();
    cout<<"\n"<<queue.isEmpty()<<" "<<queue.queueSize();



}