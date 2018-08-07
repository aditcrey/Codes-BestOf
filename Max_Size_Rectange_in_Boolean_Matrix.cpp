class Solution {
public:
    
    int maxAreaUnderHist(vector<int> hist){
        stack<int> stk;
        int n =hist.size();
        int i=0;
        int max_area = 0;
        while(i<n){

            if(stk.empty()) {stk.push(i); i++;}
            else{
                if(hist[stk.top()] <= hist[i]) {stk.push(i); i++;}
                else{
                    int tp = stk.top();
                    stk.pop();
                    max_area = max(max_area, hist[tp] * (stk.empty()?i:i-stk.top()-1));
                }
            }
        }
        
        while(!stk.empty()){

            int tp = stk.top();
            stk.pop();
            max_area = max(max_area, hist[tp]* (stk.empty()?i:i-stk.top()-1));   
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> hist;
        int r = matrix.size(); //rows
        if(r==0) return 0;
        int c = matrix[0].size(); //columns
        if(c==0) return 0;
        int max_so_far = 0;
        for(int j=0;j<c;j++) hist.push_back(matrix[0][j] - '0');
        // for(int i=0;i<c;i++) cout<<hist[i]<<endl;
        max_so_far = maxAreaUnderHist(hist);
        // cout<<"maxsofor: "<<max_so_far<<endl;
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1'){
                    hist[j] = hist[j] + 1;
                }else{
                    hist[j] = 0;
                }
                
            }
            for(int k=0;k<c;k++) cout<<hist[k]<<" ";
            max_so_far = max(max_so_far, maxAreaUnderHist(hist));
                // cout<<"row "<<i<<" maxsofar "<<max_so_far<<endl;
        }
        return max_so_far;
    }
};
