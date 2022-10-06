int longestMountain(vector<int>& arr) {
        if(arr.size() < 3)
            return 0;
        int i=1;
        int n = arr.size();
        int ans = 0;
        while(i<n)
        {
            if(arr[i-1] < arr[i])
            {
                int j=i+1;
                while((j<n) && (arr[j-1]<arr[j]) )
                {
                    j++;
                }
                int m=j;
                while((j<n) && (arr[j-1] > arr[j]))
                {
                    j++;
                }
                if(j != m)
                {
                    ans = max(ans,j-i+1);
                    i = j-1;
                }
            }
           i++;
        }
        return ans;
    }
