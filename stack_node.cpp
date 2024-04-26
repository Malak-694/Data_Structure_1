//
// Created by Malak on 4/23/2024.
//
#include <iostream>
using namespace std;
template <class T>
struct node{
    T info;
    node<T> *next;
};
template <class T>

class Stacklist{
    node<T> *last  ;
    node<T> *first  ;
    int length;
public:
    Stacklist(){
        last= nullptr;
        first= nullptr;
        length=0;
    }
    void enqueue(const T &new_element){
        auto new_node= new node<T>; //allocate memory to new node first
        new_node->info=new_element;
        new_node->next= nullptr;
        if (length==0){
            first = new_node;
            last = first;
        }
        else{
            new_node->next=first;
            first=new_node;
        }
        length++;
    }
    T dequeu (){
        if (length==0){
            throw runtime_error("Cannot dequeue from an empty queue");
        }else{
            node<T>* out_node=first;
            T value = out_node->info;
            first=first->next;
            delete out_node;
            length--;
            return value;
        }
    }
    void print(){
        node<T> *current =first;
        for(int i=0 ; i<length ; i++){
            cout<<current->info<<" ";
            if(i!=length) {
                current = current->next;
            }

        }
    }
    bool isEmpty(){
        return length==0;
    }
    int queueSize(){
        return length;
    }
    void clear(){
        if(!isEmpty()) {
            for (int i = 0; i < length; i++) {
                node<T> *current = first;
                first= first->next;
                delete current;
            }
            length=0;
        }
    }
};
int main() {
    Stacklist <int>q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    q.dequeu();
    q.print();
    cout<<"\n";
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    cout<<"\n"<<q.isEmpty()<<" "<<q.queueSize();
    q.clear();
    q.print();
}
