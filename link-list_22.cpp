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

//Rotate the link list

Node*findkthnode (Node*temp ,int k)
{
    int cnt =1;
    while(temp!=NULL)
    {
        if(cnt==k) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}
Node* rotate(Node*head ,int k)
{
    if(head == NULL || k==0) return head;
    int len =0;
    Node*tail = head;
    while(tail->next!=NULL)
    {
        len++;
        tail=tail->next;
    }
    if(k%len ==0)
    {
        return head;
    }
    k = k%len;
    tail->next =head;

    Node*newnode = findkthnode (head , len-k);

    head = newnode->next;
    newnode->next=NULL;

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
    head = rotate(head , 2);
    print(head);
    return 0;
}