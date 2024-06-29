#include <iostream>
#include <vector>
#include <algorithm>
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

// Sort the link list
// Node *sort1(Node *head)
// {
//     vector<int> arr;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }
//     sort(arr.begin(), arr.end());
//     int i = 0;
//     temp = head;
//     while (temp != NULL)
//     {
//         temp->data = arr[i];
//         i = i + 1;
//         temp = temp->next;
//     }
//     return head;
// }

 Node* findmiddle(Node*head)
 {
    Node* slow = head;
    Node*fast =head->next;
    while(fast!=NULL&& fast->next !=NULL)
    {
        slow=slow->next;
        fast =fast->next->next;

    }
    return slow;
 }

 Node* merge2 (Node*left , Node*right)
 {
    Node*dummy = new Node(-1);
    Node*temp =dummy;
    while(left !=NULL && right !=NULL)
    {
        if(left->data < right->data)
        {
            temp->next =left;
            temp = left;
            left =left->next;

        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left) temp->next = left;
    else temp->next = right;
    return dummy->next;
 }
Node*sort1(Node*head)
{
    if(head ==NULL || head->next ==NULL)
    {
        return head;
    }
    Node*middle = findmiddle(head);
    Node*left = head;
    Node*right = middle->next;
    middle->next =NULL;

   left = sort1(left);
    right = sort1(right);
    return merge2(left ,right);
}

// Node ms(arr , low,high)
// {
//     if(low == high)
//     {
//         return;
//     }
//     mid = (low+high )/2;
//     ms(arr,low,mid);
//     ms(arr,mid+1,high);
//     merge(Arr,low,mid,high);
    
// }

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
    vector<int> arr = {3, 2, 1, 4, 5};
    Node *head = convertarrll(arr);
    print(head);
    cout << endl;
   head = sort1(head);
   print(head);
    return 0;
}