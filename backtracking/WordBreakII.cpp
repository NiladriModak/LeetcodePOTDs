class Solution {
    vector<string> ans;
    map<string,int> mp;
    string check(string s,int st,int end){
        int num=end-st+1;
        if(mp.find(s.substr(st,num))!=mp.end())
        return s.substr(st,num);
        return "";
    }
    void solve(string& s,vector<string>& word,int ind,string temp){
        if(ind>=s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=ind;i<s.size();i++){
            string u=check(s,ind,i);
            if(u!=""){
                string h;
                if(temp!="")
                h=temp+" "+u;
                else
                h=temp+u;
                solve(s,word,i+1,h);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& word) {
        mp.clear();
        for(auto it:word){
            mp[it]++;
        }

        solve(s,word,0,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};