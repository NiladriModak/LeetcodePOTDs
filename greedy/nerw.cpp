class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int xr=0;
        for(auto it:mp){
            if(it.second==2){
                xr^=it.first;
            }
        }
        return xr;
    }
};