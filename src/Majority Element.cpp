/*
题目169：Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
You may assume that the array is non-empty and the majority element always exist in the array.
方案. 找出一组数中出现频率最高的元素，设置一个计数器count和一个临时major变量，挨个比较，若不等值对则成对删除，count减小，那么最后留下的一定是真正的majority。
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major = 0;
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                major = nums[i];
                ++count;
            }else{
                if(major==nums[i]){
                    ++count;
                }else{
                    --count;
                }
            }
            if( count > nums.size()/2 )
            return major;
        }
        return major;
    }
};

/*
题目229：Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.
方案：思路同169，只是候选众树变为2个；注意两点
①第一次遍历时，若当前元素与两个候选元素均不相同，则候选元素计数同时各减1.PS.注意顺序，先判断是否与已有元素等值，再判断是否存在计数为0的候选元素。
②第一次遍历结束后，找出了最高频出现的两个候选数字，该数字是否满足多于n/3次的要求，还需要进行第二次遍历。
所以时间复杂度O(2n)，也是线性时间；
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int major1 = 0, major2 = 0;
        for( int i=0; i<nums.size(); ++i){
            if( major1 == nums[i]){
                ++count1;
            }else{
                if( major2 == nums[i] ){
                    ++count2;
                }else{
                    if( count1 == 0){
                        major1 = nums[i];
                        ++count1;
                    }else{
                        if( count2 == 0){
                            major2 = nums[i];
                            ++count2;
                        }else{
                            --count1;
                            --count2;
                        }
                    }
                }
            }
        }
        count1 = 0;
        count2 = 0;
        for( int i=0; i<nums.size(); ++i){
            if(major1 == nums[i]){
                ++count1;
            }else{
                if(major2 == nums[i]){
                    ++count2;
                }
            }
        }
        vector<int> major;
        if( count1 > nums.size()/3 )
        major.push_back(major1);
        if( count2 > nums.size()/3 )
        major.push_back(major2);
        return major;
    }
};