class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n= len(nums)
        if n == 0:
            return 0
        temp = []
        temp.append(nums[0])
        for i in range(1,n):
            if nums[i] != nums[i-1]:
                temp.append(nums[i])
        for i in range(len(temp)):
            nums[i] = temp[i]
        return len(temp)               
        