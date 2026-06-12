

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        
        // Base case: if the tree is empty, return an empty vector
        if (root == nullptr) {
            return result;
        }
        
        std::queue<TreeNode*> q;
        q.push(root); // Initialize the queue with the root node
        
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int level_size = q.size();
            std::vector<int> current_level;
            
            // Allocate memory ahead of time to avoid multiple reallocations
            current_level.reserve(level_size); 
            
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                current_level.push_back(node->val);
                
                // Push left child to queue if it exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                // Push right child to queue if it exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Move the current level vector into the result to prevent copying
            result.push_back(std::move(current_level));
        }
        
        return result;
    }
};