/*
https://leetcode.com/problems/merge-two-sorted-lists/description/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr, *t;
        // if list1 happen to be NULL
		// we will simply return list2.
        if(!list1){
            return list2;
        }

        // if list2 happen to be NULL
		// we will simply return list1.
        if(!list2){
            return list1;
        }

        ptr = list1;
        if(list1->val > list2->val){
            ptr = list2;
            list2 = list2->next;
        }else{
            list1 = list1->next;
        }
        t = ptr;
        
        // till one of the list doesn't reaches NULL
        while(list1 && list2){
            if(list1->val > list2->val){
                t->next = list2;
                list2 = list2->next;
            }else{
                t->next = list1;
                list1 = list1->next;
            }
            t = t->next;
        }

        // adding remaining elements of bigger list.
        if(!list1){
            t->next = list2;
        }else{
            t->next = list1;
        }
        return ptr;
    }
};
*/