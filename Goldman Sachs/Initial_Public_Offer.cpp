class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int, int>> projects(n);
        for(int i=0;i<n;i++){
            projects[i]={profits[i], capital[i]};
        } 
        int i=0;
        sort(projects.begin(), projects.end(), [&](pair<int, int> a, pair<int, int> b){return a.second<b.second;});
        priority_queue<int> maxprofit;

        while(k--){
            while(i<n && w>=projects[i].second)
                maxprofit.push(projects[i++].first);

            if(!maxprofit.empty())
                w+=maxprofit.top(), maxprofit.pop();    
        }
        return w;
    }
};