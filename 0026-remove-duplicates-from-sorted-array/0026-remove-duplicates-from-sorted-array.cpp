class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        if(n == 0) return 0;
        temp.push_back(nums[0]);

        for(int i = 1; i<n; i++){
            if(nums[i] != nums[i-1]){
                temp.push_back(nums[i]);
            }
        }
        for(int i = 0; i  < temp.size(); i++){
            nums[i] = temp[i];
        }
        return temp.size();
        
    }
};