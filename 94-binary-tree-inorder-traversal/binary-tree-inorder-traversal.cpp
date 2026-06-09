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
    // Yeh hamara helper function hai jo traverse karega
    void helper(TreeNode* root, vector<int>& ans) {
        // Base Case: Agar node khali (NULL) hai, toh wapas lout jao
        if (root == NULL) {
            return;
        }
        
        helper(root->left, ans);  // 1. Pehle Left me jao
        ans.push_back(root->val); // 2. Root ki value ko list me daalo
        helper(root->right, ans); // 3. Fir Right me jao
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // Isme hum apna final answer store karenge
        helper(root, ans);
        return ans;
    }
};