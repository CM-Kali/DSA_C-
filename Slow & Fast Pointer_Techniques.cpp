#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = NULL;
    }
    
    // Add node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Create a cycle for testing (connect last node to node at position 'pos')
    void createCycle(int pos) {
        if (head == NULL) return;
        
        Node* temp = head;
        Node* cycleNode = NULL;
        int count = 0;
        
        // Find the node where cycle should start
        while (temp->next != NULL) {
            if (count == pos) {
                cycleNode = temp;
            }
            temp = temp->next;
            count++;
        }
        
        // If position is valid, create cycle
        if (cycleNode != NULL) {
            temp->next = cycleNode;
            cout << "Cycle created at node with value: " << cycleNode->data << endl;
        } else if (pos == 0) {
            temp->next = head;
            cout << "Cycle created at head node." << endl;
        } else {
            cout << "Invalid position for cycle creation." << endl;
        }
    }
    
    // 1. Find Middle of Linked List using Slow & Fast pointers
    Node* findMiddle() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return NULL;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        // Fast moves 2 steps, slow moves 1 step
        // When fast reaches end, slow is at middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // 2. Detect Cycle in Linked List
    bool detectCycle() {
        if (head == NULL) {
            return false;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If they meet, cycle exists
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
    
    // 3. Find Cycle Length
    int findCycleLength() {
        if (head == NULL) {
            return 0;
        }
        
        Node* slow = head;
        Node* fast = head;
        bool cycleDetected = false;
        
        // First detect if cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                cycleDetected = true;
                break;
            }
        }
        
        if (!cycleDetected) {
            return 0; // No cycle
        }
        
        // Now find cycle length
        // Keep fast pointer fixed and move slow until they meet again
        int length = 1;
        slow = slow->next;
        
        while (slow != fast) {
            slow = slow->next;
            length++;
        }
        
        return length;
    }
    
    // 4. Find Start of Cycle
    Node* findCycleStart() {
        if (head == NULL) {
            return NULL;
        }
        
        Node* slow = head;
        Node* fast = head;
        bool cycleDetected = false;
        
        // Detect cycle using Floyd's algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                cycleDetected = true;
                break;
            }
        }
        
        if (!cycleDetected) {
            return NULL; // No cycle
        }
        
        // Reset slow to head
        // Move both pointers one step at a time until they meet
        // Meeting point is the start of cycle
        slow = head;
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
    
    // Display the list (be careful with cycles)
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        // Check for cycle first to avoid infinite loop
        if (detectCycle()) {
            cout << "List contains a cycle. Cannot display fully." << endl;
            return;
        }
        
        cout << "List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Display limited nodes to avoid infinite loops with cycles
    void displayLimited(int maxNodes = 20) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "List (first " << maxNodes << " nodes): ";
        Node* temp = head;
        int count = 0;
        
        while (temp != NULL && count < maxNodes) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        
        if (temp != NULL) {
            cout << "... (cycle or long list)";
        } else {
            cout << "NULL";
        }
        cout << endl;
    }
    
    // Destructor
    ~LinkedList() {
        // For lists with cycles, we need to break the cycle first
        Node* cycleStart = findCycleStart();
        if (cycleStart != NULL) {
            // Find the node before cycle start to break the cycle
            Node* temp = head;
            while (temp != NULL && temp->next != cycleStart) {
                temp = temp->next;
            }
            if (temp != NULL) {
                temp->next = NULL;
            }
        }
        
        // Now safely delete all nodes
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value, position;
    
    cout << "=== Slow & Fast Pointer Techniques Demo ===" << endl;
    
    do {
        cout << "\n1. Add element to list\n";
        cout << "2. Create cycle in list\n";
        cout << "3. Find middle element\n";
        cout << "4. Detect cycle\n";
        cout << "5. Find cycle length\n";
        cout << "6. Find start of cycle\n";
        cout << "7. Display list (limited)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                list.append(value);
                cout << "Value " << value << " added to list." << endl;
                break;
                
            case 2:
                cout << "Enter position to create cycle (0 for head): ";
                cin >> position;
                list.createCycle(position);
                break;
                
            case 3: {
                Node* middle = list.findMiddle();
                if (middle != NULL) {
                    cout << "Middle element: " << middle->data << endl;
                }
                break;
            }
                
            case 4: {
                bool hasCycle = list.detectCycle();
                if (hasCycle) {
                    cout << "Cycle detected in the list." << endl;
                } else {
                    cout << "No cycle detected in the list." << endl;
                }
                break;
            }
                
            case 5: {
                int cycleLength = list.findCycleLength();
                if (cycleLength > 0) {
                    cout << "Cycle length: " << cycleLength << endl;
                } else {
                    cout << "No cycle in the list." << endl;
                }
                break;
            }
                
            case 6: {
                Node* cycleStart = list.findCycleStart();
                if (cycleStart != NULL) {
                    cout << "Cycle starts at node with value: " << cycleStart->data << endl;
                } else {
                    cout << "No cycle in the list." << endl;
                }
                break;
            }
                
            case 7:
                list.displayLimited();
                break;
                
            case 8:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 8);
    
    return 0;
}
