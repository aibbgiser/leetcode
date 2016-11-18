//首先分别翻转前n-k个元素组和后k个元素组，再整体翻转一次；
//注意：题目没限制k一定小于n，所以要用k=k%n;来防止越界。
//该方案空间复杂度O(1),但是时间复杂度线性.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        for( int i=0,j=n-k-1; i<j; ++i,--j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        for( int i=n-k,j=n-1; i<j; ++i,--j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        for( int i=0,j=n-1; i<j; ++i,--j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};