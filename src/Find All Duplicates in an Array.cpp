class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        if( len<=1 )
        return res;
        //method 1.����λ�÷�
        //˼�룺����nums��ÿ�ΰ�Ԫ��ֵ��Ϊ��������ӳ�䵽���Ӧλ�ã�����Ԫ��ֵ��ͬ������ظ�ӳ����ͬһλ�ã���ʱ�������ڶ��ߵ���������ֵ��ֵΪ0������Ŀ�꣬�ظ����ֵ���λ�ó�ͻ��Ԫ�ظ�ֵΪ0���õ�������һ�ε�Ԫ�ذ�ֵӳ�������е�num
        //149 ms,beat 75%
        for( int i=0; i<len; ++i ){
            while( (nums[i]>0)&&(nums[i]!=i+1) ){  //δ��ʶΪ������Ҵ���������������
                if( nums[i]==nums[nums[i]-1] ){
                    res.push_back(nums[i]);
                    nums[i] = 0;
                    //nums[nums[i]-1] = 0;
                }else{
                    swap(nums[i],nums[nums[i]-1]);
                }
            }
        }
/*
        //metiod 2. ��ֵ��Ƿ�
        //˼�룺����ֵ�ľ���ֵӳ�䵽��Ӧλ�ã�����һ�γ��֣�����λ���Լ���ֵ��ʶΪ��ֵ���ڶ��γ��֣���ᷢ�ָ�λ�õ�ֵ�Ѿ�Ϊ��ֵ������res
        for( int i=0; i<len; ++i ){
            //int index = abs(nums[i])-1;             //156ms,beats 58%
            int index = (nums[i]>0) ? (nums[i]-1) : (-nums[i]-1);            //175ms,beats 45%
            if( nums[index]<0 ){
                res.push_back(index+1);
            }else{
                nums[index] = -nums[index];
            }
        }
*/        return res;
    }
};