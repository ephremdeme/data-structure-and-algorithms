def is_monotonic_array(nums): 
    return (all(nums[i] <= nums[i + 1] for i in range(len(nums) - 1)) or 
            all(nums[i] >= nums[i + 1] for i in range(len(nums) - 1))) 
            
            
assert is_monotonic_array([1,1,2,3,7]) == True
