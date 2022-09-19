TC -> O(N)+O(N)+O(N), SC -> O(N)+O(N)
int solve(TreeNode* root,vector<int>&sum)
    {
        if(root == NULL)
            return 0;
        int s1 = solve(root->left,sum);
        int s2 = solve(root ->right,sum);
  // push sum of subtree 
        sum.push_back(root->val+s1+s2);
        return root->val+s1+s2;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>sum;
        vector<int> ans;
        int p = solve(root,sum);
        unordered_map<int,int> mp;
        for(int i=0;i<sum.size();i++)
        {
            mp[sum[i]]++;
        }
        
        int maxcount = 0;
      // get the max frequnecy
        for(auto x:mp)
        {
            if(x.second > maxcount)
            {
                ans.clear();
                ans.push_back(x.first);
                maxcount = max(maxcount,x.second);
            }
            else if(x.second == maxcount)
               ans.push_back(x.first);
        }
        return ans;
    }
