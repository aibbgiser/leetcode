//���ȷֱ�תǰn-k��Ԫ����ͺ�k��Ԫ���飬�����巭תһ�Σ�
//ע�⣺��Ŀû����kһ��С��n������Ҫ��k=k%n;����ֹԽ�硣
//�÷����ռ临�Ӷ�O(1),����ʱ�临�Ӷ�����.
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