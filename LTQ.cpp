#include<stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) , left(NULL), right(NULL) {}

};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i< size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL)
                q.push(node->left);
                if(node->right != NULL)
                q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};
int main () {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution sol;

    vector<vector<int >> result = sol.levelOrder(root);
    for(auto level  : result){
        for(auto val : level) cout << val << " ";
        cout << endl;
        
    }
    return 0;


}