class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>v;
        v.push_back(p1); v.push_back(p2); v.push_back(p3); v.push_back(p4);
        sort(v.begin(),v.end());
        //Checking if it is valid quadrilateral and not just a point
        if(v[0]==v[3])
        {
            return false;
        }
        bool ans1=false;
      
        int x1=v[0][0] , y1=v[0][1] , x4=v[3][0] , y4=v[3][1];
        int x2=v[1][0] , y2=v[1][1] , x3=v[2][0] , y3=v[2][1];

        //Diagonal bisect each other 
        if(x1+x4 == x2+x3 && y1+y4 == y2+y3)
        {
            //Diagonals intersect at right angle
            if((y4-y1)*(y3-y2) == (x2-x3)*(x4-x1))
            {
                // adjacent sides 90degrees
                if((y2-y1)*(y3-y1) == (x1-x3)*(x2-x1))
                {
                    ans1=true;
                }

            }
        }
        return ans1;
        

        






         

    }
};