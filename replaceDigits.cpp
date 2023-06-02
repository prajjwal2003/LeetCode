class Solution {
public:
    string w(string s) {
    for (auto i = 1; i < s.size(); i += 2)
        s[i] += s[i - 1] - '0';
    return s;
}
};