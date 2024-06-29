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

// middle of link list
//....................01...Brut force solution
// int middle (Node* head)
// {
//     Node* temp = head;
//     int n =0;
//     while(temp!=NULL)
//     {
//         n++;
//         temp=temp->next;
//     }
//     temp=head;
//     int midnode = (n/2) +1;
//   while (temp != NULL) {
//     // if (temp->data == (n / 2 + 1)) {
//     //     break;
//     midnode = midnode -1;
//     if(midnode ==0)
//     {
//         break;
//     }
    
//     temp = temp->next; // Corrected line
// }
// int res = temp->data;
// return res;

// }



//....................02...optimal solution.............
Node* middle(Node*head)
{
    Node* slow=head;
    Node*fast= head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast =fast->next->next;
    }
    return slow;
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
cout<<temp->data;
// print(head);
   
    return 0;
}

