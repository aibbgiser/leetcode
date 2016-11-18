class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        if( len<=1 )
        return res;
        //method 1.交换位置法
        //思想：遍历nums，每次按元素值作为坐标索引映射到其对应位置，若俩元素值相同，则会重复映射至同一位置，此时，类似于二者抵消，将该值赋值为0；最终目标，重复出现导致位置冲突的元素赋值为0，得到仅出现一次的元素按值映射重排列的num
        //149 ms,beat 75%
        for( int i=0; i<len; ++i ){
            while( (nums[i]>0)&&(nums[i]!=i+1) ){  //未标识为结果、且待交换对象不是自身
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
        //metiod 2. 负值标记法
        //思想：按照值的绝对值映射到相应位置，若第一次出现，将该位置自己的值标识为负值，第二次出现，则会发现该位置的值已经为负值，加入res
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