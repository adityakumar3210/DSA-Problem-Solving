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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> points;
        
        ListNode* prev = head;
        ListNode* temp = head-> next;
        int idx = 2;

        while(temp->next != NULL) {
            
            ListNode* nextNode = temp-> next;
            // check maxima
            if(prev-> val < temp-> val && temp-> val > nextNode-> val) {
                points.push_back(idx);
            }

            // check manima
            if(prev-> val > temp-> val && temp-> val < nextNode-> val) {
                points.push_back(idx);
            }

            idx++;
            prev = temp;
            temp = temp-> next;
        }


        int size = points.size();

        if(size <= 1)
            return {-1, -1};

        int mini = INT_MAX;

        for(int i=0; i < size-1; i++) {

            int dits = points[i+1] - points[i];
            mini     = min(dits, mini);

        }


        int maxi = points[size-1] - points[0];

        return {mini, maxi};

    }
};