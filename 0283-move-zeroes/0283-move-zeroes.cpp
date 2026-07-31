class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int end = n-1;
        int i = 0;
        while(i<=end){
            if(nums[i] == 0){
                for(int j = i; j<end; j++){
                    nums[j] = nums[j+1];

                }
                nums[end] = 0;
                end--;
            }else{
                i++;
            }
        }
        
    }
};