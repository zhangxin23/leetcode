#include <iostream>
#include <vector>

using namespace std;

/**
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 * */

//Definition for a point.
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 3)
            return points.size();

        int result = 0;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int a = points[j].x - points[i].x;
                int b = points[j].y - points[j].x;
                int c = a * points[i].y - b * points[i].x;

                int count = 0;
                for(int k = 0; k < points.size(); k++) {
                    if(a * points[k].y == c + b * points[k].x)
                        count++;
                }

                if(count > result)
                    result = count;
            }
        }

        return result;
    }
};
