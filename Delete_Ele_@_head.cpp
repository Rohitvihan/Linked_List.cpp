#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
Node* conv_arr2LL(vector<int>&arr)
{
    Node* head=new Node(arr[0]);
    Node*mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void printlist(Node* head)
{
    Node*cur=head;
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
int main()
{
    vector<int> arr={15,23,45,75,89};
    Node* res=conv_arr2LL(arr);
    cout<<res->data<<endl;
    Node* ans=dele_at_Head(res);
    cout<<ans->data<<endl;
    printlist(ans);
    return 0;
}
