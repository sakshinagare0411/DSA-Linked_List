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

// Merge the two sorted link list

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
// Node* merge(Node*head1 ,Node*head2)
// {
//     vector<int>list;
//     Node*temp1=head1;
//     Node*temp2=head2;
//     while(temp1!=NULL)
//     {
//         list.push_back(temp1->data);
//         temp1=temp1->next;
//     }
//     while(temp2!=NULL)
//     {
//         list.push_back(temp2->data);
//         temp2=temp2->next;
//     }
//     sort(list.begin(), list.end());
//     Node*head =convertarrll(list);
//     return head;

// }

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node*temp1=head1;
    Node*temp2=head2;
    Node*dummy = new Node(-1);
    Node*temp=dummy;
    while(temp1!=NULL && temp2!= NULL)
    {
        if(temp1->data < temp2->data)
        {
            temp->next =temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
        
        
    }
    if(temp1){
        temp->next =temp1;
            // temp=temp1;
            // temp1=temp1->next;
    }
    if(temp2)
    {
         temp->next=temp2;
            // temp=temp2;
            // temp2=temp2->next;
    }
    Node*head = dummy->next;
    delete(dummy);
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
    vector<int> arr = {2, 4, 8, 10};
    vector<int> arr1 = {1, 3, 3, 6, 11, 14 ,20,52};
    Node *head1 = convertarrll(arr);
    cout << "List 1 :\n";
    print(head1);
    cout << endl;
    Node *head2 = convertarrll(arr1);
    cout << "List 2 :\n";
    print(head2);
    cout << endl;
    cout<<"sorted list :\n";
    Node *head = merge(head1, head2);
    print(head);
    cout << endl;

    return 0;
}