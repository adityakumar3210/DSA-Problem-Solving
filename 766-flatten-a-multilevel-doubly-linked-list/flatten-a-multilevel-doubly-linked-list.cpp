/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* newHead = new Node(-1);
    Node* temp    = newHead;

    void solve(Node* head) {

        if(head == NULL) 
           return;
        
        Node* newNode = new Node(head-> val);

        temp-> next = newNode;
        newNode-> prev = temp;
        temp        = newNode;
        
        if(head-> child)
           solve(head-> child);
        if(head-> next)
           solve(head-> next);

        
    }
    Node* flatten(Node* head) {
        

        solve(head);
        
        if(newHead-> next)
        newHead->next-> prev = NULL;

        return newHead-> next;
    }
};