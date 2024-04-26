//data_structure.cpp : Defines the entry point for the application.
#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class ciculare_linked_list {
private:
    Node* head, * tail;
    int sz;
public:
    ciculare_linked_list() {
        cout << "the circular linked list is zero based\n";
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }
    void InsertAtHead(int data) {
        Node* newnode = new Node(data);

        if (head == nullptr) {
            head = newnode;
            tail = newnode;
            newnode->next = head;
        }
        else {
            newnode->next = head;
            tail->next = newnode;
            head = newnode;
        }
        sz++;
    }
    void InsertAtTail(int data) {
        Node* newnode = new Node(data);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
            newnode->next = head;
        }
        else {
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
        sz++;
    }
    void InsertAt(int data, int index) {
        int count = 0;
        if (index == 0) {
            InsertAtHead(data);
        }
        else {
            Node* temp = head, * previous;
            do {
                previous = temp;
                temp = temp->next;
                count++;
            } while (temp != head && count != index);
            if (count == index) {
                Node* newnode = new Node(data);
                newnode->next = temp;
                previous->next = newnode;
            }
            sz++;
        }
    }
    void RemoveAtHead() {
        if (head == nullptr) {
            cout << "cannot remove because ,list is empty\n";
        }
        else {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
            sz--;
        }

    }
    void RemoveAtTail() {
        if (head == nullptr) {
            cout << "cannot remove because ,list is empty\n";
        }
        else {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                temp->next = head;
                delete tail;
                tail = temp;
            }
        }
        sz--;
    }
    void RemoveAt(int index) {
        int count = 0;
        if (index == 0) {
            RemoveAtHead();
        }
        else if (index > sz)cout << "index not exist\n";
        else if (index == sz - 1)RemoveAtTail();
        else {
            Node* temp = head, * previous;
            do {
                previous = temp;
                temp = temp->next;
                count++;
            } while (temp != head && count != index);
            if (count == index) {
                previous->next = temp->next;
                delete temp;
            }
            sz--;
        }
    }
    int RetrieveAt(int index) {
        int count = 0;
        if (index == 0)return head->data;
        else if (index > sz - 1)return -1;
        else {
            Node* temp = head;
            do {
                temp = temp->next;
                count++;
            } while (temp != head && count != index);
            if (index == count) {
                return temp->data;
            }
        }
    }
    void ReplaceAt(int data, int index) {
        int count = 0;
        if (index == 0) head->data = data;
        else if (index > sz - 1)cout << "index Not Exist\n";
        else {
            Node* temp = head;
            do {
                temp = temp->next;
                count++;
            } while (temp != head && count != index);
            if (index == count) {
                temp->data = data;
            }
        }
    }
    bool IsExist(int data) {
        if (head == nullptr) {
            return false;
        }
        else {
            Node* temp = head;
            bool f = false;
            do {
                if (temp->data == data)f = true;
                temp = temp->next;
            } while (temp != head && f == false);
            return f;
        }
    }
    bool IsItemAtEqual(int data, int index) {
        if (index == 0)return (head->data == data);
        else if (index == sz - 1)return (tail->data == data);
        else if (index > sz - 1)return 0;
        else {
            Node* temp = head;
            int count = 0;
            do {
                temp = temp->next;
                count++;
            } while (temp != head && count != index);
            if (index == count) {
                return temp->data == data;
            }
        }
    }
    bool IsEmpty() {
        return sz == 0;
    }
    int LinkedListSize() {
        return sz;
    }
    void Clear() {
        if (!IsEmpty()) {
            Node* temp = head;
            Node* next = nullptr;
            while (temp != nullptr) {
                next = temp->next;
                delete temp;
                temp = next;
            }
        }
        head = nullptr;
        tail = nullptr;
    }
    void print() {
        if (head == nullptr)cout << "liked list is empty\n";
        else {
            Node* temp = head;
            do {
                cout << temp->data << '\n';
                temp = temp->next;
            } while (temp != head);
        }

    }
    void swapNodes(int data1, int data2) {
        if (data1 == data2) return;

        Node *prev1 = nullptr, *curr1 = head;
        Node *prev2 = nullptr, *curr2 = head;

        // Find the nodes containing data1 and data2
        while (curr1 != nullptr && curr1->data != data1) {
            prev1 = curr1;
            curr1 = curr1->next;
            if (curr1 == head) break; // Exit loop if back to head
        }
        while (curr2 != nullptr && curr2->data != data2) {
            prev2 = curr2;
            curr2 = curr2->next;
            if (curr2 == head) break; // Exit loop if back to head
        }

        if (curr1 == nullptr || curr2 == nullptr || (curr1 == head && curr2 == head)) return;

        if (prev1 != nullptr)
            prev1->next = curr2;
        else
            head = curr2;

        if (prev2 != nullptr)
            prev2->next = curr1;
        else
            head = curr1;

        // Swap next pointers of the nodes
        Node* temp = curr2->next;
        curr2->next = curr1->next;
        curr1->next = temp;

        // Update tail pointer if necessary
        if (tail == curr1)
            tail = curr2;
        else if (tail == curr2)
            tail = curr1;
    }

};
class double_pointer_Node {
public:
    int data;
    double_pointer_Node* next;
    double_pointer_Node* prev;
    double_pointer_Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

};
int main()
{
    ciculare_linked_list x;
    x.InsertAtHead(1);
    x.InsertAtHead(2);
    x.InsertAtTail(3);
    x.InsertAtTail(4);
    x.InsertAtTail(5);
    x.InsertAtTail(6);
    x.InsertAtTail(20);
    x.InsertAtTail(55);
    x.InsertAt(22, 5);
    x.print();
    x.RemoveAtTail();
    x.RemoveAtTail();
    cout << "///////////////////////\n";
    x.print();
    cout << "size:" << x.LinkedListSize() << '\n';
    x.RemoveAt(6);
    x.RemoveAt(0);
    x.RemoveAt(3);
    x.RemoveAt(6);
    cout << "///////////////////////\n";
    x.print();
    cout << "///////////////////////\n";
    cout << x.RetrieveAt(3) << '\n';
    cout << x.RetrieveAt(1) << '\n';
    cout << x.RetrieveAt(10) << '\n';
    cout << "///////////////////////\n";
    x.ReplaceAt(100, 0);
    x.ReplaceAt(1000, 2);
    x.ReplaceAt(2000, 6);
    cout << x.IsExist(2000) << ' ';
    cout << x.IsExist(100) << ' ';
    cout << x.IsItemAtEqual(100, 0) << '\n';
    cout << x.IsItemAtEqual(5, 3) << '\n';
    x.print();
    x.swapNodes(200, 1000);
    cout<<"****************\n";
    x.print();
}