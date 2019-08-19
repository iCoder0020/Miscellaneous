#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void insert_at_head(ListNode** head_ref, int node_data)
{
    ListNode* ListNode = new ListNode;
    ListNode->val = node_data;
    ListNode->next = *head_ref;
    *head_ref = ListNode;
}

void print(ListNode* head)
{
    ListNode* temp = head;
    while(temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void divide(ListNode* head, ListNode** a, ListNode** b)
{
    ListNode* slow;
    ListNode* fast;
    slow = head;
    fast = head->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

ListNode* merge(ListNode* a, ListNode* b)
{
    ListNode* result = NULL;

    if(a == NULL)
    {
        return(b);
    }
    else if(b == NULL)
    {
        return(a);
    }
    else
    {
        if(a->val <= b->val)
        {
            result = a;
            result->next = merge(a->next, b);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next);
        }
    }
    return result;
}

void merge_sort(ListNode** head_ref)
{
    ListNode* head = *head_ref;
    ListNode* a;
    ListNode* b;

    if(head == NULL || head->next == NULL)
    {
        return;
    }
    else
    {
        divide(head, &a, &b);
        merge_sort(&a);
        merge_sort(&b);

        *head_ref = merge(a, b);
    }
}

int main()
{
    int N;
    cin>>N;
    ListNode* a = NULL;
    int temp;
    for(int n = 0; n<N; n++)
    {
        cin>>temp;
        insert_at_head(&a, temp);        
    }
    print(a);
    merge_sort(&a);
    print(a);
    return 0;
}