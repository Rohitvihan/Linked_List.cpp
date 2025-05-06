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
Node* dele_at_Head(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* dele_tail(Node* head)
{
    if(head==NULL)return NULL;
    Node* cur=head;
    Node* prev=NULL;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    cur->backk=NULL;
    return head;
}
Node* delete_at_k(Node* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* KNode=head;
    int count=0;
    while(KNode)
    {
        count+=1;
        if(count==k)
        {
            break;
        }
        KNode=KNode->next;
    }
    Node* prev=KNode->backk;
    Node* frontt=KNode->next;
    if(prev==NULL && frontt==NULL)
    {
        return NULL;
    }
    else if(prev==NULL)
    {
        return dele_at_Head(head);
    }
    else if(frontt==NULL)
    {
        return dele_tail(head);
    }
    prev->next=frontt;
    frontt->backk=prev;
    delete KNode;
    return head;
}
int main()
{
    vector<int> arr={1,3,2,4,5};
    int pos=4;
    Node* ans=Conv_arr2DLL(arr);
    Node* res=delete_at_k(ans,pos);
    printlist(res);
    return 0;
}
