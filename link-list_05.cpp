#include<iostream>
#include<vector>
using namespace std;
struct Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1 ,Node*next1,Node* back1)
        {
            data =data1;
            next=next1;
            back=back1;
        }
    public:
        Node(int data1)
        {
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};

Node* convert2dll (vector<int>&arr)
{
    Node* head =new Node(arr[0]);
    Node* prev =head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp =new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(Node* head)
{
    while(head !=NULL)
    {
        cout<<head->data <<" ";
        head= head->next;
    }
}

Node* addtwonode (Node*t1 ,Node*t2)
{
    Node * dummynode =new Node(-1);
    Node* curr = dummynode;
    Node*temp1 = t1;
    Node* temp2=t2;
    int carry =0;
    while(temp1 !=NULL || temp2!=NULL)
    {
        int sum = carry;
        if(temp1)
        {
            sum  = sum+ temp1->data;
        }
        if(temp2)
        {
            sum = sum+temp2->data;
        }  
        Node* newNode =new Node(sum%10);
        carry =sum/10;

        curr->next = newNode;
        curr=curr->next;

        if(temp1)
        {
            temp1 = temp1->next;

        }
        if(temp2)
        {
            temp2=temp2->next;
        }
    }
    if(carry)
    {
        Node* newnode = new Node(carry);
        curr->next = newnode;
    }
    return dummynode->next;
}
int main()
{
    vector<int> arr1 = {3,5};
    vector<int> arr2 = {4,5,9,9};
    Node* t1= convert2dll(arr1);
    Node* t2=convert2dll(arr2);
    print(t1);
    cout<<"\n";
    print(t2);
    cout<<"\n";
    Node* result = addtwonode(t1,t2);
    print(result);
    // print(head);
}