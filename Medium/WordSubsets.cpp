Time Complexity - O(n*m)
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> mp2;
        for(int i = 0; i<words2.size(); i++)
        {
            unordered_map<char,int> temp;
            for(int j = 0; j<words2[i].size(); j++)
            {
                temp[words2[i][j]]++;
            }
            for(auto it : temp)
            {
                mp2[it.first] = max(it.second, mp2[it.first]);
            }
        }
        vector<string> result;
        for(int i = 0; i<words1.size(); i++)
        {
            unordered_map<char,int> mp1;
            for(int j = 0; j<words1[i].size(); j++)
            {
                mp1[words1[i][j]]++;
            }
            bool flag = true;
            for(auto it : mp2)
            {
                if(mp1[it.first] < it.second)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) result.push_back(words1[i]);
        }
        return result;
    }
