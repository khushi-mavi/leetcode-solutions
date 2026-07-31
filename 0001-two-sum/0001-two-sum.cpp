class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> indexed;
        for(int i = 0; i < n; i++) indexed.push_back({nums[i],i});
        sort(indexed.begin(),indexed.end());
        
        
        int i = 0;
        int j = n-1;
       while(i<j){
        int sum = indexed[i].first + indexed[j].first;
        if(sum > target) j--;
        else if(sum<target) i++;
        else return{indexed[i].second, indexed[j].second};
       }
        return{};
    }
};