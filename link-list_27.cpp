                                
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node class to represent
// elements in the linked list
class Node {
public:
    // Data stored in the node
    int data;           
     // Pointer to the next node
    Node *next;        
    // Pointer to a random
    // node in the list
    Node *random;       

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};


// // // Function to clone the linked list
// Node *cloneLL(Node *head){
//     Node* temp = head;
// //     // Create an unordered_map to map original
// //     // nodes to their corresponding copied nodes
//     map<Node*, Node*> mpp;

// //     // Step 1: Create copies of each node
// //     // and store them in the map
//     while(temp != NULL){
// //         // Create a new node with the
// //         // same data as the original node
//         Node* newNode = new Node(temp->data);
// //         // Map the original node to its
// //         // corresponding copied node in the map
//         mpp[temp] = newNode;
// //         // Move to the next node in the original list
//         temp = temp->next;
//     }
    
//     temp = head;
// //     // Step 2: Connect the next and random
// //     // pointers of the copied nodes using the map
//     while(temp != NULL){
// //         // Access the copied node corresponding
// //         // to the current original node
//         Node* copyNode = mpp[temp];
// //         // Set the next pointer of the copied node
// //         // to the copied node mapped to the
// //         // next node in the original list
//         copyNode->next = mpp[temp->next];
// //         // Set the random pointer of the copied node
// //         // to the copied node mapped to the
// //         // random node in the original list
//         copyNode->random = mpp[temp->random];
// //         // Move to the next node
// //         // in the original list
//         temp = temp->next;
//     }
    
// //     // Return the head of the
// //     // deep copied list from the map
//     return mpp[head];
// }



//.........01....Insert node in between 
Node*insert(Node*head)
{
    Node*temp =head;
    while(temp!=NULL)
    {
    Node*copynode = new Node(temp->data);
    copynode->next =temp->next;
    temp->next =copynode;
    temp=temp->next->next;
    }
}

//............02...connecting random pointer
Node*connectrandom(Node*head)
{
    Node*temp =head;
    while(temp!=NULL)
    {
        Node*copynode =temp->next;
         if(temp->random){   
             // Point the copied node's random to the
             // corresponding copied random node
            copynode->random = temp->random->next; 
        }
        else{
             // Set the copied node's random to
             // null if the original random is null
            copynode->random = NULL;   
        }
        temp=temp->next->next;
    }
}

//................03...connecting next pointer
Node*connectnext (Node*head)
{
    Node*temp=head;
    Node*dummy =new Node(-1);
    Node*res = dummy;
    while(temp!=NULL)
    {
        res->next = temp->next;
        temp->next =temp->next->next;
        res=res->next;
        temp=temp->next;
    }
    return dummy->next;
}

//function to clonde the linked list
Node*cloneLL(Node*head)
{
    if(!head)
    {
        return NULL;
    }
    insert(head);
    connectrandom(head);
    return connectnext(head);
}
// Function to print the cloned linked list
void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

// Main function
int main() {
    // Example linked list: 7 -> 13 -> 11 -> 10->1
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    // Assigning random pointers
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next ;
    head->next->next->next->next->random = head;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}
                                
                            