class Solution {
    int maxi=0;
    void check(vector<vector<int>>& m,vector<int>& tem){
        int num=m.size();
        vector<int> temp;
        for(int i=0;i<m[0].size();i++){
            if(binary_search(tem.begin(),tem.end(),i)==false){
                temp.push_back(i);
                // cout<<endl<<"This "<<i<<endl;
            }
        }
        // cout<<"num="<<num<<endl;
        for(int i=0;i<m.size();i++){
            int flag=0;
            for(int j=0;j<temp.size();j++){
                if(m[i][temp[j]]==1){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                num--;
            }
        }
        // cout<<"num="<<num<<endl;
        maxi=max(maxi,num);
    }
    void solve(vector<vector<int>>& m,int ind,int num,vector<int>& temp){
        if(ind>m[0].size()){
            return ;
        }
        if(num==0){
            check(m,temp);
            return ;
        }
        temp.push_back(ind);
        solve(m,ind+1,num-1,temp);
        temp.pop_back();
        solve(m,ind+1,num,temp);
    }
public:
    int maximumRows(vector<vector<int>>& matrix, int num) {
        vector<int> temp;
        solve(matrix,0,num,temp);
        return maxi;
    }
};