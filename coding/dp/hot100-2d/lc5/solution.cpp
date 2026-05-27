class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() < 2) return s;
		int start = 0, maxlength = 1;
		for (int i = 0; i < s.length(); i++) {
			expandAroundCenter(s, i, i, start, maxlength);
			expandAroundCenter(s, i, i + 1, start, maxlength);

		}
		return s.substr(start, maxlength);
	}
private:
	void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			int currentlength = right - left + 1;
			if (currentlength > maxlength) {
				maxlength = currentlength;
				start = left;
			}
			left--;
			right++;
		}
	}
};