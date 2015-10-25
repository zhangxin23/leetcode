/**
 *The gray code is a binary numeral system where two successive values differ in only one bit.
 *Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
 *A gray code sequence must begin with 0.
 *For example, given n = 2, return [0, 1, 3, 2]. Its gray code sequence is:
 *  00 - 0
 *  01 - 1
 *  11 - 3
 *  10 - 2
 *Note:
 *  • Foragivenn,agraycodesequenceisnotuniquelydefined.
 *  • Forexample,isalsoavalidgraycodesequenceaccordingtotheabovedefinition.
 *  • For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 * */

class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> result;
            int size = 1 << n;
            result.reserve(size);
            for(int i = 0; i < size; i++) {
                result.push_back(i ^ (i >> 1));
            }
            return result;
        }
};
