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
void printlist(Node* head)
{
    Node* cur=head;
    while(cur)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}
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
Node* odd_even(Node* head)
{
    Node* odd=head;
    Node* even=head->next;
    Node* evenNode=even;
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenNode;
    return head;
}
int main()
{
    vector<int> arr={4,5,6,8,18,2};
    Node* ans=Convert_arr2LL(arr);
    Node* ans1=odd_even(ans);
    printlist(ans1);
    return 0;
}
