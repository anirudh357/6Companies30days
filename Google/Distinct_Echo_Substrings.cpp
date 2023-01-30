class Solution {
public:
    int distinctEchoSubstrings(string text) {
	unordered_set<string_view> res;
	const char *p = text.c_str();
	for (int i=0; i<text.size(); ++i) {
		for (int len=1; i+len+len<=text.size(); ++len) {
			const string_view a(p+i    , len);
			const string_view b(p+i+len, len);
			if (a==b) {
				res.insert(a);
			}
		}
	}
	return res.size();
}
};