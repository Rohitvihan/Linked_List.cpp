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
void printlist(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
Node* Find_nth_node(Node* head, int n) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count += 1;
        if (count == n) {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

Node* rotatee_LL(Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    Node* tail = head;
    int cnt = 1;
    while (tail->next) {
        cnt += 1;
        tail = tail->next;
    }

    k = k % cnt;
    if (k == 0) return head;

    tail->next = head;
    Node* newLastnode = Find_nth_node(head, cnt - k);
    Node* newhead = newLastnode->next;
    newLastnode->next = nullptr;

    return newhead;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = Convert_arr2LL(arr);
    Node* ans = rotatee_LL(head, 7);
    printlist(ans);
    return 0;
}
