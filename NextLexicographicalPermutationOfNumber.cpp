class Solution {
public:
    void swap(int l,int r,vector<int> &nums){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]) break;
        }
        
        if(i!=0){
        int mn = INT_MAX;
        int mnIdx = -1;
        for(int j=i;j<n;j++){
            if(nums[j]>nums[i-1])
                if(nums[j]<mn){
                    mnIdx = j;
                    mn = nums[j];
                }
        }
        
        cout<<"The mnIdx is: "<<mnIdx<<"with value: "<<mn<<endl;
        swap(i-1,mnIdx,nums);
            
        }
        
        // for(int j=i;j<(i+(n-i)/2);j++){//reversing the number
        //     swap(j,n-1-(j-i),nums);
        // }
        sort(nums.begin()+i,nums.end());
        
        
        
    }
};
