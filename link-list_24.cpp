#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

// Merge two lists
Node *merge(Node *list1, Node *list2) {
    Node *dummy = new Node(-1);
    Node *res = dummy;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        } else {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
    }
    if (list1) res->child = list1;
    else res->child = list2;

    Node *flattenedHead = dummy->child;
    delete dummy; // Free the dummy node
    return flattenedHead;
}

// Flatten the multi-level linked list
Node *flatten(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *mergehead = flatten(head->next);
    head->next = NULL; // Disconnect the next pointer
    head = merge(head, mergehead);
    return head;
}

// Print the original multi-level linked list
void printoriginal(Node *head, int depth) {
    while (head != nullptr) {
        cout << head->data << " ";

        if (head->child) {
            cout << "->";
            printoriginal(head->child, depth + 1);
        }

        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| .............";
            }
        }
        head = head->next;
    }
    cout << endl;
}

// Print the flattened linked list
void printLinkedList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->child = new Node(10);

    head->next->next = new Node(1);
    head->next->next->child = new Node(7);
    head->next->next->child->child = new Node(11);
    head->next->next->child->child->child = new Node(12);

    head->next->next->next = new Node(4);
    head->next->next->next->child = new Node(9);

    head->next->next->next->next = new Node(5);
    head->next->next->next->next->child = new Node(6);
    head->next->next->next->next->child->child = new Node(8);

    cout << "Original list:\n";
    printoriginal(head, 0);
    
    Node *flattened = flatten(head);
    cout << "Flattened list:\n";
    printLinkedList(flattened);

    // Clean up memory
    // You would typically need to delete all the nodes to prevent memory leaks.
    // For simplicity, this is not included here.

    return 0;
}


// Node*convert(vector<int>& arr)
// {
//     if(arr.size()==0)
//     {
//         return NULL;
//     }

//     Node* dummyNode = new Node(-1);
//     Node* temp = dummyNode;
//     for(int i = 0; i < arr.size(); i++){
//             temp->child = new Node(arr[i]);

//         temp = temp->child;
//     }
//     return dummyNode->child;
// }

//...............................01...Brut force solution..................
// Node*flatten(Node*head)
// {
//     vector<int>arr;
//     Node*temp=head;
//     while(temp!=NULL)
//     {
//         Node*t2 =temp;
//         while(t2!=NULL)
//         {
//             arr.push_back(t2->data);
//             t2=t2->child;
//         }
//         temp=temp->next;
//     }
//     sort(arr.begin(),arr.end());
//     head = convert(arr);
//     return head;
// }
