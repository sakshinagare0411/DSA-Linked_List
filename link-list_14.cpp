
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;        
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data 
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// function to detect loop in linked list

//......................01...Brut force solution.................
// bool detectLoop(Node* head) {
    
//     map<Node*, bool> visitedNodes;

//     Node* current = head;
//     while (current != nullptr)
//     {
//         if (visitedNodes[current])
//         {
//             return true; // Loop detected
//         }

//         visitedNodes[current] = true;
//         current = current->next;
//     }

//     return false; // No loop found
// }

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


int main() {
    // Create a sample linked list
    // with a loop for testing
    
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

    // Check if there is a loop 
    // n the linked list
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}


