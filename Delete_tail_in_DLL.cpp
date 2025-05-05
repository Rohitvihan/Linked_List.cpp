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
int main()
{
    vector<int> arr={1,3,2,4,5};
    Node* ans=Conv_arr2DLL(arr);
    Node* res=dele_tail(ans);
    cout<<res->data<<endl;
    printlist(res);
    return 0;
}
