class Solution {
public:
   string getHint(string secret, string guess) {
	unordered_map<char, int> mp;
	int n = secret.size(), cA = 0, cB = 0;
	for (int i = 0; i < n; i++) {
		if (secret[i] == guess[i]) {
			cA++;
			continue;
		}
		mp[secret[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (secret[i] != guess[i] && mp[guess[i]] > 0) {
			mp[guess[i]]--;
			cB++;
		}
	}
	return to_string(cA) + 'A' + to_string(cB) + 'B';

    }
};
