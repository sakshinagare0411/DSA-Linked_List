#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node {
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1 , Node* next1 , Node *back1) //constructure
        {
            data = data1;
            next = next1;
            back = back1;

        }
    public:
            Node(int data1) //constructure
            {
                data= data1;
                next = nullptr;
                back = nullptr;
            }
};

Node * convertArr2DLL (vector<int> &arr)
{
    Node * head =new Node(arr[0]);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next =temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

//......................Brut force solution.....................

// Node* reverse(Node* head)
// {
//     Node* temp =head;
//     stack<int>st;
//     while(temp!=NULL)
//     {
//         st.push(temp->data);
//         temp=temp->next;
//     }
//     temp = head;
//     while(temp!=NULL)
//     {
//         temp->data =st.top();
//         st.pop();
//         temp=temp->next;
//     }
//     return head;
// }


Node* reverse (Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
   Node* last=NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        last =curr->back;
        curr->back = curr->next;
        curr->next = last;
        curr = curr->back;
    }
    return last->back;
}

int main()
{
    vector<int> arr= {12,5,4,7};
    Node* head =convertArr2DLL(arr);
    // print(head);
    head =reverse(head);
    print(head);
}