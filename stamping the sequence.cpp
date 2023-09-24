struct Solution {
    
    int n, m, c = 0;
    char *a, *s;
    
    int find() {
        
        for (int i = 0, j; i+m <= n; ++i) {
            bool has = 0;
            for (j = 0; j < m; ++j) {
                if (a[i+j] == '?') continue;
                has = 1;
                if (a[i+j] != s[j]) {
                    break;
                }
            }
            if (j == m && has) {
                for (j = 0; j < m; ++j) {
                    if (a[i+j] != '?') {
                        a[i+j] = '?';
                        ++c;
                    }
                }
                return i;
            }
        }
        
        return -1;
    }
    
    vector<int> movesToStamp(string &stamp, string &target) {
        
        m = stamp.size();
        s = stamp.data();
         n = target.size();
        a = target.data();
        
        int i;
        vector<int> ans;
        
        while (c < n && (i = find()) != -1) {
            ans.push_back(i);
        }
        
        if (c >= n) {
            reverse(ans.begin(), ans.end());
        } else {
            ans.clear();
        }
        
        return ans;
    }
};
