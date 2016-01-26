#include <iostream>
#include <vector>
#include <bits/stl_stack.h>

using namespace std;

/**
 * Given an absolute path for a file (Unix-style), simplify it.
 * For example,
 *  path = "/home/", => "/home"
 *  path = "/a/./b/../../c/", => "/c"
 * Corner Cases:
 *  • Did you consider the case where path = "/../"? In this case, you should return "/".
 *  • Another corner case is the path might contain multiple slashes '/' together,
 *    such as "/home//foo/". In this case, you should ignore redundant slashes and return "/home/foo".
 * */

class Solution {
public:
    string simplifyPath(string path) {
        string curDir;
        vector<string> vec;

        path += "/";
        for(int i = 0; i < path.length(); i++) {
            if(path[i] == '/') {
                if(curDir.empty())
                    continue;
                else if(curDir == ".")
                    curDir.clear();
                else if(curDir == "..") {
                    if(vec.empty())
                        vec.pop_back();
                    curDir.clear();
                } else {
                    vec.push_back(curDir);
                    curDir.clear();
                }
            } else {
                curDir += path[i];
            }
        }

        string result;
        if(vec.empty())
            return "/";
        else {
            for(int i = 0; i < vec.size(); i++)
                result += vec[i];
            return result;
        }
    }
};
