class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        if(len<=1)
        return res;
        /*
        //method 1. 2nʱ�临�Ӷ�
        for( int i=0; i<len; ++i ){
            int idx = abs(nums[i])-1;
            if( nums[idx]>0 ){
                nums[idx] = -nums[idx];
            }
        }
        for( int i=0; i<len; ++i ){
            if( nums[i]>0 ){
                res.push_back(i+1);
            }
        }
        */
        //method 2. ��������ҪĿ����Ԫ�ع�λ��ÿ��Ԫ��ӳ�䵽ֵΪ���꣬��
        //a.Ŀ��ӳ��λ�����к͵�ǰԪ����ȵ�Ԫ�أ�˵����ǰλ�ö�ӦԪ�ؿ�����ȱʧ�ģ���ʱ���Ϊȱʧ��ǰ��һ��λ��
        //b.��Ŀ��λ�ÿ��ã������жϵ�ǰλ��Ԫ���Ƿ�������ǹ�ȱʧ�����ǣ��ı��Ϊ��ȱʧ�����򽻻���ǰλ����Ŀ��λ�ã�ѭ��ֱ��ȫ����λΪֹ
        for( int i=0; i<len; ){
            if( nums[i]!=i+1 ){
                int idx = nums[i]-1;
                if( nums[i]==nums[idx] ){
                    res.push_back(++i);
                }else{
                    vector<int>::iterator iter = find( res.begin( ), res.end( ), nums[i] );
                    if( iter!= res.end() )
                    res.erase(iter);
                    swap( nums[i], nums[idx] );
                }
            }else{
                ++i;
            }
        }
        return res;
    }
};