class Solution {
public:
    string getHint(string secret, string guess) {
        int sz=secret.size();
        vector<int> numbers(10);
        int bulls = 0, cows = 0;
        for(int i = 0; i<sz ; i++){
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if(s==g){
                bulls++;
            }
            else{
                if(numbers[s]<0) cows++;
                if(numbers[g]>0) cows++;
                numbers[s]++;
                numbers[g]--;
            }
        } 
        return bulls+"A"+cows+"B";
    }
};