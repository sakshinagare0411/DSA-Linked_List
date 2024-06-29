#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data1, Node *next1) : data(data1), next(next1) {}
    Node(int data1) : data(data1), next(nullptr) {}
};


// Merge K sorted linked lists
Node *mergeLists(vector<Node *> &listArray)
{
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

    for (int i = 0; i < listArray.size(); i++)
    {
        if (listArray[i])
        {
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        if (it.second->next)
        {
            pq.push({it.second->next->data, it.second->next});
        }

        temp->next = it.second;
        temp = temp->next;
    }

    return dummy->next;
}

Node *convertArrToLL(const vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 4, 6};
    vector<int> arr1 = {1, 5};
    vector<int> arr2 = {1, 1, 3, 7};
    vector<int> arr3 = {8};

    Node *head1 = convertArrToLL(arr);
    cout << "List 1:\n";
    printList(head1);

    Node *head2 = convertArrToLL(arr1);
    cout << "List 2:\n";
    printList(head2);

    Node *head3 = convertArrToLL(arr2);
    cout << "List 3:\n";
    printList(head3);

    Node *head4 = convertArrToLL(arr3);
    cout << "List 4:\n";
    printList(head4);

    vector<Node *> listArray = {head1, head2, head3, head4};

    Node *mergedList = mergeLists(listArray);
    cout << "Merged List:\n";
    printList(mergedList);

    return 0;
}
