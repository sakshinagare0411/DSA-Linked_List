#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    public:
        int data;
        Node*next;

    public:
        Node(int data1,Node* next1) // constructure
        {
            data=data1;
            next=next1;
        }

     public:
        Node(int data1) // constructure
        {
            data=data1;
            next=nullptr;
        }
};


Node* convertArrtoLL(vector<int> &arr){
    Node* head =new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node (arr[i]);
        mover->next = temp;
        mover = temp;

    }
    return head;
}
int lengthofLL(Node* head)
{
    int cnt = 0;
       Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
int search(Node* head ,int val)
{
       Node* temp = head;
    while(temp)
    {
        if(temp->data ==val )
        {
            return 1;

        }
        temp =temp->next;
    }
return 0;
}

int main()
{
    vector<int>arr = {12,5,2,4};
    // Node* y  = new Node (arr[0]);
    // cout<<y->data;
    Node* head = convertArrtoLL(arr);
    // cout<< head->data;
    // cout<<lengthofLL(head);
    cout<<search(head,2);
}