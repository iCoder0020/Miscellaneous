#include <bits/stdc++.h>

using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

void insert_at_head(NODE** head_ref, int node_data)
{
    NODE* node = new NODE;
    node->data = node_data;
    node->next = *head_ref;
    *head_ref = node;
}

void print(NODE* head)
{
    NODE* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void divide(NODE* head, NODE** a, NODE** b)
{
    NODE* slow;
    NODE* fast;
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

NODE* merge(NODE* a, NODE* b)
{
    NODE* result = NULL;

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
        if(a->data <= b->data)
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

void merge_sort(NODE** head_ref)
{
    NODE* head = *head_ref;
    NODE* a;
    NODE* b;

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
    NODE* a = NULL;
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