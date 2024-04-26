#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
#include <memory>
#include <numeric>

#define pb push_back
#define ll long long
#define AYA ios_base::sync_with_stdio(false), cin.tie(NULL);
#define all(var) var.begin(), var.end()
#define allr(var) var.rbegin(), var.rend()
#define F first
#define S second
//#define e '\n'
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
const int N = 1e5 + 7;
#include <bits/stdc++.h>
using namespace std;
// Create a node
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node() {
        this->data = 0;
        this->next = nullptr;
    }
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
    Node(T data, Node<T>* next) {
        this->data = data;
        this->next = next;
    }
    //overloading of cout operator
    friend ostream& operator<<(ostream& os, const Node<T>& node) {
        os << node.data;
        return os;
    }
};

// Insertion at tail
template <typename T>
void insertAtTail(T element, Node<T>*& last) {
    if (last == nullptr) {
        last = new Node<T>(element);
        last->next = last; // Circular pointing to itself
    } else {
        Node<T>* new_node = new Node<T>(element, last->next);
        last->next = new_node;
        last = new_node;
    }
}
template <typename T>
void insertAtHead (T element, Node<T>*& last){
    if (last == nullptr) {
        last = new Node<T>(element);
        last->next = last; // Circular pointing to itself
    }
    else {
        Node<T>* new_node = new Node<T>(element, last->next);
        last->next = new_node;
    }
}
template <typename T>
void insertAt (T element, int index,Node<T>*& last){
    if (last == nullptr) {
        last = new Node<T>(element);
        last->next = last; // Circular pointing to itself
    }
    else if (index < 0||index>linkedListSize(last)) return;

    else if (index == 0) insertAtHead(element , last);
    else if (index==linkedListSize(last)) insertAtTail(element , last);
    else{
        int c = 0;
        Node<T>* temp = last->next;
        while (c < index-1){
            temp = temp->next;
            c++;
        }
        Node<T>* new_node = new Node<T>(element, temp->next);
        temp->next = new_node;
    }
}
// Deletion of head
template <typename T>
void deleteHead(Node<T>*& last) {
    if (last == nullptr) {
        return;
    }
    if (last->next == last) {
        delete last;
        last = nullptr;
    } else {
        Node<T>* temp = last->next;
        last->next = temp->next;
        delete temp;
    }
}
template <typename T>
void removeAtTail (Node<T>*&last ) {
    if (last == nullptr) {
        return;
    }
    if (last->next == last) {
        delete last;
        last = nullptr;
    } else {
        Node<T>* temp = last->next;
        while (temp->next != last){
            temp = temp->next;
        }
        temp->next = last->next;
        delete last;
        last = temp;
    }
}
// Deletion of a node
template <typename T>
void removeAt (int index,Node<T>*& last){
    if (last == nullptr)return;
    else if (index < 0||index>linkedListSize(last)) return;

    else if (index == 0) deleteHead(last);
    else if (index==linkedListSize(last)) removeAtTail(last);
    else{
        int c = 0;
        Node<T>* temp = last->next;
        while (c < index-1){
            temp = temp->next;
            c++;
        }
        Node<T>* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}
//retrive at
template <typename T>
Node<T>* retrieveAt (int index , Node<T>* last){
    if (last == nullptr) {
        return nullptr;
    }
    int c =0;
    Node<T>* temp = last->next;
    do {
        c++;
        temp = temp->next;
    } while (c<index-1);
    return temp;
}
//repalce at
template <typename T>
void repalceAt (int index,T New_element , Node<T>* &last){
    if (last == nullptr) {
        return;
    }
    else if (index < 0||index>linkedListSize(last)) return;
    int c =0;
    Node<T>* temp = last->next;
    do {
        c++;
        temp = temp->next;
    } while (c<index-1);
    temp->data = New_element;
}
// Print circular linked list
template <typename T>
void printCircularLinkedList(Node<T>* last) {
    if (last == nullptr) {
        return;
    }
    Node<T>* temp = last->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}
template <typename T>
int linkedListSize (Node<T>* last){
    if (last == nullptr) {
        return 0;
    }
    int c =0;
    Node<T>* temp = last->next;
    do {
        c++;
        temp = temp->next;
    } while (temp != last->next);
    return c;
}
template <typename T>
bool isExist (T element, Node<T>* last){
    if (last == nullptr) {
        return false;
    }
    bool exist = false;
    Node<T>* temp = last->next;
    do {
        if (temp->data == element) {
            exist = true;
            break;
        }
        temp = temp->next;
    } while (temp != last->next);
    return exist;
}
template <typename T>
bool isItemAtEqual (T element, int index,Node<T>* last){
    if (last == nullptr) {
        return false;
    }
    else if (index < 0||index>linkedListSize(last)) return false;
    int c =0 ;
    Node<T>* temp = last->next;
    while (c<index-1){
        temp = temp->next;
        c++;
    }
    if (temp->data == element) return true;
    return false;
}
template <typename T>
bool isEmpty (Node<T>* last){
    if (last == nullptr) {
        return true;
    }
    return false;
}
template<typename T>
void clear(Node<T>*& last) {
    if (last == nullptr) {
        return;
    }
    Node<T>* temp = last->next;
    while (temp != last) {
        Node<T>* next = temp->next;
        delete temp;
        temp = next;
    }
    delete last;
    last = nullptr;
}
// swap two nodes without swapping data.
template <typename T>
void swapNodes(int firstItemIdx, int secondItemIdx, Node<T>*& last){
    int size = linkedListSize(last);
    if (last == nullptr || firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size){
        cout << "Index out of range or list is empty" << endl;
        return;
    }
    else if (firstItemIdx == secondItemIdx){
        return;
    }

    Node<T>* curfir = last->next;
    Node<T>* prefir = nullptr;
    Node<T>* cursec = last->next;
    Node<T>* presec = nullptr;

    for (int i = 0; i < firstItemIdx ; ++i) {
        prefir = curfir;
        curfir = curfir->next;
    }
    for (int i = 0; i < secondItemIdx ; ++i) {
        presec = cursec;
        cursec = cursec->next;
    }

    if (curfir->next == cursec) {
        curfir->next = cursec->next;
        cursec->next = curfir;
        prefir->next = cursec;
        if (curfir == last) last = cursec;
    }
    else if (cursec->next == curfir) {
        cursec->next = curfir->next;
        curfir->next = cursec;
        presec->next = curfir;
        if (cursec == last) last = curfir;
    }
    else {
        prefir->next = cursec;
        presec->next = curfir;
        Node<T>* temp = curfir->next;
        curfir->next = cursec->next;
        cursec->next = temp;
        if (curfir == last) last = cursec;
        else if (cursec == last) last = curfir;
    }
}


int main() {
    Node<int>* last = nullptr;

    // Add elements to the circular linked list
    insertAtTail(1, last);
    insertAtTail(2, last);
    insertAtTail(3, last);
    insertAtHead(4, last);


    // Print the circular linked list
    printCircularLinkedList(last);
    cout <<linkedListSize(last)<<endl;
    insertAt(5, 2, last);
    printCircularLinkedList(last);
    cout <<linkedListSize(last)<<endl;
    insertAt(6, 0, last);
    printCircularLinkedList(last);
    cout <<linkedListSize(last)<<endl;
    // Delete the head of the circular linked list
//    deleteHead(last);
    insertAt(7, 6, last);
    // Print the circular linked list after deletion
    printCircularLinkedList(last);
    cout <<linkedListSize(last)<<endl;
    insertAt(8, 10, last);
    printCircularLinkedList(last);
    cout <<linkedListSize(last)<<endl;
    removeAtTail(last);
    printCircularLinkedList(last);
    cout <<linkedListSize(last)<<endl;
    removeAt(2, last);
    printCircularLinkedList(last);
    cout <<linkedListSize(last)<<endl;
    repalceAt(2, 10, last);
    printCircularLinkedList(last);
//    cout << isExist(2, last)<<endl;
//    cout << isItemAtEqual(5, 3, last)<<endl;
//    cout << isEmpty(last)<<endl;
//    clear(last);
    cout << isEmpty(last)<<endl;
    swapNodes(1,3,last);
    printCircularLinkedList(last);
//    swapNodes(3,1,last);
//    printCircularLinkedList(last);
//    cout << linkedListSize(last)<<endl;
//    swapNodes(0,3,last);
//    printCircularLinkedList(last);
//  swapNodes(3,3,last);
//  printCircularLinkedList(last);
//  swapNodes(3,0,last);
//  printCircularLinkedList(last);
    swapNodes(1,2,last);
    printCircularLinkedList(last);
    swapNodes(2,1,last);
    printCircularLinkedList(last);
    swapNodes(0,4,last);
    printCircularLinkedList(last);
}