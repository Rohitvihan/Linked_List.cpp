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
int length_of_LL(Node* head)
{
    Node* cur=head;
    int cunt=0;
    while(cur)
    {
        cunt+=1;
        cur=cur->next;
    }
    return cunt;
}
int search_element(int val,Node* head)
{
    Node*cur=head;
    while(cur)
    {
        if(cur->data==val)
        {
            return 1;
        }
        cur=cur->next;
    }
    return 0;
}
int main()
{
    vector<int> arr={1,23,34,45,56};
    Node* head=Convert_arr2LL(arr);
    int res=search_element(1,head);
    cout<<"the result is:"<<res;
    return 0;
}
