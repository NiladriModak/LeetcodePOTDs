class Solution {
    int solve(vector<int>& nums,vector<int>& temp,int ind,int k){
        if(ind>=nums.size()){
            
            return 0;
        }
        bool check=false;
        int lw=lower_bound(temp.begin(),temp.end(),(nums[ind]-k))-temp.begin();
        if(lw<temp.size()){
            if(temp[lw]==(nums[ind]-k)){
                check=true;
            }
        }
        int take=0,nottake=0;
        if(temp.size()==0 || !check){
            temp.push_back(nums[ind]);
            take=1+solve(nums,temp,ind+1,k);
            temp.pop_back();
        }
        nottake+=solve(nums,temp,ind+1,k);
        return take+nottake;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        return solve(nums,temp,0,k);
        // return st.size()-1;
    }
};