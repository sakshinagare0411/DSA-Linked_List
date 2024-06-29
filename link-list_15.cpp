#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;        
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to detect loop in linked list
// Helper function to find the length of the loop
int findLength(Node* slow, Node* fast) {
    int count = 1;
    fast = fast->next;
    while (slow != fast) {
        count++;
        fast = fast->next;
    }
    return count;
}

bool detectLoop (Node* head)
{
    Node* slow =head;
    Node* fast =head;
    while(fast !=NULL && fast->next !=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast ) return true;
        
    }
    return false;
}


// Function to find the length of the loop
int length(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return findLength(slow, fast);
        }
    }
    return 0;
}


int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // Create a loop
    fifth->next = third; 

   if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
        cout << "Length of the loop: " << length(head) << endl;  // Added text for clarity
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Deleting nodes to free up memory
    // Note: This will not work correctly if there is a loop
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
