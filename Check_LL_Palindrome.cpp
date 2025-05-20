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
Node* reverse_LL(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* newHead=reverse_LL(head->next);
    Node* frontt=head->next;
    frontt->next=head;
    head->next=NULL;
    return newHead;
}
bool is_palindrome(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverse_LL(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second)
    {
        if(first->data!=second->data)
        {
            reverse_LL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse_LL(newHead);
    return true;
}
int main()
{
    vector<int> arr={1,2,3,1,2,1};
    Node* ans=Convert_arr2LL(arr);
    int ans1=is_palindrome(ans);
    if(ans1==0)
    {
        cout<<"It is not a palindrome";
    }
    else
    {
        cout<<"It is a palindrome";
    }
    return 0;
}
