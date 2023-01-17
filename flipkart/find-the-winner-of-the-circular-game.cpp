class Solution {
public:
    void josephus(vector<int> &v, int start, int k){
        if(v.size()==1){             //Return last standing person
            return;
        }
        start+=k;                    //Position of person form start which is to be eliminated
        int s = v.size();
        start%=s;                    //Taking remainder so that index does not go above the size of array
        v.erase(v.begin()+start);      //Eliminating the person
        josephus(v,start,k);             //Recusive call
        return;
    }
    
    
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        k--;
        for(int i=1; i<=n; i++){
            v[i-1]=i;
        }
        josephus(v,0,k);
        return v[0];
    }
};
