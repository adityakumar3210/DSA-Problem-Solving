/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2, int rem) {
         
        if(l1 == NULL && l2 == NULL) {
            if(rem  == 0)return NULL;
            return new ListNode(1);
        }
            

        int num = 0;

        if(l1 != NULL) num += l1-> val;
        if(l2 != NULL) num += l2-> val;

        num += rem;
        int digit = num % 10;
        rem = num / 10;

        ListNode* newNode = new ListNode(digit);

        ListNode* nextNode;
        if(l1 != NULL && l2 != NULL) {
            nextNode = solve(l1-> next, l2-> next, rem);
        }
        else if(l1 != NULL) {
            nextNode = solve(l1-> next, l2, rem);
        }
        else if(l2 != NULL) {
            nextNode = solve(l1, l2-> next, rem);
        }

        newNode-> next = nextNode;
        return newNode;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) 
           return l2;

        if(l2 == NULL) 
            return l1;

        return solve(l1, l2, 0);


    }
};