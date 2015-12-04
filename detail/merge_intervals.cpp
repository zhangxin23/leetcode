#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 * */

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
        vector<Interval> stk;
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end()) {
            if(stk.empty()) {
                stk.push_back(*it);
            } else {
                Interval* top = &(stk[stk.size() - 1]);
                if(top->end < it->start) {
                    stk.push_back(*it);
                } else {
                    top->end = max(it->end, top->end);
                }
            }
            it++;
        }

        return stk;
    }
};
