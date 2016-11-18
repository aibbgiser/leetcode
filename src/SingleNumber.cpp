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
/* ����1��ͳ��ÿһλ��1���ֵĴ�����Ŀ���ǽ��������ε����־���һ���������Ϊ0��������һ�ε����ֱ���ԭֵ��
/* ��˶��ڳ������ε����ֶ��ԣ�0λ���ÿ��ǣ�1λ����3�Σ�����Ϊ0�� �Խ���һ��32λ�����֣�
/* ��ͳ��ÿһλ��1���ֵĸ�������λͳ�ƽ����3ȡ�ࡣ
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
/* ����2������������one, two, three����ʶ��λ�ۻ�����1�Ĵ�����������3�Σ������㡣
/* ��Ϊ��one�͵�ǰ���ֺ��ϴ�ѭ����two�������µ�two,�ϴ�ѭ����one�͵�ǰ���־������µ�one��
/* ���ε�one�ͱ��ε�two�����˱��ε�three�����ε�threeȷ����threeΪ1��λ�ü�Ϊ����3�ε�λ��
/* ��Ҫ���㣬��˶�one��two����Ӧλ����0.
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
�������ε����֣�ֻ�а�λ���ſɵ����������尴λ���һ��֮�󣬳���һ�ε���������a,bҲ������������㣬
�õ��Ľ��diffΪ�������ֲ�ͬλΪ1����ͬλΪ0��ע�⣬diff�п����кܶ�λ����1��������ҳ�����ĳһλ��kλΪ1��
����λΪ0�Ķ�Ӧ����diff2����diff2��ԭ�������а�����λ�룬��num[i]���Ϊ�棬��num[i]���������������1��
������������������2������1���ý��Ϊa/b�е�kλΪ1����һ��������2���ý��Ϊa/b�е�kλΪ0����һ����
��diff��ȡdiff2��˼·���£�
diff2 = diff & (-diff);
diff2������diff���ұ�Ϊ1��λΪ1������λΪ0.�������£������ڼ���������Բ�����ʽ���ڣ���������diff��
�䲹��Ϊԭ�밴λȡ����ĩλ��1�������Դ���Ψһ��ͬλ����ԭ�����ҵ�һ��Ϊ1��λ�þ�Ϊ1������λ����ͬ��
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