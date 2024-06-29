#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1) : data(data1), next(next1) {}
    Node(int data1) : data(data1), next(nullptr) {}
};

//..........................01.....brut force solution..................................
// Node* intersection (Node* head1 ,Node* head2)
// {
//     map<Node*,int> mapp;
//    Node* temp=head1;
//    while (temp != NULL) {
//         mapp.insert(make_pair(temp, 1));
//         temp = temp->next;
//     }

//    temp = head2;
//    while(temp!=NULL)
//    {
//    if (mapp.find(temp) != mapp.end()) {
//             return temp;
//         }
//     temp = temp->next;
//    }
//  return NULL;
// }
void insertnode(Node*& head, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// ...........................02.......optimal solution.............
// Node* collisionpoint(Node* t1, Node* t2, int d) {
//     while (d > 0) {
//         d--;
//         t2 = t2->next;
//     }
//     while (t1 != t2) {
//         t1 = t1->next;
//         t2 = t2->next;
//     }
//     return t1;
// }

// Node* intersection(Node* head1, Node* head2) {
//     Node* t1 = head1;
//     Node* t2 = head2;
//     int N1 = 0, N2 = 0;
    
//     while (t1 != NULL) {
//         N1++;
//         t1 = t1->next;
//     }
    
//     while (t2 != NULL) {
//         N2++;
//         t2 = t2->next;
//     }
    
//     t1 = head1;
//     t2 = head2;
    
//     if (N1 < N2) {
//         return collisionpoint(head1, head2, N2 - N1);
//     }
//     else {
//         return collisionpoint(head2, head1, N1 - N2);
//     }
// }

// ...........................03...optimal solution..................
Node* intersection (Node* head1 ,Node* head2)
{
    if(head1==NULL || head2==NULL)
    return NULL;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1!=t2)
    {
        t1 = t1->next;
        t2=t2->next;

        if(t1==t2)
        {
            return t1;
        }
        if(t1 ==NULL) t1 =head2;
        if(t2 ==NULL) t2 =head1;
    }
    return t1;
}


void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insertnode(head, 1);
    insertnode(head, 3);
    insertnode(head, 1);
    insertnode(head, 2);
    insertnode(head, 4);
    Node* head1 = head;
    head = head->next->next->next;
    
    Node* headsec = NULL;
    insertnode(headsec, 3);
    Node* head2 = headsec;
    headsec->next = head;
    
    cout << "List 1: "; 
    print(head1);
    cout << endl;
    
    cout << "List 2: "; 
    print(head2);
    cout << endl;

    Node* ans = intersection(head1, head2);
    if (ans == NULL) {
        cout << "No intersection";
    }
    else {
        cout << "The intersection point is " << ans->data << endl;
    }
    
    return 0;
}
