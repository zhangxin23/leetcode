#include <iostream>
#include <vector>

using namespace std;

/**
 *Given an absolute path for a file (Unix-style), simplify it.
 *For example,
 *  path = "/home/", => "/home"
 *  path = "/a/./b/../../c/", => "/c"
 *Corner Cases:
 *  • Did you consider the case where path = "/../"? In this case, you should return "/".
 *  • Another corner case is the path might contain multiple slashes '/' together,
 *    such as "/home//foo/". In this case, you should ignore redundant slashes and return "/home/foo".
 * */

class Solution {
    public:
        string simplifyPath(const string &path) {
            vector<string> dirs;

            for(int i = 0; i < path.length();) {
                i++;
                int j = path.find('/', i);
                string dir = path.substr(i, j);
                if(!dir.empty() && dir != ".") {
                    if(dir == "..") {
                        if(!dirs.empty())
                            dirs.pop_back();
                    } else {
                        dirs.push_back(dir);
                    }
                }
                i = j;
            }

            string result;
            if(dirs.empty()) {
                result += "/";
            } else {
                for(auto dir: dirs) {
                    result += "/" + dir;
                }
            }

            return result;
        }
};