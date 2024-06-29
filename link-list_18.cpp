#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node*back;
public:
    Node(int data1, Node *next1,Node* back1) // constructure
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1) // constructure
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
//Delete the occurance of key in double link list

Node* deletenode(Node* head ,int key)
{
    Node* temp =head;
    while(temp!=NULL)
    {
        if(temp->data ==key)
        {
            if(temp==head)
            {
                head=head->next;
            }
            Node* nextnode= temp->next;
            Node* prevnode= temp->back;
            if(nextnode) nextnode->back =prevnode;
            if(prevnode) prevnode->next =nextnode;
            delete(temp);
            temp=nextnode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
Node* convertaarll(vector<int>&arr)
{
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp =head;
    for(int i=1;i<arr.size();i++)
    {
        Node*newnode =new Node(arr[i],nullptr,temp);
        temp->next = newnode;
        temp=newnode;
    }
    return head;
}
void print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    vector<int> arr = {10,4,10,10,6,10};
    Node* head =convertaarll(arr);
    print(head);
    cout<<"\n";
    head= deletenode(head,10);
    print(head);
    return 0;

}