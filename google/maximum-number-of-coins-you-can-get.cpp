class Solution {
public:
   int maxCoins(vector<int>& piles) {
	sort(piles.begin(), piles.end());
    int ans = 0, start = 0, end = piles.size() - 1;
    while(start < end) {
        ans += piles[end - 1];
        start++;
        end -= 2;
    }
    return ans;
}
};
