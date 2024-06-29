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

// delete middle of link list
//....................01...Brut force solution
// Node* middle(Node* head)
// {
//      if (head == nullptr || head->next == nullptr) {
// //         // No or only one node in the list, so there is no middle node to delete
//         return nullptr;
//     }
//     Node* temp = head;
//     int n=0;
//     while(temp!=NULL)
//     {
//         n++;
//         temp=temp->next;
//     }
//     temp=head;
//     int res =(n/2);
//     while(temp!=NULL)
//     {
//         res--;
//         if(res ==0 )
//         {
//             Node* middle =temp->next;
//             temp->next=temp->next->next;
//             delete(middle);
//             return head;
//         }
//         temp=temp->next;
        
//     }
// }

//....................02...optimal solution.............
Node* middle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // No or only one node in the list, so there is no middle node to delete
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    fast =fast->next->next;

    while (fast != nullptr && fast->next != nullptr) {
       
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middle = slow->next;
    slow->next=slow->next->next;


    delete middle;

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
    cout << "\n";
//   int ans=  middle(head);
//    cout<<ans;
Node* temp= middle(head);
print(temp);
// print(head);
   
    return 0;
}


