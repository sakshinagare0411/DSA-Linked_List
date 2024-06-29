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
//Remove the duplicate from the link list

Node* remove(Node*head)
{
    Node*temp = head;
    while(  temp!=NULL && temp->next!=NULL)
    {
        Node*nextnode =temp->next;
        while(nextnode!=NULL  && nextnode->data==temp->data)
        {
            Node* duplicate = nextnode;
                nextnode =nextnode->next;
                delete(duplicate);
        }
        temp->next =nextnode;
        if(nextnode) nextnode->back =temp;
        temp =temp->next;
       
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
    vector<int> arr = {1,1,1,2,3,3};
    Node* head =convertaarll(arr);
    print(head);
    cout<<"\n Remove the duplicate :\n";
    remove(head);
    print(head);
    cout<<"\n";
   
    return 0;

}