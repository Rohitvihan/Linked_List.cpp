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
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* insert_ele(Node* head,int ele)
{
    Node* temp=new Node(ele,head);
    return temp;
}
Node* insert_tail(Node* head,int val)
{
    if(head==NULL)
    {
        Node* temp=new Node(val);
        return temp;
    }
    Node* cur=head;
    while(cur->next!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    Node* temp=new Node(val,nullptr);
    cur->next=temp;
    return head;
}
void printlist(Node* head)
{
    Node*cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* head=Convert_arr2LL(arr);
    cout<<endl;
    Node* ans=insert_tail(head,190);
    cout<<"the element @ tail of LL is:";
    cout<<ans->data<<endl;
    cout<<"After inserting element at tail:";
    printlist(head);
    return 0;
}
