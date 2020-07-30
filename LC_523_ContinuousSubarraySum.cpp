// Done July 30 2020
// Solves LeetCode 523 Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/
// Difficulty Medium, success rate 24.6%
// Task is given an array, see if subarray adds up to multiple of another given number.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // The idea is to keep adding the numbers in nums modulo k.
        // If you hit a remainder you had before, then the numbers in between
        // add up to a number divisible by k.
        // Or if you add up to a multiple of k, you got it.
        // Lots of special cases to take care of: 
        // -- need at least two elements added together
        // -- if have a zero, that repeats a remainder, so doesn't count
        // -- but two zeros in a row do count
        int nlen = nums.size();
        if (nlen<2) { return false;}   // need at least two elements
        if ((k==1 || k==-1) && nlen>1 ) { return true; } // true even if nums is zeros
        if (k<0) { k*=-1;} // for ease
        for (int ii=0; ii<nlen-1; ii++) { // if you have two zeros in a row, return true
            if (nums[ii]==0 && nums[ii+1]==0) {
                    return true;
                }
        }

        if (k==0) {  // need two zeros in a row otherwise get division by zero
            for (int ii=0; ii<nlen-1; ii++) { 
                if (nums[ii]==0 && nums[ii+1]==0) {
                    return true;
                }
            }
            return false;
        }
        
        std::unordered_map<long, long> themap;  // map of remainders so far
        long runningsum=nums[0]%k;              // current remainder of sum
        themap[runningsum]=1;
        for (int ii=1; ii<nlen; ii++) {
            if (nums[ii]!=0) runningsum=(runningsum+nums[ii])%k;  //update runningsum
            // return true if meet conditions listed at top of code
            if ((runningsum==0 || themap[runningsum]==1) && nums[ii]!=0 && nums[ii]%k!=0) { return true; }
            // otherwise update map of remainders
            else {themap[runningsum]=1;}
        }
        return false;
    }
};

