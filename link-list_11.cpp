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

//Add 1 to link list
//.......................brut force solution.................................
// Node* add(Node* head)
// {
   
//     head= reverse(head);
//     Node* temp =head;
//     int carry =1;
//     while( temp !=NULL)
//     {
//         temp->data =temp->data+carry;
//         if(temp->data < 10)
//         {
//             carry =0 ;
//             break;
//         }
//         else{
//             temp->data = 0;
//             carry=1;
//         }
//         temp =temp->next;
//     }
     
//      if(carry ==1)
//      {
//         Node* newhead =new Node(1);
//         head = reverse(head);
//         newhead->next = head;
//        return newhead;

//      }
//     head = reverse(head);
//      return head;
// }


//.........................................optimized solution recursive solution..........................
int helper(Node* temp)
{
    if(temp ==NULL)
    {
        return 1 ;

    }
     int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data ==0 )
    {
        return 0;
    }
    temp->data =0;
    return 1;
}


Node* add(Node* head)
{
    int carry = helper(head);
    if(carry ==1)
    {
        Node* newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    return head;
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
    vector<int> arr = {9,9,9,9,9};
    Node* head = convertarr1ll(arr);
    print(head);
    cout << "\n";
  head = add(head);
   print(head);
   
    return 0;
}
