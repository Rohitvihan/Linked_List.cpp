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
Node* Dele_at_pos(Node* head,int k)
{
    if(head==NULL)return NULL;
    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp;
    Node* prev;
    temp=head;
    int count=0;
    while(temp)
    {
        count+=1;
        if(count==k)
        {
            prev->next=prev->next->next;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr={15,23,45,75,89};
    int k=3;
    Node* res=conv_arr2LL(arr);
    Node* re=Dele_at_pos(res,k);
    printlist(re);
    return 0;
}
