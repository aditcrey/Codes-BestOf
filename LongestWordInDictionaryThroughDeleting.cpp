//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/


//Solution Logic: Sort accoring to lexico and length. Check for strings which are subsequence of the given string. That is the answer.
class Solution {
public:
    
    static bool compare(string a,string b){
        if(a.length()==b.length()) return a<b;
        else return a.length()>b.length();
    }
    
    bool isSubsequence(string a,string b){ //is b a subsequence of a

        int n = a.length(), m = b.length();
        
        int j=0,i=0;
        
        for(;i<n&&j<m;i++) if(a[i]==b[j]) j++;
        
        return j==m;
    
    }
    
    string findLongestWord(string s, vector<string>& d) {
        
        int n = d.size();
        sort(d.begin(),d.end(), compare);
        // for(int i=0;i<n;i++) cout<<d[i]<<" ";
        // cout<<endl;
        
        int maxLength = 0;
        for(int i=0;i<n;i++)
            if(isSubsequence(s,d[i]))
                return d[i];

        return "";
    }
};
