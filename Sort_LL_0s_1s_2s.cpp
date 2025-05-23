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
Node* Sort_LL_0s_1s_2s(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* dumy_node1=new Node(-1);
    Node* dumy_node2=new Node(-1);
    Node* dumy_node3=new Node(-1);
    Node* L0=dumy_node1;
    Node* L1=dumy_node2;
    Node* L2=dumy_node3;
    Node* temp=head;
    while(temp)
    {
        if(temp->data==0)
        {
            L0->next=temp;
            L0=L0->next;
            temp=temp->next;
        }
        else if(temp->data==1)
        {
            L1->next=temp;
            L1=L1->next;
            temp=temp->next;
        }
        else
        {
             L2->next=temp;
            L2=L2->next;
            temp=temp->next;
        }
    }
    L0->next=(dumy_node2->next)?(dumy_node2->next):dumy_node2->next;
    L1->next=dumy_node3->next;
    L2->next=NULL;
    Node* newHead=dumy_node1->next;
    delete(dumy_node1,dumy_node2,dumy_node3);
    return newHead;

}
int main()
{
    vector<int> arr={1,0,1,2,0,2,1};
    Node* head=Convert_arr2LL(arr);
    Node* ans=Sort_LL_0s_1s_2s(head);
    printlist(ans);
    return 0;
}
