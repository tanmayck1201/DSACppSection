/*
https://leetcode.com/problems/linked-list-cycle/
https://leetcode.com/problems/linked-list-cycle-ii/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *q, *p;
        p = head;
        q = p;
        while(q){
            p = p->next;
            q = q->next;
            q=q!=NULL?q->next:NULL;
            if(p == q && head->next != 0){
                return true;
                break;
            }
        }
        return false;
    }
};


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!(fast && fast->next)) return NULL;
        while(head != slow)
        {
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};
*/