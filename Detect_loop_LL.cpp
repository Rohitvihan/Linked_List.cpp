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
int Detect_loop(Node* head)
{
   Node* slow=head;
   Node* fast=head;
   while(fast!=NULL && fast->next!=NULL)
   {
       slow=slow->next;
       fast=fast->next->next;
       if(slow==fast)
       {
           return true;
       }
   }
   return false;
}

    
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* ans=Convert_arr2LL(arr);
    int ans1=Detect_loop(ans);
    if(ans1==0)
    {
        cout<<"No loop in the LL";
    }
    else
    {
        cout<<"Loop in the LL";
    }
    return 0;
}

