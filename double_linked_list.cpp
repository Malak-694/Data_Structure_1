#include <iostream>
using namespace std ;
template<typename T>
struct node{
    T data ;
    node<T> *prev;
    node<T> *next;
    node(T Data){
        data= Data;
        prev=NULL;
        next=NULL;
    }
};
template<class T >
class double_linked_list{
protected:
    node<T> *first ;
    node<T> *tail ;
    int size;
public:
    double_linked_list(){
        first = NULL;
        tail =NULL;
        size = 0;
    };
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertA(T element,int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T element , int index);
    bool isExist(T element);
    bool isItemAtEqual(T element , int index);
    void swap(int firstItemIdx , int secondItemIdx);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
};
//--------------------------------------------//
template<typename T>
void double_linked_list<T>::insertAtHead(T element) {
    node<T> *newnode = new node(element);
//    if(size!=0){

//    }
//    first = newnode;

    if(size==0){
        first = newnode;
        tail = newnode;
    }
    else{
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
    size++;

}
//----------------------------------------------//
template<typename T>
void double_linked_list<T>::insertAtTail(T element) {
    node<T> *newnode  = new node(element) ;

    if(size!=0){
        newnode->prev = tail;
        tail->next = newnode;
        tail=newnode;
    } else insertAtHead(element);
    size++;
}
//-----------------------------------------------//
template<typename T>
void double_linked_list<T>::insertA(T element, int index) {
    if(index==0) {
        insertAtHead(element);
    }else if(index == size){
        insertAtTail(element);
    }
    else if (index<0||index>size){
        cout<<"invalid index\n";
    }
    else{
        node<T> *current ,*newnode  = new node(element) ;
        current=first->next;
        int count=1;
        while (count!=index) {
            current = current->next;
            count++;
        }
        newnode->next=current;
        newnode->prev=current->prev;
        current->prev->next = newnode;
        current->prev = newnode;
        size++;
    }
}
//--------------------------------------------//
template<typename T>
void double_linked_list<T>::removeAtHead() {
    node<T> *temp;
    temp=first;
    if(size==0) {
        cout << "the list is empty\n";
    }
    else if (size==1){
        first = NULL;
        tail = NULL;
        delete temp;
        size--;
    }
    else{
        first=first->next;
        first->prev=NULL;
        delete temp;
        size--;
    }
}
//---------------------------------------------//
template<typename T>
void double_linked_list<T>::removeAtTail() {
    node<T> *removedNode;
    removedNode=tail;
    if(isEmpty()) {
        cout<<"the list is empty\n";
    }
    else if(size==1){
        removeAtHead();
    }
    else {
        tail=tail->prev;
        tail->next=NULL;
        delete removedNode;
        size--;
    }
}
//--------------------------------------------//
template<typename T>
void double_linked_list<T>::removeAt(int index) {
    node<T> *removedNode ;
    if(index==0){
        removeAtHead();
    }
    else if(index==size-1){
        removeAtTail();
    }
    else {
        removedNode = first->next;
        int count=1;
        while (count!=index){
            removedNode=removedNode->next;
            count++;
        }
        removedNode->next->prev = removedNode->prev;
        removedNode->prev->next = removedNode->next;
        delete removedNode;
        size--;
    }
}
//--------------------------------------------//
template<typename T>
bool double_linked_list<T>::isEmpty() {
    if(size==0) return true;
    else return false;
}
//--------------------------------------------//
template<typename T>
int double_linked_list<T>::linkedListSize() {
    return size;
}
//-------------------------------------------//
template<typename T>
void double_linked_list<T>::print() {
    node<T> *current ;
    current = first;
    if(isEmpty()) cout<<"list is empty\n";
    else {
        while (current!=NULL){
            cout<<current->data<<' ';
            current=current->next;
        }
        cout<<'\n';
    }

}
//------------------------------------------//
template<typename T>
void double_linked_list<T>::clear() {
    node<T> *current ;
    current=first;
    while (current!=NULL){
        first=current->next;
        delete current;
        current=first;

    }
    size=0;
    tail=NULL;

}
//-----------------------------------------//
template<typename T>
T double_linked_list<T>::retrieveAt(int index) {
    node<T> *neededNode;
    neededNode = first;
    if(index<0||index>=size){
        cout<<"invalid index\n";
        return 0;
    }
    else {
        int count = 0;
        while (count != index) {
            neededNode = neededNode->next;
            count++;
        }
        return neededNode->data;
    }
}
//-------------------------------------------//
template<typename T>
void double_linked_list<T>::replaceAt(T element, int index)  {
    node<T> *neededNode;
    neededNode = first;
    if(index<0||index>size){
        cout<<"invalid index\n";
        return ;
    }
    else {
        int count = 0;
        while (count != index) {
            neededNode = neededNode->next;
            count++;
        }
        neededNode->data = element;
    }
}
//------------------------------------------//
template<typename T>
bool double_linked_list<T>::isExist(T element) {
    node<T> *neededNode ;
    neededNode = first;
    while (neededNode->next != NULL) {
        neededNode = neededNode->next;
        if(neededNode->data == element) break;
    }
    if(neededNode->data==element) return true;
    return false;
}
//------------------------------------------//
template<typename T>
bool double_linked_list<T>::isItemAtEqual(T element, int index) {
    node<T> *neededNode;
    neededNode = first;
    if(index<0||index>size){
        return 0 ;
    }
    else {
        int count = 0;
        while (count != index) {
            neededNode = neededNode->next;
            count++;
        }
        if( neededNode->data == element) return true;
    }
}
//---------------------------------------------------//
template<typename T>
void double_linked_list<T>::swap(int firstItemIdx, int secondItemIdx) {
    int mini = min(firstItemIdx , secondItemIdx);
    int maxx = max(firstItemIdx , secondItemIdx);
    if (firstItemIdx>=size || firstItemIdx<0 || secondItemIdx>=size || secondItemIdx<0 ){
        cout<<"invalid index\n";
    }
    else {
        int count =0 ;
        node<T> *temp , *current = first;
        while (count!=maxx){
            if(count == mini){
                temp = current;
            }
            current = current->next;
            count++;
        }
        node<T> *tempprev = temp->prev,*tempext = temp->next ;
        if(temp->prev)  temp->prev->next = current ;
        if(current->next) current->next->prev = temp ;
        if (temp->next==current) {
            temp->next = current->next;
            current->prev = temp->prev ;
            temp->prev = current;
            current->next = temp ;
        }
        else {
            temp->next = current->next;
            temp->prev = current->prev;
            current->prev->next = temp;
            current->prev = tempprev;
            current->next = tempext;
            tempext->prev = current;
        }
        if(maxx==size-1) tail = temp ;
        if(mini == 0) first = current;
    }
}
//----------------------------------------------------//

int main(){
    double_linked_list<int> list;
    list.insertAtHead(5);
    list.insertAtTail(10);
    list.insertA(7, 1);

    cout << "List : ";
    list.print();

    int element = list.retrieveAt(1);
    cout << "Element at index 1: " << element << endl;

    cout << "replacement index 1 to be 8: ";
    list.replaceAt(8, 1);
    list.print();

    cout << "Is 10 present in the list? " << (list.isExist(10) ? "Yes" : "No") << endl;

    cout << "swapping index 0 and 2 : ";
    list.swap(0, 2);
    list.print();

    list.removeAtHead();
    list.removeAtTail();
    list.removeAt(0);

    cout << "List after removal: ";
    list.clear();
    cout << "List cleared." << endl;
}