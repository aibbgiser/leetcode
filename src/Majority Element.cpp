/*
��Ŀ169��Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
You may assume that the array is non-empty and the majority element always exist in the array.
����. �ҳ�һ�����г���Ƶ����ߵ�Ԫ�أ�����һ��������count��һ����ʱmajor�����������Ƚϣ�������ֵ����ɶ�ɾ����count��С����ô������µ�һ����������majority��
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
��Ŀ229��Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.
������˼·ͬ169��ֻ�Ǻ�ѡ������Ϊ2����ע������
�ٵ�һ�α���ʱ������ǰԪ����������ѡԪ�ؾ�����ͬ�����ѡԪ�ؼ���ͬʱ����1.PS.ע��˳�����ж��Ƿ�������Ԫ�ص�ֵ�����ж��Ƿ���ڼ���Ϊ0�ĺ�ѡԪ�ء�
�ڵ�һ�α����������ҳ������Ƶ���ֵ�������ѡ���֣��������Ƿ��������n/3�ε�Ҫ�󣬻���Ҫ���еڶ��α�����
����ʱ�临�Ӷ�O(2n)��Ҳ������ʱ�䣻
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