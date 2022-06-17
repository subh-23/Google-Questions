#include <bits/stdc++.h>
string maxRoomBooked(vector<string> arr, int n) {
    // Write your code here.
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == '-')
            continue;
        else
        {
            string demo = "";
            demo.push_back(arr[i][1]);
            demo.push_back(arr[i][2]);
            m[demo]++;
        }
    }
    multimap<int, string, greater<int>> ans;
    for (auto it : m)
        ans.insert(make_pair(it.second, it.first));
    for (auto it : ans)
        return it.second;
    return "";
}
