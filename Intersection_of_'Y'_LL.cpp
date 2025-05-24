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
Node* Inter_section(Node* head1,Node* head2)
{
    if(head1==NULL || head2==NULL)return NULL;
    Node* t1=head1;
    Node* t2=head2;
    while(t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;
        if(t1==t2)return t1;
        if(t1==NULL)t1=head2;
        if(t2==NULL)t2=head1;
    }
    return t1;
}
int main()
{
    vector<int> arr={3,1,4,6,2};
    vector<int> arr1={1,2,4,5,4,6,2};
    Node* ans=Convert_arr2LL(arr);
    Node* ans1=Convert_arr2LL(arr1);
    Node* as=Inter_section(ans,ans1);
    if(as)
    {
        cout<<as->data;
    }
    else
    {
        cout<<"Intersection not found";
    }
    return 0;
}
