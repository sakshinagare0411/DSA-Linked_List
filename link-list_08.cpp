#include<iostream>
#include<vector>
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

//Remove the Nth node from the linked list

//...............Brut force solution.................
// Node * removeNthnode (Node* head , int N)
// {
//     int cnt =0;
//     Node* temp= head;
//     while(temp!=NULL)
//     {
//         cnt++;
//         temp=temp->next;
//     }
//     if (cnt == N)
//     {
//        Node* newhead  = head->next;
//        delete head ;
//     }
//     int res =cnt-N;
//     temp= head;
//     while(temp!=NULL)
//     {
//         res --;
//         if(res== 0)
//         {
//             break;
//         }
//         temp=temp->next;
//     }
//     Node * deletenode = temp->next;
//     temp->next =temp->next->next;
//     return head;
// }


//..................Optimized solution.....................

Node* removeNthnode(Node*head ,int N)
{
    Node* fast =head ;
    if(fast ==NULL)
    {
        return head->next;
    }
    for(int i=0;i<N;i++)
    {
        fast =fast ->next;
    }
    Node * slow = head;
    while(fast->next !=NULL)
    {
        slow=slow->next;
        fast =fast->next;
    }
    Node* deleteNode = slow->next ;
    slow->next =slow->next->next;
    delete(deleteNode);
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
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertarr1ll(arr);
    print(head);
    cout<<"\n";
    head = removeNthnode(head , 2);
    print(head);
    cout << "\n";
}