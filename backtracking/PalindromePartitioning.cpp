
class Solution {
public:
    bool palin(string s)
    {
        int j=0,i=s.length()-1;
        while(j<=i)
        {
            if(s[j++]!=s[i--])
                return false;
        }
        return true;
    }
    void partition(string s,vector<string>& k,vector<vector<string>>& ans)
    {
        if(s.length()==0)
        {
            ans.push_back(k);
        }
        for(int i=0;i<s.length();i++)
        {
            if(palin(s.substr(0,i+1))){
                k.push_back(s.substr(0,i+1));
                partition(s.substr(i+1),k,ans);
                k.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> k;
        partition(s,k,ans);
        return ans;
    }
};