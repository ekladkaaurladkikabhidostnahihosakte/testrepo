class Solution {
public:
   int res;

void backtracking(vector<vector<int>> &vec, int pos, vector<int> &visited, int count) {
	if (pos == vec.size()) {
		res = max(res, count);
		return;
	}
	for (int i = 0; i < vec.size() ; i++) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		backtracking(vec, pos + 1, visited, count + vec[pos][i]);
		visited[i] = 0;
	}
}

int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
	res = 0;
	vector<vector<int>> sVec (students.size(), vector<int> (mentors.size(), 0));
	for (int i = 0; i < students.size(); i++) {
		for (int j = 0; j < mentors.size(); j++) {
			int score(0);    
			for (int n = 0; n < students[0].size(); n++) {
				if (students[i][n] == mentors[j][n])
					score++;
			}
			sVec[i][j] = score;
		}
	}
	vector<int> visited (mentors.size(), 0);
	backtracking(sVec, 0, visited, 0);
	return res;
}
};
