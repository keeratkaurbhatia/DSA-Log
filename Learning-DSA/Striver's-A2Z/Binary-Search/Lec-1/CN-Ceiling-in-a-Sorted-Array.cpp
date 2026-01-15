pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int l = 0, r = n - 1;
    int floor = -1, ceil = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) {
            return {x, x};
        }
        if (a[mid] < x) {
            floor = a[mid];
            l = mid + 1;
        } else {
            ceil = a[mid];
            r = mid - 1;
        }
    }
    return {floor, ceil};
}
