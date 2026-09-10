/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<pair<int,int>, int> solve(TreeNode* root) {

        if(root == NULL) 
            return {{0,0},0}; 

        pair<pair<int,int>, int> leftAns = solve(root-> left);

        pair<pair<int,int>, int> rightAns = solve(root-> right);

        int sum = leftAns.first.first + rightAns.first.first + root-> val;
        int totalNodes = leftAns.first.second + rightAns.first.second + 1;
        int count = leftAns.second + rightAns.second;

        pair<pair<int,int>, int> ans;
        ans.first.first  = sum;
        ans.first.second = totalNodes;
        ans.second = count;

        if(sum / totalNodes == root-> val) 
            ans.second = count+1;

        return ans;


    }
    int averageOfSubtree(TreeNode* root) {
        
        return solve(root).second;
    }
};