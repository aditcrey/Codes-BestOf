class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m==0) return ans;
        int n = matrix[0].size();
        
        //defining the directions
        int dc[] = {1,0,-1,0};
        int dr[] = {0,1,0,-1};
        vector<vector<bool> > seen(m, vector<bool> (n,false)); 
        int r = 0,c=0,di=0;
        for(int i=0;i<m*n;i++){
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr  = r +  dr[di];
            int cc = c +  dc[di];
            if(cr>=0 && cr<m && cc>=0 && cc<n && !seen[cr][cc]){

                r = cr;
                c = cc;
                
            }else{
                di = (di+1)%4;
                r += dr[di];
                c += dc[di];
            }
            
        
        }
        
        return ans;
        
    }
};
