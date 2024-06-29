#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1) // constructure
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1) // constructure
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArrtoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Delete the head of linked list
Node *removeshead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete the tail of linked list

Node *removestail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

// Delete the Kth element of the List
Node *removesk(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    // K=1

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    // K=3
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete (temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;

    // Time complexity O(k)
}

// Delete the element based on value of element

Node *removesE(Node *head, int e)
{
    if (head == NULL)
    {
        return head;
    }

    // K=1

    if (head->data == e)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {

        if (temp->data == e)
        {
            prev->next = prev->next->next;
            delete (temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;

    // Time complexity O(k)
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Insert Element at the head

Node *inserthead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    temp->next = head;
    return temp;
    // time complexity O(1)
}

// Insert element at last

Node *insertlast(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(val);
    temp->next = newnode;
    return head;
}

// Insert at Kth element
Node *insertatk(Node *head, int ele, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(ele);
        }
        else
        {
            return NULL;
        }
    }
    if (k == 1)
    {
        Node *temp = new Node(ele, head);
        return temp;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;

        if (cnt == (k - 1))
        {
            Node *x = new Node(ele);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//Insert the element before the value X
Node* insertbeforex (Node* head , int ele , int val)
{
     if (head == NULL)
    {
        return NULL;
    }
    if (head->data == val)
    {
        Node *temp = new Node(ele, head);
        return temp;
    }
   
    Node *temp = head;
    while (temp->next != NULL)
    {
      

        if (temp->next->data == val)
        {
            Node *x = new Node(ele);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {12, 5, 2, 4};
    // Node* y  = new Node (arr[0]);
    // cout<<y->data;
    Node *head = convertArrtoLL(arr);
    // head = removeshead(head);
    // // print(head);
    // print(head);

    // head = removestail(head);
    // print(head);

    // head = removesk(head , 8);
    // print(head);

    //  head = removesE(head , 5);
    // print(head);

    //  head = inserthead(head , 48);
    // print(head);
    // head = insertlast(head,55);
    // print(head);
    // head = insertatk(head, 63, 2);
    // print(head);
    // head = insertatk(head, 63, 5);
    // print(head);
     head = insertbeforex(head, 555, 5);
    print(head);
}