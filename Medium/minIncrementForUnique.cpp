int minIncrementForUnique(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i<n; i++) mp[nums[i]]++;

        int count = 0;
        for(auto it : mp)
        {
            if(it.second > 1)
            {
                count += it.second - 1;
                mp[it.first+1] += it.second-1;
            }
        }
        return count;
    }
    
    
    int minIncrementForUnique(vector<int>& nums) {
        int count = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i<n; i++)
        {
            if(nums[i] == nums[i-1])
            {
                 count++;
                 nums[i] = nums[i-1]+1;
            }
            else if(nums[i-1] > nums[i])
            {
                count += abs(nums[i]-nums[i-1])+1;
                nums[i] = nums[i-1]+1;
            } 
            
        }
        return count;
    }
