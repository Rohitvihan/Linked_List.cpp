

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
   Node* prev=NULL;
   Node* cur=head;
   Node* frontt;
   while(cur)
   {
       frontt=cur->next;;
       cur->next=prev;
       prev=cur;
       cur=frontt;
   }
   return prev;
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
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* ans=Convert_arr2LL(arr);
    Node*ans1=reverse_LL(ans);
    printlist(ans1);
    return 0;
}

