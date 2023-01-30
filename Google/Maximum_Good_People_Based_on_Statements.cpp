class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=size(statements), ans=0;
        auto valid = [&](int cur){
            for(int i=0;i<n;i++){
                if(cur&1<<(n-1-i))
                    for(int j=0;j<n;j++){
                        if(statements[i][j]!=2 && statements[i][j]!=bool(cur&1<<(n-1-j)))
                                                return false;
                    }                            
            }                                    
            return true;                                    
        };
        for(int i=0;i<1<<n;i++){
            if(valid(i)) ans = max(ans, __builtin_popcount(i));
        }
        return ans;

    }
};