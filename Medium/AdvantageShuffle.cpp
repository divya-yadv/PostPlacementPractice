vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            auto it = mp.upper_bound(nums2[i]);
            if(it == mp.end())
            {
                it = mp.begin();
            }
            nums1[i] = (*it).first;
            mp[nums1[i]]--;
            if(mp[nums1[i]] == 0)
                mp.erase(nums1[i]);
        }
        return nums1;
    }
