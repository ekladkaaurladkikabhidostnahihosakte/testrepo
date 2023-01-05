class Solution {
public:
    int numberOfSubstrings(string s) {
         int n=s.size();
        int res=0, i=0;
        int a=-1, b=-1, c=-1;
        while(i<n) {
            int curr=0;
            if(s[i]=='a')
                a=i;
            else if(s[i]=='b')
                b=i;
            else
                c=i;
            if(a>=0 && b>=0 && c>=0) 
                res+=min(a, min(b,c))+1;
            i++;
        }
     return res;
    }
};
