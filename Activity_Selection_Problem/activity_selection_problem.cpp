#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivities);

    cout << "Selected Activities:\n";
    int lastFinish = -1;
    for (const auto& activity : activities) {
        if (activity.start >= lastFinish) {
            cout << "(" << activity.start << ", " << activity.finish << ")\n";
            lastFinish = activity.finish;
        }
    }
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 9}, {8, 9}};
    activitySelection(activities);
    return 0;
}

