
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
struct node{
    T value;
    node *next;
    node() {
        value = 0;
        next = nullptr;
    }
    node(const T &val){
        value = val;
        next= nullptr;
    }
};

template <typename T>
class singleLinkedlist{
private:
    node<T> *head;
    node<T> *tail;
    int size;

public:
    singleLinkedlist(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~singleLinkedlist(){
        clear();
    }
// insert at head
    void insertAtHead(T value){
        node<T>* newNode = new node<T>(value);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
// insert at tail
    void insertAtTail(T value){
        node<T>* newNode = new node<T>(value);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
// insert at
    void insertAt(T value , int index){
        if(index == 0){
            insertAtHead(value);
        }
        else if(index == size){
            insertAtTail(value);
        }
        else if(index > size || index < 0){
            cout << " Index out of the range";
        }
        else{
            node<T> *newNode = new node<T>(value);
            node<T> *prev = nullptr;
            node<T> *current = head;
            for (int i = 0; i < index; ++i) {
                prev = current;
                current = current->next;
            }
            newNode->next = current;
            prev->next = newNode;
            size++;
        }
    }
// remove at head
    void removeAtHead (){
        if (head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = nullptr;
        }
        else{
            node<T> *current = head;
            head = head->next;
            delete current;
        }
        size--;
    }
// remove at tail
    void removeAtTail (){
        if (tail == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        else if(head == tail){
            removeAtHead();
        }
        else{
            node<T> *prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            delete tail;
            tail = prev;
            tail->next = nullptr;
            size--;
        }
    }
// remove at
    void removeAt (int index){
        if(index == 0){
            removeAtHead();
        }
        else if(index == size-1){
            removeAtTail();
        }
        else if(index > size-1 || index < 0){
            cout << "Index out of range" << endl;
         }
        else{
            node<T> *prev = nullptr;
            node<T> *current = head;
            for (int i = 0; i < index; ++i) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            current->next = nullptr;
            delete current;
            size--;
        }
    }
// retrieve at
    T retrieveAt (int index){
        if(index == 0){
            return head->value;
        }
        else if(index == size-1){
            return tail->value;
        }
        else if (index >= size || index < 0){
            cout << "Index out of range" << endl;
            return 0;
        }
        else{
            node<T>* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->value;
        }
    }
// replace at
    void replaceAt (T newElement, int index){
        if (index >= size || index < 0){
            cout << "Index out of range" << endl;
            return ;
        }
        else{
            node<T>* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            current->value = newElement;
        }
    }
// is Exist
    bool isExist(T element){
        node<T>* current = head;
        while (current){
            if (current->value == element){
                return true;
            }
            current = current->next;
        }
        return false;
    }
// is item at equal
    bool isItemAtEqual (T element, int index){
        if (index < 0 || index >= size) {
            cout << "Index out of range" << endl;
            return false;
        }
        node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        if(current->value == element){
            return true;
        }
        return false;
    }
// swap
    void swap (int firstItemIdx, int secondItemIdx){
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size){
            cout << "Index out of range" << endl;
            return;
        }
        else if (firstItemIdx == secondItemIdx){
            return;
        }

        node<T>* curfir = head;
        node<T>* prefir = nullptr;
        node<T>* cursec = head;
        node<T>* presec = nullptr;
        for (int i = 0; i < firstItemIdx; ++i) {
            prefir = curfir;
            curfir = curfir->next;
        }
        for (int i = 0; i < secondItemIdx; ++i) {
            presec = cursec;
            cursec = cursec->next;
        }
        if(firstItemIdx == secondItemIdx+1 || secondItemIdx == firstItemIdx+1){
            if (firstItemIdx < secondItemIdx){
                if (prefir != nullptr){
                    prefir->next = cursec;
                }
                else{
                    head = cursec;
                }
                curfir->next = cursec->next;
                cursec->next = curfir;

            }
            else{
                if (presec != nullptr){
                    presec->next = curfir;
                }
                else{
                    head = curfir;
                }
                cursec->next = curfir->next;
                curfir->next = cursec;
            }

        }

        else{
            node<T>* temp = cursec->next;
            cursec->next = curfir->next;
            curfir->next = temp;

            if (prefir != nullptr){
                prefir->next = cursec;
            }
            else{
                head = cursec;
            }

            if (presec != nullptr){
                presec->next = curfir;
            }
            else{
                head = curfir;
            }

            if (cursec->next == nullptr){
                tail = cursec;
            }
            else if (curfir->next == nullptr){
                tail = curfir;
            }
        }
    }
// is empty
    bool isEmpty(){
        return size == 0;
    }
// linked list size
    int linkedListSize (){
        return size;
    }
// clear
    void clear(){
        while (head){
            removeAtHead();
        }
    }
// print
    void print(){
        node<T>* current = head;
        while (current){
            cout << current->value << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    singleLinkedlist<string> myList;

    myList.insertAtHead("apple");
    myList.insertAtHead("banana");
    myList.insertAtHead("orange");

    myList.insertAtTail("grapes");
    myList.insertAtTail("pineapple");
    myList.insertAtTail("watermelon");

    myList.insertAt("kiwi", 2);

    myList.removeAtHead();

    myList.removeAt(3);

    myList.swap(4, 1);
    myList.swap(0, 1);
    myList.swap(4, 3);

    cout << "Element at index 2: " << myList.retrieveAt(2) << endl;

    myList.replaceAt("strawberry", 1);

    cout << "Is 'orange' in the list? " << (myList.isExist("orange") ? "Yes" : "No") << endl;
    cout << "Is 'strawberry' in the list? " << (myList.isExist("strawberry") ? "Yes" : "No") << endl;

    cout << "Is element at index 3 equal to 'grapes'? " << (myList.isItemAtEqual("grapes", 3) ? "Yes" : "No") << endl;

    cout << "Is the list empty? " << (myList.isEmpty() ? "Yes" : "No") << endl;

    cout << "Size of the list: " << myList.linkedListSize() << endl;

    myList.clear();
}
