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
Node* Merge_two_LL(Node* head1,Node* head2)
{
    Node* t1=head1;
    Node* t2=head2;
    Node* dumy_node=new Node(-1);
    Node* temp=dumy_node;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data<t2->data)
        {
            temp->next=t1;
            temp=temp->next;
            t1=t1->next;
        }
        else
        {
            temp->next=t2;
            temp=temp->next;
            t2=t2->next;
        }
    }
    if(t1)
    {
        temp->next=t1;
        temp=temp->next;
        t1=t1->next;
    }
    else
    {
        temp->next=t2;
        temp=temp->next;
        t2=t2->next;
    }
    return dumy_node->next;
}
int main()
{
    vector<int> arr={2,4,8,10};
    vector<int> arr1={1,3,3,6,11,14};
    Node* he=Convert_arr2LL(arr);
    Node* ad=Convert_arr2LL(arr1);
    Node* ans1=Merge_two_LL(he,ad);
    printlist(ans1);
    return 0;
}
