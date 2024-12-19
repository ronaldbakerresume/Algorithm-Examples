#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end;
};

// Function to find the maximum number of overlapping intervals
int maxOverlappingIntervals(vector<Interval>& intervals) {
    vector<pair<int, int>> events;
    for (const auto& interval : intervals) {
        events.push_back({interval.start, 1});  // Start of interval
        events.push_back({interval.end, -1});   // End of interval
    }

    // Sort events based on time, breaking ties by type (end before start)
    sort(events.begin(), events.end());

    int maxOverlap = 0, currentOverlap = 0;
    for (const auto& event : events) {
        currentOverlap += event.second;
        maxOverlap = max(maxOverlap, currentOverlap);
    }
    return maxOverlap;
}

int main() {
    vector<Interval> intervals = {{1, 3}, {2, 5}, {4, 6}, {5, 8}, {7, 9}};
    cout << "Maximum Overlapping Intervals: " << maxOverlappingIntervals(intervals) << endl;
    return 0;
}

