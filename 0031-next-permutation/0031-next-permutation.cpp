class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n=nums.size();
    int i;
    int ind=-1;
    for(i=n-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
            ind=i;
            break;
        }

    }
    if(ind==-1)
    {
       reverse(nums.begin(),nums.end());
       return;
    }
    for(i=n-1;i>ind;i--)
    {
        if(nums[i]>nums[ind])
        {
            swap(nums[i],nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1,nums.end());
    return;
    }
};