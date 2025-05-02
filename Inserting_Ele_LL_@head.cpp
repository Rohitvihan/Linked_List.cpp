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
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* head=Convert_arr2LL(arr);
    Node* cur=head;
    while(cur)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
    Node* hed=insert_ele(head,49);
    cout<<"hed->data is:"<<hed->data;
    return 0;
}
