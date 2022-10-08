int calculate(string s) {
        stack<int> st;
        char sign = '+';
        s += '+';
        long long int curr = 0;
        int n = s.length();
        for(int i = 0; i<n; i++)
        {
            if(isdigit(s[i])) curr = curr*10 + s[i]-'0';
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if(sign == '+') st.push(curr);
                else if(sign == '-') st.push(curr*-1);
                else if(sign == '*')
                {
                    int num = st.top(); st.pop();
                    st.push(num * curr);
                }
                else 
                {
                    int num = st.top(); st.pop();
                    st.push(num / curr);
                }
                sign = s[i];
                curr = 0;
            }
        }
        int ans = 0;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
