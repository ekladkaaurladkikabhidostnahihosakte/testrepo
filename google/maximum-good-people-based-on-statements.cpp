class Solution {
public:
    bool validity(int number, int n, vector<vector<int>> &statements)
    {
        for (int i=0; i<n; i++)
        {
            if (number & (1<<(n-1-i))) // ith person is good
            {
                for (int j=0; j<n; j++){
                    bool j_asgn = (number & (1<<(n-1-j))) > 0; //assignment of j as per this number
                    if (statements[i][j]!=2 && statements[i][j]!=j_asgn) return false;
                }
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) 
    {
        int n=statements.size(), res=0;
        for (int i=0; i<(1<<n); i++)
            if(validity(i, n, statements)) res = max(res, __builtin_popcount(i));
        return res; 
    }
};
