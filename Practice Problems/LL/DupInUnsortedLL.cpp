/*
https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-LinkedList/problem/remove-duplicates-from-an-unsorted-linked-list

1st:-

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     struct Node *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    // Pick elements one by one 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        // Compare the picked element with rest
        //  of the elements 
        while (ptr2->next != NULL) {
            // If duplicate then delete it 
            if (ptr1->data == ptr2->next->data) {
                // sequence of steps is important here 
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else // This is tricky 
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return head;
    }
};

2nd:-

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     if(head==NULL || head->next ==NULL)
     return head;
     
     unordered_set<int> s;
     Node *curr=head->next;
     Node *prev=head;
     s.insert(head->data);
     
     while(curr!=NULL)
     {
         if(s.find(curr->data) !=s.end())
         {
             Node *temp=curr;
             prev->next=temp->next;
             curr=curr->next;
             delete temp;
         }
         else
         {
            // cout<<"Check"<<endl;
             s.insert(curr->data);
             curr=curr->next;
             prev=prev->next;
             
         }
     }
    return head;
    }
};
*/