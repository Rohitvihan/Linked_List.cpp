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
Node* Add_2LL(Node* LL1,Node* LL2)
{
   Node* t1=LL1;
   Node* t2=LL2;
   int carry=0;
   Node* dummy_node=new Node(-1);
   Node* cur=dummy_node;
   while(t1!=NULL || t2!=NULL)
   {
       int sum=carry;
       if(t1)sum=sum+t1->data;
       if(t2)sum=sum+t2->data;
       Node* newNode=new Node(sum%10);
       carry=sum/10;
       cur->next=newNode;
       cur=cur->next;
       if(t1)t1=t1->next;
       if(t2)t2=t2->next;
   }
   if(carry)
   {
        Node* newNode=new Node(carry);
        cur->next=newNode;
        cur=cur->next;
   }
    return dummy_node->next;
}
int main()
{
    vector<int> arr={2,4,6};
    vector<int> arr1={3,8,7};

    Node* ans=Convert_arr2LL(arr);
    Node* ans1=Convert_arr2LL(arr1);
    Node* fin=Add_2LL(ans,ans1);
    printlist(fin);
    return 0;
}
