class Solution {
private:
    int mod=1e9+7;    
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> persons(n+1,0);
        long long numberOfPeopleSharingSecret=0;
        long long ans=0;
        persons[1]=1;

        for(int i=2;i<=n;i++){
            if(i-delay>=0){
                numberOfPeopleSharingSecret = (numberOfPeopleSharingSecret+persons[i-delay])%mod;

            } // mod to avoid overflow and underflow conditions
            if(i-forget>=0){
                numberOfPeopleSharingSecret = (numberOfPeopleSharingSecret-persons[i-forget]+mod)%mod; 
            }
            persons[i]=numberOfPeopleSharingSecret;
        }
        for(int i=n-forget+1; i<=n;i++){
            ans=(ans+persons[i])%mod;
        }
        return ans;
    }
};