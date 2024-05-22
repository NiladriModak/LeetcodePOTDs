class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int x=0;
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=0;i<30;i++){
            if(mp.find(pow(2,i))==mp.end())
            return (int)pow(2,i);
        }
        return (int)pow(2,30);
    }
};