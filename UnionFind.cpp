
class Solution {
public:
    
    int find(int c, vector<int> &parent){
        if(parent[c]!=c){
            parent[c] = find(parent[c], parent);
        }
        return parent[c];
    }
    
    void uni(int a,int b, vector<int> &parent, vector<int> &rank){
        int xPar = find(a,parent);
        int yPar = find(b,parent);
        
        if(xPar!=yPar){
        if(rank[xPar]> rank[yPar]) {
            parent[yPar] = xPar; 
            rank[yPar]++;
            }
        else {parent[xPar] = yPar;
              rank[xPar]++;
             }
        }
    }
    
    bool inSameSet(int a,int b,vector<int> &parent){
        int xPar = find(a,parent);
        int yPar = find(a,parent);
        if(xPar == yPar) return true;
        return false;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        
        
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]==1){
                    uni(i,j,parent,rank);
                }
            }
        }
        
        int count = 0 ;
        for(int i=0;i<n;i++){
            if(parent[i]==i) count++;
        }
        return count;
        
        
        
    }
};
