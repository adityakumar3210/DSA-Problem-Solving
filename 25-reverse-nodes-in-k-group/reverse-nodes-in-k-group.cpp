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
    pair<ListNode*, ListNode*> reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {

            ListNode* next  = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = next;

        }
        return {prev, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k == 1) 
            return head;

        ListNode* newNode = new ListNode(-1);
        newNode-> next = head;
        ListNode* prev = newNode;
        ListNode* curr   = head;

        int count = 1;

        while(curr != NULL) {

            if(count == k) {

                ListNode* next = curr-> next;
                
                curr-> next    = NULL;
                pair<ListNode*, ListNode*> newPosition = reverse(prev-> next);

                prev-> next = newPosition.first;
                prev  = newPosition.second;

                prev-> next = next;

                curr = next;
                count = 1;
            }
            else{

                curr = curr-> next;
                count++;


            }
            
            
        }

        return newNode-> next;
    }
};