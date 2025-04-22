#include <iostream>
using namespace std;
void intervalScheduling(int intervals[][2], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (intervals[j][1] > intervals[j + 1][1]) {
                int tempStart = intervals[j][0];
                int tempEnd = intervals[j][1];
                intervals[j][0] = intervals[j + 1][0];
                intervals[j][1] = intervals[j + 1][1];
                intervals[j + 1][0] = tempStart;
                intervals[j + 1][1] = tempEnd;
            }
        }
    }
    cout << "Selected intervals: ";
    int lastEndTime = -1;
    for (int i = 0; i < n; i++) {
        if (intervals[i][0] >= lastEndTime) {
            cout << "(" << intervals[i][0] << ", " << intervals[i][1] << ") ";
            lastEndTime = intervals[i][1];
        }
    }
    cout << endl;
}
int main() {
    int intervals[][2] = {{1, 3}, {2, 5}, {4, 6}, {6, 8}, {5, 7}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    intervalScheduling(intervals, n);
    return 0;
}
