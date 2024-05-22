class Solution {
    set<vector<int>> ans;
    void solve(vector<int>& nums,int ind,vector<int>& temp){
        if(ind>=nums.size()){
            ans.insert(temp);
            return;
        }
        //take
        temp.push_back(nums[ind]);
        solve(nums,ind+1,temp);
        temp.pop_back();
        solve(nums,ind+1,temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        vector<vector<int>> res;
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};