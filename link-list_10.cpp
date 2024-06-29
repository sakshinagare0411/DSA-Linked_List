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

//Check if linked have palindrom or not

// bool palindrome (Node* head)
// {
//     Node* temp =head;
//     stack<int> st;
//     while( temp != NULL)
//     {
//         st.push(temp->data);
//         temp=temp->next;
//     }
//     temp=head;
//     {
//         while(temp!=NULL)
//         {
//             if(temp->data !=st.top())
//             {
//                return false;
//             }
//                st.pop();
//         temp = temp->next;
//         }
//         return true;
//     }
// }
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

bool palindrome (Node* head)
{
    Node* slow =head;
    Node*fast=head;
    while(fast->next !=NULL && fast->next->next !=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newhead =reverse(slow->next);
    Node*first =head;
    Node* second = newhead;
    while(second!=NULL)
    {
        if(first->data != second->data)
        {
            reverse(newhead);
            return false;
        }
        first =first->next;
        second =second ->next;

    }
    reverse(newhead);
    return true;
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
    vector<int> arr = {1,2,3,2,1};
    Node* head = convertarr1ll(arr);
    print(head);
    cout << "\n";
    if(palindrome(head))
    {
        cout<<"palidrome";
    }
    else{
        cout<<"no palindrome";
    }
  
    return 0;
}
