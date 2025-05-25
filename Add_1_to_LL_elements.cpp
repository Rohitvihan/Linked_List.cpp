
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
Node* Add_1_to_LL(Node* head)
{
    head=reverse_LL(head);
    int carry=1;
    Node* temp=head;
    while(temp)
    {
        temp->data+=1;
        if(temp->data<10)
        {
            carry=0;
            break;
        }
        else
        {
            carry=1;
            temp->data=0;
        }
        temp=temp->next;
    }
    if(carry)
    {
        Node* newHead=new Node(1,head);
        head=reverse_LL(head);
        return head;
    }
    head=reverse_LL(head);
    return head;
}
int main()
{
    vector<int> arr={1,5,9};
    Node* head=Convert_arr2LL(arr);
    Node* ans=Add_1_to_LL(head);
    printlist(ans);
    return 0;
}
