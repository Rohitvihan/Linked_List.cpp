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
int findLength(Node* slow,Node* fast)
{
    int count=0;
    fast=fast->next;
    while(slow!=fast)
    {
        fast=fast->next;
        count+=1;
    }
    return count;
}
int Length_of_loop(Node* head)
{
   Node* slow=head;
   Node* fast=head;
   while(fast!=NULL && fast->next!=NULL)
   {
       slow=slow->next;
       fast=fast->next->next;
       if(slow==fast)
       {
           return findLength(slow,fast);
       }
   }
   return 0;
}
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* ans=Convert_arr2LL(arr);
    int ans1=Length_of_loop(ans);
    cout<<ans1;
    return 0;
}
