#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPairs(vector<int>& skillLevel, int minDiff) {
    sort(skillLevel.begin(), skillLevel.end());
    int n = skillLevel.size();
    int i = 0;
    vector<int> x;
    
    for (int j = 0; j < n / 2; ++j) {
        while (i < n && skillLevel[i] - skillLevel[j] < minDiff) {
            ++i;
        }
        if (i >= n) {
            break;
        }
        x.push_back(i);
    }
    x.resize(n / 2);
    
    int ans = 0;
    int k = n - 1;
    
    for (int y : x) {
        if (y <= k) {
            ++ans;
            --k;
        }
    }
    
    return ans;
}

int main() {
    int skillLevel_count;
    cin >> skillLevel_count;

    vector<int> skillLevel(skillLevel_count);

    for (int i = 0; i < skillLevel_count; ++i) {
        cin >> skillLevel[i];
    }

    int minDiff;
    cin >> minDiff;

    int result = maxPairs(skillLevel, minDiff);

    cout << result << endl;

    return 0;
}

