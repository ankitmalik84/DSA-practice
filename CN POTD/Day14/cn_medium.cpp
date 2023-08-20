int minimumReschedules(int n, vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    int count = 0;
    int lastEndTime = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] < lastEndTime) {
            count++;
            lastEndTime = min(lastEndTime, intervals[i][1]);
        } else {
            lastEndTime = intervals[i][1];
        }
    }

    return count;
}
