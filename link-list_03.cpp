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

void print(Node*head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
}
Node *convertArr2DLL ( vector<int> &arr)
{
    Node*head = new Node (arr[0]);
    Node * prev = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev=temp;
    }

    return head;
}

// 01...Delete the head of doubly link list
Node* deletehead (Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;

    }

    Node* prev=head;
    head = head->next;
    head->back=nullptr;
    prev->next = nullptr;

    return head;

}

//02...Delete the tail of doubly link list
Node* deletetail (Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node * tail = head;
    while(tail->next != NULL)
    {
        tail=tail->next;
    }

    Node*prev = tail->back;
       prev->next=nullptr;
    tail->back =nullptr;
 
    delete tail;
    return head;
}

//03..Delete the Kth element of the doubly link list
Node* deletek(Node* head , int k )
{
    Node* temp = head;
    int cnt =0 ;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt == k)
        {
            break;
        }
        temp=temp->next;
    }
    Node*prev = temp->back;
   Node* front = temp->next;
   if(prev ==NULL && front==NULL)
   {
        delete temp;
        return NULL;
   }
   else if(prev==NULL)
   {
       return  deletehead(head);
        
   }
   else if(front == NULL)
   {
        return deletetail(head);
        
   }
   prev->next=front;
   front->back = prev;
   temp->back = NULL;
   temp->next =NULL;
    delete temp;
    return head;
}

//04.Delete Node from the doubly link list (Node != head)
void deleteNode (Node*temp)
{
    Node*prev = temp->back;
    Node*front = temp->next;
    if(front==NULL)
    {
        prev->next =nullptr;
        temp->back=nullptr;
        delete(temp);
        return;
    }
    prev->next = front;
    front->back =prev;
     temp->next =temp->back =nullptr;
     delete temp;
     return;
}

//05..insert the node before the head
Node * insertbeforehead(Node* head ,int val)
{
    Node*newnode = new Node(val , head , nullptr);
    head->back =newnode;
    return newnode;
}

//06..Insert before the tail of link list
Node *insertbeforetail (Node* head ,int val)
{
    if(head->next ==NULL)
    {
        return insertbeforehead(head,val);
    }
    Node* tail =head ;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* prev= tail->back;
    Node* newnode = new Node(val,tail,prev);
    prev->next = newnode;
    tail->back=newnode;
    return head;

}

//06...Insert Node at Kth Position 
Node* insertk(Node* head , int val,int k)
{
    if(k==1)
    {
        return insertbeforehead(head,val);

    }
    Node* temp = head;
    int cnt =0 ;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k )
        {
            break;
        }
        temp = temp->next;

    }
    Node* prev = temp->back;
    Node* newnode = new Node (val,temp,prev);
    prev->next =newnode;
    temp->back =newnode;
    return head;

}

//07...Insert before the node (Node != head)becaues node get change
void insertBeforenode (Node* node,int val)
{
    Node* prev = node->back;
    Node*newnode =new Node(val ,node,prev);
    prev->next = newnode;
    node->back =newnode;
}
int main()
{
    vector<int> arr ={12,5,8,7};
    Node* head = convertArr2DLL(arr);
    // print(head);
    // cout<<"\n";
    // cout<<" delete head \n";
    // head = deletehead(head);
    // print(head);
    //  cout<<"\n";
    // cout<<" delete tail \n";
    // head = deletetail(head);
    // print(head);
    // head = deletek(head,3);
    // print(head);
    // deleteNode(head->next);
    // print(head);
    // head = insertbeforehead(head , 55);
    // print(head);
    // head= insertbeforetail(head,63);
    // print(head);
    // head = insertk(head, 10, 4); 
    // print(head);
    insertBeforenode(head->next ,100);
    print(head);
    return 0;
}