class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
        {
            return NULL;
        }
        if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        else
        {
            if(!root->left && !root->right)
            {
                delete(root);
                return NULL;
            }
            else if(!root->left)
            {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            else if(!root->right)
            {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            else 
            {
                TreeNode* rightMin = root->right;
                while(rightMin->left)
                {
                    rightMin = rightMin->left;
                }
                root->val = rightMin->val;
                root->right = deleteNode(root->right,root->val);
                return root;
            }
        }
    }
};