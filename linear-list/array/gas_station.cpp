#include <iostream>
#include <vector>

using namespace std;

/**
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs  of gas to travel from station i to its next station (i+1).
 * You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station’s index if you can travel around the circuit once, otherwise return -1.
 * Note: The solution is guaranteed to be unique.
 *
 * 证明过程：
 * 1 从i开始，j是当前station的指针，sum += gas[j] – cost[j] （从j站加了油，再算上从i开始走到j剩的油，走到j+1站还能剩下多少油）
 * 2 如果sum < 0，说明从i开始是不行的。那能不能从i..j中间的某个位置开始呢？假设能从k (i<=k<=j)走，那么i..j < 0，若k..j >=0，说明i..k – 1更是<0，那从k处就早该断开了，根本轮不到j。
 * 3 所以一旦sum<0，i就赋成j + 1，sum归零。
 * 4 最后total表示能不能走一圈。
 *
 * */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int j = -1;
        for(int i = 0, sum = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
};
