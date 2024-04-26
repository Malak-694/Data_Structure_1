#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node {
    T info;
    Node<T>* next;
};

template <class T>
class StackList {
    Node<T>* top;
    int length;

public:
    StackList() : top(nullptr), length(0) {}

    void push(const T& new_element) {
        Node<T>* new_node = new Node<T>;
        new_node->info = new_element;
        new_node->next = top;
        top = new_node;
        length++;
    }

    T pop() {
        if (isEmpty()) {
            throw runtime_error("Cannot pop from an empty stack");
        }
        Node<T>* temp = top;
        T value = top->info;
        top = top->next;
        delete temp;
        length--;
        return value;
    }

    T TOP() const {
        if (isEmpty()) {
            throw runtime_error("Cannot get top value from an empty stack");
        }
        return top->info;
    }

    void print() const {
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() const {
        return length == 0;
    }

    int stackSize() const {
        return length;
    }

    void clear() {
        while (!isEmpty()) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
            length--;
        }
    }

    ~StackList() {
        clear();
    }
};

int main() {
    StackList<int> stack;stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << "Stack content: ";
    stack.print();

    stack.pop();
    stack.pop();

    cout << "After popping: ";
    stack.print();

    cout << "the top element: "<<stack.TOP()<<"\n";

    stack.clear();
    cout << "After clearing: ";
    stack.print();

    cout << "Stack size: " << stack.stackSize() << endl;
    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
