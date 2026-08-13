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
    ListNode* findMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head-> next;

        while(fast != NULL && fast-> next != NULL) {

            slow = slow-> next;
            fast = fast-> next-> next;
        }
        fast = slow-> next;
        slow-> next = NULL;
        return fast;
    }
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {

            ListNode* next = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* solve(ListNode* h1, ListNode* h2) {

        if(h1 == NULL) 
            return h2;

        if(h2 == NULL) 
            return h1;

        ListNode* next = h1-> next;
        h1-> next = h2;
        h2-> next = solve(next, h2-> next);

        return h1;
    }
    void reorderList(ListNode* head) {
        
        ListNode* middle = findMid(head);
        middle = reverse(middle);

        solve(head, middle);
        
    }
};