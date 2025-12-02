#include <bits/stdc++.h>
using namespace std;

void brute() {
    // Approach: Sort based on Euclidean distance (Simple Sorting Approach)
    // T.C = O(N log N)        S.C = O(N)
    
    int n, k;
    cout << "Enter number of points: ";
    cin >> n;
    
    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points (x y):\n";
    for(int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];

    cout << "Enter k: ";
    cin >> k;

    vector<pair<int, pair<int,int>>> vec;                         // (distance^2, (x, y)) store karenge
    for(int i = 0; i < n; i++) {
        int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);    // distance^2 nikalna
        vec.push_back({dist, {points[i][0], points[i][1]}});                     // pair me daalna
    }

    sort(vec.begin(), vec.end());                                 // distance ke basis pe sort karna

    cout << "\nK Closest Points to Origin (Brute):\n";
    for(int i = 0; i < k; i++) {
        cout << "[" << vec[i].second.first << ", " << vec[i].second.second << "] ";  // pehle k print karna
    }
    cout << endl;
}



void optimal() {
    // Approach: Use Max Heap to store only K closest points
    // T.C = O(N log K)        S.C = O(K)
    
    int n, k;
    cout << "Enter number of points: ";
    cin >> n;
    
    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points (x y):\n";
    for(int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];

    cout << "Enter k: ";
    cin >> k;

    priority_queue<pair<int, pair<int,int>>> maxHeap;             // (distance^2, (x, y)) — max-heap bana rahe hain

    for(int i = 0; i < n; i++) {
        int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);    // distance^2 calculate karna
        maxHeap.push({dist, {points[i][0], points[i][1]}});                      // heap me daalna

        if(maxHeap.size() > k) maxHeap.pop();                                    // agar heap size > k ho gaya to sabse bada nikaal do
    }

    cout << "\nK Closest Points to Origin (Optimal):\n";
    while(!maxHeap.empty()) {
        cout << "[" << maxHeap.top().second.first << ", " << maxHeap.top().second.second << "] ";
        maxHeap.pop();
    }
    cout << endl;
}



int main() {
    brute();         // Brute approach call karna
    optimal();       // Optimal approach call karna
    return 0;
}
