#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5]; // Small size for demonstration
    int front, rear;
    int size;
    
public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }
    
    // Check if queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }
    
    // Add element to queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }
    
    // Remove element from queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue" << endl;
            return -1;
        }
        
        int value = arr[front];
        
        // If only one element was present
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        
        cout << "Dequeued: " << value << endl;
        return value;
    }
    
    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }
    
    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;
    
    cout << "=== CIRCULAR QUEUE OPERATIONS ===" << endl;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
                
            case 2:
                q.dequeue();
                break;
                
            case 3:
                cout << "Front element: " << q.getFront() << endl;
                break;
                
            case 4:
                cout << "Rear element: " << q.getRear() << endl;
                break;
                
            case 5:
                q.display();
                break;
                
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 6);
    
    return 0;
}
