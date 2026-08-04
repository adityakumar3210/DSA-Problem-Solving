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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* newNode = new ListNode(-1);
        ListNode* temp    = newNode;
        ListNode* t1      = l1;
        ListNode* t2      = l2;

        int carry = 0;

        while(t1 != NULL && t2 != NULL) {

            int val = t1-> val + t2-> val + carry;
            temp-> next = new ListNode(val);
            
            if(carry == 1) 
                carry = 0;

            if(val >= 10) {
                int digit = val % 10;
                temp-> next-> val = digit;
                carry = val / 10;
            }

            temp = temp-> next;
            t1   = t1-> next;
            t2   = t2-> next;

        }

        while(t1 != NULL) {

            int val = t1-> val + carry;
            temp-> next = new ListNode(val);

            if(carry == 1) 
               carry = 0;

            if(val >= 10) {
                int digit = val % 10;
                temp-> next-> val = digit;
                carry = val / 10;
            }

            temp = temp-> next;
            t1   = t1-> next;

        }

        while(t2 != NULL) {

            int val = t2-> val + carry;
            temp-> next = new ListNode(val);
            
            if(carry == 1) 
               carry = 0;

            if(val >= 10) {
                int digit = val % 10;
                temp-> next-> val = digit;
                carry = val / 10;
            }

            temp = temp-> next;
            t2   = t2-> next;

        }

        if(carry == 1) 
            temp-> next = new ListNode(1);
        

        return newNode-> next;

        
    }
};