string reorganizeString(string s) {
        vector<int> v(26,0);
        int mi = 0;
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a'] += 1;
            if(v[mi] < v[s[i]-'a'] )
            {
                mi = s[i]-'a';
            }
        }
      if(2 * v[mi] - 1 > s.size()) return "";
        int i=0;
        while(v[mi])
        {
            s[i] = mi + 'a';
            i += 2;
            v[mi]--;
        }
        for(int j=0;j<26;j++)
        {
            while(v[j])
            {
                if(i >= s.length()) i=1;
                s[i] = j + 'a';
                i+=2;
                v[j]--;
            }
        }
        return s;
    }
