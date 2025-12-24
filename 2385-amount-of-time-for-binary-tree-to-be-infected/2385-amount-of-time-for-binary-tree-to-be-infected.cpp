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
    int bfs(unordered_map<int,vector <int>> & mp, vector<bool> &visited, int curr){
    int ans=-1;
        queue <int >q;
        q.push(curr);
        q.push(-1);
        visited[curr]=1;
        while(!q.empty()){
            int temp =q.front();
            q.pop();
            if(temp==-1){
                ans++;
                if(!q.empty()) q.push(-1);
                continue;
            }
            visited[temp]=1;
            for(auto i:mp[temp]){
                if(visited[i]==0){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector <int>> mp;
        queue <TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * curr= q.front();
            q.pop();
            if(curr->left){
                mp[curr->val].push_back(curr->left->val);
                mp[curr->left->val].push_back(curr->val);
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->val].push_back(curr->right->val);
                mp[curr->right->val].push_back(curr->val);
                q.push(curr->right);            }
        }
        vector <bool> visited(1e5+10 , 0);
        return max(bfs(mp,visited,start),0);
    }
};