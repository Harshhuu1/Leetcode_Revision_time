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
    void morris(TreeNode* root, vector<int>&ans){
        if(!root) return ;
        TreeNode* curr = root;
        while(curr){
            if(curr -> left == NULL){
                ans.push_back(curr->val);
                curr = curr -> right;
            }
            else{
                TreeNode* prev = curr -> left;
                while(prev -> right && prev -> right != curr){
                    prev = prev -> right;
                }
                if(prev -> right == curr){
                
                    prev -> right = NULL;
                    ans.push_back(curr ->val);
                    curr = curr -> right;
                }
                else{
                    prev -> right = curr;
                    curr = curr -> left;
                }

            }
        }
        
            }
    void inorderStack(TreeNode* root, vector<int>&ans){
        if(root == NULL) return ;
        stack<TreeNode*>st;
        TreeNode*curr=root;

        while(curr != NULL  || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr  = curr->left;
            }
            curr =st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
            
            
    }}
    void inorder(TreeNode* root, vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        morris(root,ans);
        return ans;
    }
};