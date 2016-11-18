class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //�ѳ��ֹ�����ֵ���±�λ�����ñ�ʶ�����û�г��ֹ���������±��û�б�ʶ����ô������Ǵ𰸡�
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