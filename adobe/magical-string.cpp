class Solution {
public:
    static const long n = 1e5+1;
    short arr[n];
    Solution(){
        arr[0] = 1;
        arr[1] = 2;
        
        
        int i = 1, idx = 1;
        while(idx<n){
            
            if(arr[i]==1){
                arr[idx] = arr[idx-1]%2 + 1;
            }else{
                int val = arr[idx-1]%2 + 1;
                arr[idx++] = val;
                
                if(idx==n) break;
                arr[idx] = val;
            }
            idx++;
            i++;
            
        }
    }
    int magicalString(int n) {
        int count = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] == 1)
                count++;
        return count;
    }
};
