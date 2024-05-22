class Solution {
public:
#define ll long long 
    long long minimumPerimeter(long long na) {
        ll cnt=0;
        ll y=0;
        while(y<na){
            cnt++;
            y+=(12*cnt*cnt);
        }
        return 8*cnt;
    }
};