#include <iostream>
#include <vector>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

// Optimized solution
Node* sortlist(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);

    Node* zero = zerohead;
    Node* one = onehead;
    Node* two = twohead;
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    // Connecting the zero, one, and two lists
    zero->next = (onehead->next != nullptr) ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = NULL;

    Node* newhead = zerohead->next;

    // Deleting dummy nodes to avoid memory leak
    delete zerohead;
    delete onehead;
    delete twohead;

    return newhead;
}

Node* convertarr1ll(vector<int> &arr)
{
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
    Node* head = convertarr1ll(arr);
    print(head);
    cout << "\n";

    head = sortlist(head); // Update the head to the sorted list
    print(head);

    return 0;
}
