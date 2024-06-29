#include <iostream>
#include <vector>
#include<stack>
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

//Reverse a link list

//...............Brut force solution....................
// Node* reverse(Node* head)
// {
//     Node* temp =head;
//     stack<int> st;
//     while(temp!=NULL)
//     {
//         st.push(temp->data);
//         temp=temp->next;
//     }
//     temp=head;
//     while(temp!=NULL)
//     {
//         temp->data  =st.top();
//         st.pop();
//         temp=temp->next;
//     }
//     return head;
// }

//............optimized solution.................................
// Node* reverse(Node* head)
// {
//     Node* temp=head;
//     Node* prev=NULL;
//     while( temp!=NULL)
//     {
//         Node* front = temp->next;
//         temp->next = prev;
//         prev = temp ;
//         temp= front;
//     }
//     return prev;
// }

//....................Reverse linked list by Recursive method................
Node* reverse(Node* head)
{
    if( head ==NULL ||head->next ==NULL )
    { return head;}
    Node* newnode = reverse(head->next);
    Node* front = head->next;
    front->next =head ;
    head->next =NULL;
     
     return newnode;
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
    vector<int> arr = {1,3,2,5};
    Node* head = convertarr1ll(arr);
    print(head);
    cout << "\n";
    head=reverse(head);
    print(head);
   
    return 0;
}
