class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        map<int,int> mp,col;
        int num=0;
        vector<int> ans;
        for(auto it:q){
            if(mp.find(it[0])!=mp.end()){
                if(col[mp[it[0]]]==1){
                    num--;
                    col.erase(mp[it[0]]);
                }else{
                    col[mp[it[0]]]--;
                }
                if(col.find(it[1])==col.end()){
                    num++;
                }
                col[it[1]]++;
                mp[it[0]]=it[1];
            }else{
                mp[it[0]]=it[1];
                if(col.find(it[1])==col.end()){
                    num++;
                }
                col[it[1]]++;
            }
            ans.push_back(num);
        }
        return ans;
    }
};