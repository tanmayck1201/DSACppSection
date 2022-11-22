/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/?languageTags=cpp

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*t,*q;
        p = head;
        int count=0, index;
        // count the nodes
        while(p){
            count++;
            p = p->next;
        }
        index = (count - n) + 1;

        // Case1: If only node is present 
        // or 1st node to be deleted
        if(count == 1 && n == 1){
            head = NULL;
            return head;
        }else if(count == n){
            head = head->next;
            return head;
        }

        // Case2: If last node is reqd.
        if(n==1){
            t = head;
            while(t->next && t->next->next){
                t = t->next;
            }
            t->next = nullptr;
            return head;
        }
        // Case3: For in between nodes
        else{
            t = head;
            q = head;
            for(int i=0; i<index-2; i++){
                t = t->next;
                q = q->next;
            }q = q->next;
            q = q->next;
            t->next = q;
            return head;
        }
        // default(if null ll is passed.)
        return nullptr;
    }
};

Two pointer approach:-
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode();
        temp->next=head;

        ListNode* fast=temp;
        ListNode* slow=temp;

        for(int i=1;i<=n;i++){
             fast=fast->next;
        }

        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* gaya=slow->next;
        slow->next=slow->next->next;
        delete(gaya);
        
        return temp->next;
    }
};
*/