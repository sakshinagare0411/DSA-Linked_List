#include<iostream>
#include<vector>
using namespace std;
struct Node{
    public:
        int data;
        Node* next;
        
    public:
        Node(int data1,Node* next1,Node*back1)
        {
            data=data1;
            next=next1;
          
        }
        Node(int data1)
        {
            data=data1;
            next=nullptr;
           
        }
};

//.............................brut force solution........................

// Node*oddenevlist(Node* head)
// {
//     if(head ==NULL || head->next ==NULL)
//     {
//         return head;
//     }
//     vector<int> arr ;

//     Node* temp = head;
//     while(temp!=NULL && temp->next !=NULL)
//     {
//         arr.push_back(temp->data);
//         temp =temp->next->next;

//     }
//     if(temp) arr.push_back(temp->data);
//     temp=head->next;
//      while(temp!=NULL && temp->next !=NULL)
//     {
//         arr.push_back(temp->data);
//         temp =temp->next->next;

//     }
//      if(temp) arr.push_back(temp->data);
//      int i=0;
//      temp=head;
//      while(temp!=NULL)
//      {
//         temp->data = arr[i];
//         i++;
//         temp=temp->next;
//      }
//      return head;
// }

//................optimize solution........................

Node* oddevenlist(Node* head)
{
    if(head ==NULL || head->next ==NULL)
    {
        return head;
    }
    Node*odd = head;
    Node*even =head->next;
    Node* enevehead = head->next;
    while(even !=NULL && even->next !=NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd=odd->next;
        even =even->next; 
    }
    odd->next = enevehead;
    return head;
}
Node*convertArr2ll (vector<int> &arr)
{
    Node*head =new Node(arr[0]);
    Node* prev =head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        prev->next= temp;
        prev=temp;
    }
    return head;
    
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    vector<int> arr={1,3,4,2,5,6};
    Node* head = convertArr2ll(arr);
    print(head);

    cout<<"\n";
    oddevenlist(head);
    print(head);
    return 0;
}