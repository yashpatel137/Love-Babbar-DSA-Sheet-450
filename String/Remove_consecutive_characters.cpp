class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string ans="";
        S+=' ';
        int n=S.length();
        for(int i=0;i<n-1;i++)
        {
            if(S[i]!=S[i+1])
            {
                ans+=S[i];
            }
        }
        return ans;
    }
};