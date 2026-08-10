class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        left = 0
        right = n-1
        while left < right:
         current_sum = numbers[left] + numbers[right]
         if current_sum == target:
            return[left+1,right+1]    
         elif current_sum < target:
            left = left+1
         else:
            right = right-1
        
        