#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    public:
        Node(int data1,Node* next1)
        {
            data=data1;
            next=next1;
        }

    public:
        Node(int data1)
        {
            data=data1;
            next=nullptr;
        }

};
Node* Convert_arr2LL(vector<int> &arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
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
Node* remove_Nth(Node* head,int n)
{
    Node* temp=head;
    int count=0;
    while(temp)
    {
        count+=1;
        temp=temp->next;
    }
    if(count==n)
    {
        Node* newhead=head->next;
        delete(head);
        return newhead;
    }
    int res=count-n;
    temp=head;
    while(temp)
    {
        res-=1;
        if(res==0)
        {
            break;
        }
        temp=temp->next;
    }
    Node* delenode=temp->next;
    temp->next=temp->next->next;
    delete(delenode);
    return head;
}
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* head=Convert_arr2LL(arr);
    int n=3;
    Node* ans1=remove_Nth(head,n);
    printlist(ans1);
    return 0;
}
