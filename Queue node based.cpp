#include <iostream>
using namespace std;

// Define the node structure
struct node
{
  int data;   // Data
  node *next; // Pointer to the next node

  // Constructor
  node(int d) : data(d), next(nullptr) {}
};

// Queue class
class Queue
{
  node *front; // Pointer to the start
  node *rear;  // Pointer to the end
  int size;

public:
  // Constructor
  Queue() : front(nullptr), rear(nullptr), size(0) {}

  // Function to check if the queue is empty
  bool isEmpty() const
  {
    return size == 0;
  }

  // function to add an element to the queue
  void enqueue(int data)
  {
    node *newNode = new node(data);
    // check if is empty,both front & rear =newNode
    if (isEmpty())
      front = rear = newNode;
    else
    {
      // otherwise, add the new node to the end and update rear
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }
  // function to remove
  int dequeue()
  {
    // Check if the queue is empty
    if (isEmpty())
    {
      // If the queue is empty, print an error message and return -1
      cout << "Queue is empty, cannot dequeue" << endl;
      return -1;
    }

    // If the queue is not empty, store the data of the node at the front
    int data = front->data;

    // Create a temporary pointer to the node at the front
    node *tmp = front;

    // Move the front pointer to the next node (removing the current front node)
    front = front->next;

    // Delete the node that was at the front
    delete tmp;

    // Decrease the size of the queue
    size--;

    // Return the data of the removed node
    return data;
  }
  // Function to get the size of the queue
  int queueSize() const
  {
    return size;
  }

  // Function to clear the queue
  void clear()
  {
    while (!isEmpty())
    {
      dequeue();
    }
  }

  // Function to print the queue
  void print() const
  {
    if (isEmpty())
    {
      cout << "The queue is empty." << endl;
    }
    else
    {
      node *current = front;
      while (current)
      {
        cout << current->data << " "; // get data
        current = current->next;      // go next
      }
      cout << endl;
    }
  }
  //destructor
  ~Queue(){
    clear();
  }
};

int main()
{
  // Test the Queue implementation
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.print();

  cout << "The delete element is " << q.dequeue() << endl;
  cout << "The delete element is " << q.dequeue() << endl;
  q.print();
  cout << q.isEmpty() << endl;
  q.enqueue(2);
  cout << q.queueSize() << endl;
  q.clear();
  q.dequeue();
  q.print();

  return 0;
}
