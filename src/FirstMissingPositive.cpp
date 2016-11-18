class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //把出现过的数值的下标位置做好标识，如果没有出现过的数组的下标就没有标识，那么这个就是答案。
        int len = nums.size();
        for( int i=0; i<len; ){
            if( nums[i] != i + 1 && nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1] ){
                swap( nums[i],nums[nums[i]-1] );
            }else{
                ++i;
            }
        }
        for( int i=0; i<len;++i ){
            if( nums[i]!=i+1 ){
                return i+1;
            }
        }
        return len+1;
    }
};