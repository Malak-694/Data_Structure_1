#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_SIZE = INT_MAX;

template <class T>
class StackArray {
    int top;
    int capacity;
    T stack[MAX_SIZE];

public:
    StackArray(int cap) : top(-1), capacity(cap) {}

    void push(const T& new_element) {
        if (top >= capacity - 1) {
            throw overflow_error("Stack overflow: Cannot push to a full stack");
        }
        stack[++top] = new_element;
    }

    T pop() {
        if (top < 0) {
            throw underflow_error("Stack underflow: Cannot pop from an empty stack");
        }
        return stack[top--];
    }

    const T& TOP() const {
        if (top < 0) {
            throw underflow_error("Stack is empty: Cannot peek");
        }
        return stack[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    int stackSize() const {
        return top + 1;
    }

    void clear() {
        top = -1;
    }

    void print() const {
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackArray<int> stack(4);
    stack.push(1);
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
