class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);
        for (auto q : shifts) {
            int l = q[0];
            int r = q[1];
            int dir = q[2];
            int x;
            if (dir == 0)
                x = -1;
            else
                x = 1;
            diff[l] += x;
            if (r + 1 < n)
                diff[r + 1] -= x;
        }
        for (int i = 1; i < n; i++)
            diff[i] += diff[i - 1];
        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26;
            if (shift < 0)
                shift += 26;
            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }
        return s;
    }
};
