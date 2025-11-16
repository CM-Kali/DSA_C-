#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    // Add node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Value " << value << " added to the end of the list." << endl;
    }
    
    // Add node at the beginning
    void prepend(int value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Value " << value << " added to the beginning of the list." << endl;
    }
    
    // Insert at specific position
    void insertAt(int value, int position) {
        if (position <= 0) {
            prepend(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* current = head;
        int currentPosition = 0;
        
        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        
        if (current == NULL) {
            // Position is beyond the list length, add at end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {
                current->next->prev = newNode;
            } else {
                tail = newNode; // Updating tail if inserting at end
            }
            current->next = newNode;
        }
        cout << "Value " << value << " inserted at position " << position << "." << endl;
    }
    
    // Delete a node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* current = head;
        
        // Find the node to delete
        while (current != NULL && current->data != value) {
            current = current->next;
        }
        
        // If node not found
        if (current == NULL) {
            cout << "Value " << value << " not found in list." << endl;
            return;
        }
        
        // If node to delete is head
        if (current == head) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL; // List becomes empty
            }
        }
        // If node to delete is tail
        else if (current == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        // If node is in the middle
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        
        delete current;
        cout << "Value " << value << " deleted from list." << endl;
    }
    
    // Search for a value
    bool search(int value) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    // Display list forward
    void displayForward() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "List (Forward): ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Display list backward
    void displayBackward() {
        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "List (Backward): ";
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->prev != NULL) {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << endl;
    }
    
    // Get list length
    int getLength() {
        int length = 0;
        Node* current = head;
        while (current != NULL) {
            length++;
            current = current->next;
        }
        return length;
    }
    
    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Main function for doubly linked list
int main() {
    DoublyLinkedList myList;
    int choice, value, position;
    
    cout << "=== Doubly Linked List Operations ===" << endl;
    
    do {
        cout << "\n1. Add element to end\n";
        cout << "2. Add element to beginning\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Display list forward\n";
        cout << "5. Display list backward\n";
        cout << "6. Delete element\n";
        cout << "7. Search element\n";
        cout << "8. Get list length\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to add at end: ";
                cin >> value;
                myList.append(value);
                break;
                
            case 2:
                cout << "Enter value to add at beginning: ";
                cin >> value;
                myList.prepend(value);
                break;
                
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                myList.insertAt(value, position);
                break;
                
            case 4:
                myList.displayForward();
                break;
                
            case 5:
                myList.displayBackward();
                break;
                
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.deleteNode(value);
                break;
                
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                if (myList.search(value)) {
                    cout << "Value " << value << " found in list." << endl;
                } else {
                    cout << "Value " << value << " not found in list." << endl;
                }
                break;
                
            case 8:
                cout << "List length: " << myList.getLength() << endl;
                break;
                
            case 9:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 9);
    
    return 0;
}
