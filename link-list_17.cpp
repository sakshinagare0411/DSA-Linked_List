#include <iostream>
#include <unordered_set>

using namespace std;

// Node class represents a node in a linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize the node
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert a node at the end of the linked list
void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to create a loop in the linked list
void createLoop(Node *&head, int position)
{
    if (head == nullptr)
        return;
    Node *loopNode = head;
    Node *temp = head;
    int count = 1;
    while (count < position && loopNode->next != nullptr)
    {
        loopNode = loopNode->next;
        count++;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = loopNode;
}
int startNode(Node *slow, Node *head)
{
    Node *ptr1 = head;
    Node *ptr2 = slow;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1->data;
}
int detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return startNode(slow, head);
    }
    return 0;
}



// Function to display the linked list
void display(Node *head)
{
    Node *temp = head;
    unordered_set<Node *> visited;
    while (temp != nullptr)
    {
        // Check if we've seen this node before to avoid infinite loop
        if (visited.find(temp) != visited.end())
        {
            cout << temp->data << " -> ... (loop detected)" << endl;
            return;
        }
        cout << temp->data << " -> ";
        visited.insert(temp);
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    Node *head = nullptr;

    // Inserting nodes into the linked list
    insert(head, 1);
    insert(head, 2);
    insert(head, 15);
    insert(head, 4);
    insert(head, 13);
    insert(head, 6);
    insert(head, 15);
    insert(head, 8);
    insert(head, 9);

    // Display the linked list before creating a loop
    cout << "Linked list before creating a loop:" << endl;
    display(head);

    // Creating a loop in the linked list at position 3
    createLoop(head, 3);

    // Detecting the loop and displaying the starting node
    int start = detectLoop(head);
    if (start != 0)
    {
        cout << "Loop detected in the linked list." << endl;
        display(head);
        cout << "Starting node of the loop: " << start << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}


//.......................01...Brut force solution................
// int startnode(Node* head) {
//    map<Node*,int> mapp;
//   Node* temp =head;
//   while(temp!=NULL)
//   {
//     if(mapp.find(temp) !=mapp.end())
//     {
//         return temp->data;
//     }
//     mapp.insert(make_pair(temp,1));
//     temp=temp->next;
//   }
//   return 0;

// }