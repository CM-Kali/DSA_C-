#include <iostream>
using namespace std;

class PriorityQueue {
private:
    struct Node {
        int data;
        int priority;
    };
    
    Node arr[100];
    int size;
    
public:
    PriorityQueue() {
        size = 0;
    }
    
    // Check if priority queue is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Check if priority queue is full
    bool isFull() {
        return size == 100;
    }
    
    // Insert element with priority
    void enqueue(int value, int priority) {
        if (isFull()) {
            cout << "Priority Queue Overflow!" << endl;
            return;
        }
        
        // Find position to insert (higher priority first)
        int i;
        for (i = size - 1; i >= 0; i--) {
            if (arr[i].priority > priority) {
                arr[i + 1] = arr[i];
            } else {
                break;
            }
        }
        
        arr[i + 1].data = value;
        arr[i + 1].priority = priority;
        size++;
        
        cout << "Enqueued: " << value << " with priority: " << priority << endl;
    }
    
    // Remove highest priority element
    int dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow!" << endl;
            return -1;
        }
        
        int value = arr[0].data;
        
        // Shift all elements left
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
        size--;
        cout << "Dequeued: " << value << " (highest priority)" << endl;
        return value;
    }
    
    // Get highest priority element
    int peek() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return arr[0].data;
    }
    
    // Get priority of highest element
    int peekPriority() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return arr[0].priority;
    }
    
    // Display priority queue
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        
        cout << "Priority Queue (Value[Priority]): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i].data << "[" << arr[i].priority << "] ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value, priority;
    
    cout << "=== PRIORITY QUEUE OPERATIONS ===" << endl;
    cout << "Note: Lower number = Higher priority" << endl;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter priority (lower = higher priority): ";
                cin >> priority;
                pq.enqueue(value, priority);
                break;
                
            case 2:
                pq.dequeue();
                break;
                
            case 3:
                cout << "Highest priority element: " << pq.peek() << endl;
                cout << "Its priority: " << pq.peekPriority() << endl;
                break;
                
            case 4:
                pq.display();
                break;
                
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 5);
    
    return 0;
}
