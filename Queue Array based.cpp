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
        last=size-1;
        length=0;
    }
    void enqueue(T new_element){
        if(length!=size){
            last=(last+1)%size;
            queue[last]=new_element;
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
            left_element=queue[first];
            first=(first+1)%size;
            length--;
            return left_element;
        }
    }
    T First(){
        if(length!=0) {
            return queue[first];
        }else
            throw runtime_error("the queue is empty");

    }
    void print() {
        for (int i = first; i < first + length; i++) {
            cout << queue[i % size] << " ";
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

    queue.print();
    cout<<"\n";
    cout<<queue.First()<<" ";
    cout<<"\n";
    queue.clear();
    cout<<"\n"<<queue.isEmpty()<<" "<<queue.queueSize();



}