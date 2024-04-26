#include <iostream>
#include <cassert>
using namespace std;

class ArrayQueue
{
    int size{};
    int front{0};
    int rear{0};
    int added_elements{};
    int *array{};

public:
    // constructor
    ArrayQueue(int size) : size(size)
    {
        array = new int[size];
    }

    // destructor
    ~ArrayQueue()
    {
        delete[] array;
    }

    int next(int pos)
    {
        ++pos;
        if (pos == size)
            pos = 0;
        return pos;
        // return (pos+1)%size   //or shorter way
    }
    // add element
    void enqueue(int value)
    {
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        added_elements++;
    }

    // delete
    int dequeue()
    {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        --added_elements;
        return value;
    }

    void display()
    {
        cout << "Front " << front << " - rear " << rear << "\t";
        if (isFull())
            cout << "full";
        else if (isEmpty())
        {
            cout << "empty\n\n";
            return;
        }
        cout << "\n";

        for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
            cout << array[cur] << " ";
        cout << "\n\n";
    }

    bool isEmpty()
    {
        return added_elements == 0;
    }

    bool isFull()
    {
        return added_elements == size;
    }
};

int main()
{
    ArrayQueue qu(6);
    assert(qu.isEmpty());
    qu.display();

    for (int i = 1; i <= 6; i++)
    {
        assert(!qu.isFull());
        qu.enqueue(i);
        qu.display();
    }
    assert(qu.isFull());

    for (int i = 1; i <= 6; ++i)
    {
        assert(!qu.isEmpty()); 
        qu.dequeue();
        // qu.display();
    }

    for (int i = 1; i <= 6; ++i)
    {
        assert(!qu.isFull());
        qu.enqueue(i);
        qu.display();
    }

    qu.dequeue();
    assert(!qu.isFull());
    qu.enqueue(7);
    assert(qu.isFull());
    qu.display();

    qu.dequeue();
    qu.dequeue();
    assert(!qu.isFull());
    qu.enqueue(8);
    assert(!qu.isFull());
    qu.display();
    qu.enqueue(9);
    assert(qu.isFull());
    qu.display();

    for (int i = 1; i <= 6; ++i)
    {
        assert(!qu.isEmpty());
        qu.dequeue();
        qu.display();
    }

    return 0;
}