#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *reverse(Node *head)
{

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {

        Node *front = temp->next;

        temp->next = prev;

        prev = temp;

        temp = front;
    }

    return prev;
}
Node *findkthnode(Node *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
Node *reversekthnode(Node *head, int k)
{
    Node *temp = head;
    Node *prevnode = NULL;
    while (temp != NULL)
    {
        Node *kthnode = findkthnode(temp, k);
        if (kthnode == NULL)
        {
            if (prevnode)
                prevnode->next = temp;
            break;
        }
        Node *nextnode = kthnode->next;
        kthnode->next = nullptr;
        reverse(temp);
        if (temp == head)
        {
            head = kthnode;
        }
        else
        {
            prevnode->next = kthnode;
        }
        prevnode = temp;
        temp->next = nextnode;
        temp = nextnode;
    }
    return head;
}
Node *convertarrll(vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newnode = new Node(arr[i]);
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = convertarrll(arr);
    print(head);
    cout << endl;
    int k = 3;
    head = reversekthnode(head, k);
    print(head);
    return 0;
}