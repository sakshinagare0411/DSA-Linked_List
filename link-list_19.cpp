#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node*back;
public:
    Node(int data1, Node *next1,Node* back1) // constructure
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1) // constructure
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
//find the all pairs whose sum is give

//................01..Brut force solution.................
// vector<pair<int, int>> findPairsWithSum(Node* head, int sum) {
//     vector<pair<int, int>> pairs;
//     Node* temp1 = head;

//     while (temp1 != nullptr) {
//         Node* temp2 = temp1->next;
//         while (temp2 != nullptr) {
//             if (temp1->data + temp2->data == sum) {
//                 pairs.push_back(make_pair(temp1->data, temp2->data));
//             }
//             temp2 = temp2->next;
//         }
//         temp1 = temp1->next;
//     }

//     return pairs;
// }

Node* findtail(Node* head)
{
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}
//...........................02.....Optimal solution...................
vector<pair<int,int>> findsum(Node* head,int sum)
{
    Node* left =head;
    Node*right = findtail(head);
    vector<pair<int,int>>ds;
    while(left != nullptr && right != nullptr && left->data <right->data)
    {
        if(left->data+right->data == sum)
        {
            ds.push_back(make_pair(left->data,right->data));
            left =left->next;
            right=right->back;

        }
        else if(left->data+right->data < sum)
        {
            left=left->next;
        }
        else{
            right=right->back;
        }
    }
    return ds;

}
Node* convertaarll(vector<int>&arr)
{
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp =head;
    for(int i=1;i<arr.size();i++)
    {
        Node*newnode =new Node(arr[i],nullptr,temp);
        temp->next = newnode;
        temp=newnode;
    }
    return head;
}
void print(Node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    vector<int> arr = {1,2,3,4,9};
    Node* head =convertaarll(arr);
    print(head);
    cout<<"\n";
     int sum = 6;
    vector<pair<int, int>> ds = findsum(head, sum);
    cout << "Pairs with sum " << sum << ":\n";
    for (const auto& p : ds) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
   
    return 0;

}