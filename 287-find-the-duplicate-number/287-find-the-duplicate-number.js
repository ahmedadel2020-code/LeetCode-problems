/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
     const map = new Map();
     for(let i = 0; i < nums.length; i++) {
        const unique = nums[i];
        if(map.has(unique)) {
          return unique;
        } else {
          map.set(nums[i], i)
        }
  }
};