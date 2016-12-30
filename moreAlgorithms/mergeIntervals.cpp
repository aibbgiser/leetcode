#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

 //Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if( intervals.empty() ) return res;
        sort( intervals.begin(), intervals.end(), comp );
		res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            }else{
                res.push_back(intervals[i]);
            }
        }
		for ( vector<Interval>::iterator iter = res.begin(); iter!=res.end(); ++iter ){
			cout<<(*iter).start<<" "<<(*iter).end<<endl;
		}
        return res;
    }
private:
    static bool comp(const Interval &a, const Interval &b) {
        return (a.start<b.start);
    }
};

int main(){
	vector<Interval> obj;
	//Interval tmpObj(1,3);
	obj.push_back(Interval (1,3));
	obj.push_back(Interval (8,10));
	obj.push_back(Interval (2,6));
	obj.push_back(Interval (15,18));
	for ( vector<Interval>::iterator iter = obj.begin(); iter!=obj.end(); ++iter ){
		cout<<(*iter).start<<" "<<(*iter).end<<endl;
	}
	Solution sol;
	sol.merge(obj);
	for ( vector<Interval>::iterator iter = obj.begin(); iter!=obj.end(); ++iter ){
		cout<<(*iter).start<<" "<<(*iter).end<<endl;
	}
	system("pause");
}