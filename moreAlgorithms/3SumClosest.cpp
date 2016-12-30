#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int threeSumClosest( vector<int>& nums, int target ) {
	sort( nums.begin(), nums.end() );
	int closetSum = nums[0]+nums[1]+nums[2];
	int diff = closetSum-target;
	int len = nums.size();
	for( int i=0; i<len-2; ++i ){
		int left=i+1, right = len-1;
		int thisSum = nums[left]+nums[right]+nums[i];
		int thisDiff = thisSum-target;
		while( left<right ){
			int sum = nums[left]+nums[right]+nums[i];
			int newDiff = sum-target;
			if( (abs(newDiff)>abs(thisDiff))&&(newDiff*thisDiff>0) ){
				break;
			}else{
				thisDiff = newDiff;
				thisSum = sum;
			}
			if(sum<target){
				++left;
			}else{
				if(sum>target){
					--right;
				}else{
					return target;
				}
			}
		}
		if( abs(thisDiff)<diff ){
			closetSum = thisSum;
			diff = abs(thisDiff);
		}
	}
	return closetSum;
}

int main(){
	vector<int> nums;
	int arr[200] = {87,6,-100,-19,10,-8,-58,56,14,-1,-42,-45,-17,10,20,-4,13,-17,0,11,-44,65,74,-48,30,-91,13,-53,76,-69,-19,-69,16,78,-56,27,41,67,-79,-2,30,-13,-60,39,95,64,-12,45,-52,45,-44,73,97,100,-19,-16,-26,58,-61,53,70,1,-83,11,-35,-7,61,30,17,98,29,52,75,-73,-73,-23,-75,91,3,-57,91,50,42,74,-7,62,17,-91,55,94,-21,-36,73,19,-61,-82,73,1,-10,-40,11,54,-81,20,40,-29,96,89,57,10,-16,-34,-56,69,76,49,76,82,80,58,-47,12,17,77,-75,-24,11,-45,60,65,55,-89,49,-19,4};
	for (int i=0; i<200; ++i){
		nums.push_back(arr[i]);
	}
	threeSumClosest(nums, -275);
	cout<<threeSumClosest(nums, -275)<<endl;
	system("pause");
}
