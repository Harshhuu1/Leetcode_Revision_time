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
    TreeNode* built(vector<int>& inorder, vector<int>& postorder , int start , int end , int &idx){
        if(start > end) return NULL;
        int rootVal = postorder[idx];
        TreeNode* root = new TreeNode(rootVal);
        int i = start ;
        for(; i <=end ;i++){
            if(inorder[i] == rootVal)
            break;
        }
        idx--;
        root->right = built(inorder ,  postorder, i+1 , end,idx);
        root->left = built(inorder ,  postorder, start , i-1,idx);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx =postorder.size()-1;
        return built(inorder , postorder, 0,postorder.size()-1,idx);
    }
};