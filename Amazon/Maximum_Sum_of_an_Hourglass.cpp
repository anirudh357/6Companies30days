class Solution {
public:
	int maxSum(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		int ans = INT_MIN;
		for (int i=0; i<n-2; i++){
			for (int j=0; j<m-2; j++){
				int sum = matrix[i][j]+matrix[i][j+1]+matrix[i][j+2]+matrix[i+1][j+1]+matrix[i+2][j]+matrix[i+2][j+1]+matrix[i+2][j+2];
				ans = max(ans, sum);
			}
		}
		return ans;
	}
};