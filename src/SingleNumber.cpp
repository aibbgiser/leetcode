//first
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        if(length<1) return 0;
        if(length<2) return nums[0];
        int res = nums[0];
        for( int i=1; i<length; ++i ){
            res ^= nums[i];
        }
        return res;
    }
};

//second
/*
/* 方案1，统计每一位上1出现的次数。目标是将出现三次的数字经过一定运算后置为0，而出现一次的数字保持原值。
/* 因此对于出现三次的数字而言，0位不用考虑，1位出现3次，则置为0； 以建立一个32位的数字，
/* 来统计每一位上1出现的个数，该位统计结果对3取余。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};
/* 
/* 方案2，用三个整数one, two, three来标识各位累积出现1的次数，若出现3次，则清零。
/* 因为是one和当前数字和上次循环的two决定了新的two,上次循环的one和当前数字决定了新的one，
/* 本次的one和本次的two决定了本次的three，本次的three确定后，three为1的位置即为出现3次的位置
/* 需要清零，因此对one和two的相应位置置0.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int ones = 0, twos = 0, threes = 0;
        for( int i=0; i<length; ++i){
            twos |= ones&nums[i];
            ones ^= nums[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

//third
/*
出现两次的数字，只有按位异或才可抵消，而整体按位异或一遍之后，出现一次的两个数字a,b也进行了异或运算，
得到的结果diff为两个数字不同位为1，相同位为0。注意，diff中可能有很多位都是1，如果能找出它仅某一位第k位为1，
其他位为0的对应数字diff2，将diff2和原数字序列挨个按位与，若num[i]结果为真，则num[i]参与异或运算序列1，
否则参与异或运算序列2，序列1所得结果为a/b中第k位为1的那一个，序列2所得结果为a/b中第k位为0的那一个。
从diff获取diff2的思路如下：
diff2 = diff & (-diff);
diff2保留了diff最右边为1的位为1，其余位为0.理由如下：数字在计算机中是以补码形式存在，对于正数diff，
其补码为原码按位取反，末位加1，补码和源码的唯一相同位在于原码最右第一个为1的位置均为1，其他位均不同。
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
/*        vector<int> res;
        int length = nums.size();
        if( length<1 ) 
            return res;
        int result = nums[0];
        for( int i=1; i<length; ++i){
            result ^= nums[i];
        }
        res[0] = 0;
        res[1] = 0;
        int n = result & (~(result-1)); 
        for( int i=0; i<length; ++i){
            if((n & nums[i])!=0){
                res[0] = res[0] ^ nums[i]; 
            }else{
                res[1] = res[1] ^ nums[i];
            }
        }
        return res;
*/
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res(2, 0);
        for (auto &a : nums) {
            if (a & diff) res[0] ^= a;
            else res[1] ^= a;
        }
        return res;
    }
};