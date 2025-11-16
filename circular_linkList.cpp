#include <iostream>
using namespace std;

// Node class for circular linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;
    
public:
    CircularLinkedList() {
        head = NULL;
    }
    
    // Add node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Value " << value << " added to the end of the list." << endl;
    }
    
    // Add node at the beginning
    void prepend(int value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
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
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        
        Node* current = head;
        int currentPosition = 0;
        
        // Traverse to the node before the desired position
        while (current->next != head && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        cout << "Value " << value << " inserted at position " << position << "." << endl;
    }
    
    // Delete a node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* current = head;
        Node* prev = NULL;
        
        // If head node itself holds the value
        if (current->data == value) {
            // If there's only one node
            if (current->next == head) {
                delete current;
                head = NULL;
            } else {
                // Find the last node
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
            }
            cout << "Value " << value << " deleted from list." << endl;
            return;
        }
        
        // Search for the node to be deleted
        prev = current;
        current = current->next;
        while (current != head && current->data != value) {
            prev = current;
            current = current->next;
        }
        
        // If value was not found
        if (current == head) {
            cout << "Value " << value << " not found in list." << endl;
            return;
        }
        
        // Unlink the node from linked list
        prev->next = current->next;
        delete current;
        cout << "Value " << value << " deleted from list." << endl;
    }
    
    // Search for a value
    bool search(int value) {
        if (head == NULL) {
            return false;
        }
        
        Node* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
        
        return false;
    }
    
    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "Circular List: ";
        Node* temp = head;
        do {
            cout << temp->data;
            if (temp->next != head) {
                cout << " -> ";
            }
            temp = temp->next;
        } while (temp != head);
        cout << " -> (back to head)" << endl;
    }
    
    // Get list length
    int getLength() {
        if (head == NULL) {
            return 0;
        }
        
        int length = 0;
        Node* current = head;
        do {
            length++;
            current = current->next;
        } while (current != head);
        
        return length;
    }
    
    // Check if list is circular
    bool isCircular() {
        if (head == NULL) {
            return true;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
    
    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == NULL) {
            return;
        }
        
        Node* current = head;
        Node* nextNode;
        
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

// Main function for circular linked list
int main() {
    CircularLinkedList myList;
    int choice, value, position;
    
    cout << "=== Circular Linked List Operations ===" << endl;
    
    do {
        cout << "\n1. Add element to end\n";
        cout << "2. Add element to beginning\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Display list\n";
        cout << "5. Delete element\n";
        cout << "6. Search element\n";
        cout << "7. Get list length\n";
        cout << "8. Check if list is circular\n";
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
                myList.display();
                break;
                
            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.deleteNode(value);
                break;
                
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                if (myList.search(value)) {
                    cout << "Value " << value << " found in list." << endl;
                } else {
                    cout << "Value " << value << " not found in list." << endl;
                }
                break;
                
            case 7:
                cout << "List length: " << myList.getLength() << endl;
                break;
                
            case 8:
                if (myList.isCircular()) {
                    cout << "The list is circular." << endl;
                } else {
                    cout << "The list is not circular." << endl;
                }
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
