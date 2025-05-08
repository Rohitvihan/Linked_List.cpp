#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* backk;
    public:
    Node(int data1,Node* backk1,Node* next1)
    {
        data=data1;
        backk=backk1;
        next=next1;
    }
    public:
    Node(int data1)
    {
        data=data1;
        backk=nullptr;
        next=nullptr;
    }
};
Node* Conv_arr2DLL(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i],prev,nullptr);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void printlist(Node* head)
{
    Node* cur=head;
    while(cur)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}
Node* Insert_before_head(Node* head,int val)
{
    Node* newNode=new Node(val,nullptr,head);
    head->backk=newNode;
    head=newNode;
    return head;
}
Node* Insert_before_tail(Node* head,int val)
{
    if(head->next==NULL)
    {
        Node* newNode=new Node(val,nullptr,head);
        head=newNode;
        return head;
    }
    Node* cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    Node* prev=cur->backk;
    Node* newNode=new Node(val,prev,cur);
    prev->next=newNode;
    cur->backk=newNode;
    return head;
}
Node* insertt_at_k(Node* head,int k,int vl)
{
    if(k==1)
    {
        return Insert_before_head(head,vl);
    }
    Node* cur=head;
    int count=0;
    while(cur!=NULL)
    {
        count+=1;
        if(count==k)
        {
            break;
        }
        cur=cur->next;
    }
    Node* prev=cur->backk;
    Node* temp=new Node(vl,prev,cur);
    prev->next=temp;
    cur->backk=temp;
    return head;
}
void insertt_bef_Node(Node* node,int val)
{
    Node* prev=node->backk;
    Node* newNode=new Node(val,prev,node);
    prev->next=newNode;
    node->backk=newNode;
}
int main()
{
    vector<int> arr={1,3,2,4,5};
    Node* ans=Conv_arr2DLL(arr);
    int val=23,k=1;
    insertt_bef_Node(ans->next->next,val);
    printlist(ans);
    return 0;
}
