//https://leetcode.com/problems/find-the-duplicate-number/description/
#define ll long long int
class Solution {
public:
    int next(int a,vector<int> &nums){
        return nums[a];
    }
    
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, f = 0;
        do{
            s = next(s,nums);
            f = next(next(f,nums),nums);
        }while(s!=f);
        
        cout<<"f: "<<f<<" s: "<<s<<endl;
        
        int p1=0,p2=s;
        while(next(p1,nums)!=next(p2,nums)){
            cout<<"p1: "<<p1<<" p2: "<<p2<<endl;
            p1 = next(p1,nums);
            p2 = next(p2,nums);
        }
        
        return next(p1,nums);
    }
};
