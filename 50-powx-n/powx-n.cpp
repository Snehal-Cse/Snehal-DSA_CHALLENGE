class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
     long long nCopy = n;
        if(nCopy<0){
            nCopy*=-1;
        }
        while(nCopy>0){
            if(nCopy%2){
               ans = ans*x;
                nCopy = nCopy-1;   
            }
            else{
                x = x*x;
                nCopy/=2; 
            }   
        }
        if(n<0){
            ans = double(1.0)/double(ans);
        }
        return ans;
        
    }
};


