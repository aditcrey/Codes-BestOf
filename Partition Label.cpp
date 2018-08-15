//https://leetcode.com/problems/partition-labels/description/
typedef long long int ll;
class Solution {
public:
    vector<int> partitionLabels(string S) {
                ll n = S.length();
        vector<int> last(26,-1);
        for(ll i=0;i<n;i++) last[S[i]-'a'] = i; //stores the last occurance
        // for(ll j=0;j<26;j++) cout<<(char)('a'+ j)<<last[j]<<" ";
        // ll count = 0;
        ll i = 0,j=0;
        ll anchor = 0;
        vector<int> ans;
        while(i<n && j<n){
            // cout<<"j"<<j<<endl;
            if(j<last[S[i]-'a']) j = last[S[i]-'a'];
            if(i==j) {
                // cout<<"ancdhord: "<<anchor<<endl;
                ans.push_back(i-anchor + 1);
                anchor = j+1;
                j++;
            }
            i++;
        }
        
        return ans;
        
        
    }
};
