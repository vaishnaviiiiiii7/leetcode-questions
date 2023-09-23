class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        vector<pair<int, int>> lot; // Stores the nodes along with their levels

        if (root == nullptr)
            return ans;

        queue<pair<TreeNode *, int>> q; // Queue to perform level order traversal
        q.push({root, 0});              // Push the root node with level 0

        while (!q.empty())
        {
            TreeNode *current = q.front().first;
            int level = q.front().second;
            q.pop();

            lot.push_back({current->val, level}); // Store current node with its level

            if (current->left)
                q.push({current->left, level + 1}); // Push left child with level increased by 1

            if (current->right)
                q.push({current->right, level + 1}); // Push right child with level increased by 1
        }

        for(int i = 0; i < lot.size()-1; i++) {
            if(lot[i].second != lot[i+1].second) {
                ans.push_back(lot[i].first);
            }
        }
        ans.push_back(lot[lot.size()-1].first);
        return ans;
    }
};
