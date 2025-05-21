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
Node* Delete_middle_node(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* dele_node=slow->next;
    slow->next=slow->next->next;
    delete(dele_node);
    return head;
}
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* head=Convert_arr2LL(arr);
    Node* ans1=Delete_middle_node(head);
    printlist(ans1);
    return 0;
}
