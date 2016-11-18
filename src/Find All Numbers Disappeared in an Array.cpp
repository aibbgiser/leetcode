class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        if(len<=1)
        return res;
        /*
        //method 1. 2n时间复杂度
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
        //method 2. 遍历，主要目标是元素归位，每个元素映射到值为坐标，若
        //a.目标映射位置已有和当前元素相等的元素，说明当前位置对应元素可能是缺失的，暂时标记为缺失；前进一格位置
        //b.若目标位置可用，则先判断当前位置元素是否曾被标记过缺失，若是，改标记为非缺失；否则交换当前位置与目标位置，循环直到全部归位为止
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