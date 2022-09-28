TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        TreeNode* temp = root;
        if(root == NULL)
        {
            return new TreeNode(val);
        }
        if(depth == 1)
        {
            TreeNode* t = new TreeNode(val);
            t->left = root;
            return t;
        }
        q.push(root);
        depth--;
        while((!q.empty()) && (depth-1) )
        {
            int count = q.size();
            while(count--){
                  TreeNode* p = q.front();
                  q.pop();
                  if(p->left) q.push(p->left);
                  if(p->right) q.push(p->right);
            }
            depth--;
        }
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            TreeNode* l =t->left;
            TreeNode* r = t->right;
            t->left = new TreeNode(val);
            t->right = new TreeNode(val);
            t->left->left = l;
            t->right->right = r;
        }
        return root;
    }
