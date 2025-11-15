#include <iostream>
using namespace std;

// Node class represents each element in the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    
    // Constructor to initialize node
    Node(int value) {
        data = value;
        next =NULL;  // Initially points to nothing
    }
};

// LinkedList class manages the list operations
class LinkedList {
private:
    Node* head;     // Pointer to the first node
    
public:
    // Constructor to initialize empty list
    LinkedList() {
        head = NULL;
    }
    
    // Function to add a node at the end of the list
    void append(int value) {
        // Create a new node
        Node* newNode = new Node(value);
        
        // If list is empty, make new node the head
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        // Traverse to the last node
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // Link the last node to new node
        temp->next = newNode;
    }
    
    // Function to display all elements in the list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "Linked List elements: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList myList;
    int choice, value;
    
    cout << "=== Singly Linked List Operations ===" << endl;
    
    do {
        cout << "\n1. Add element to list\n";
        cout << "2. Display list\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                myList.append(value);
                cout << "Value " << value << " added to list." << endl;
                break;
                
            case 2:
                myList.display();
                break;
                
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 3);
    
    return 0;
}
