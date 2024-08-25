class Solution {
public:
   
long long cnt=0;
void merge(vector<int>&arr, int s, int m, int e){
      vector<long long>a(e-s+1);
      int l =s;
      int r = m+1;
      int k =0;
      while(l<=m && r<=e){
          if(arr[l]<arr[r]){
              a[k++] = arr[l++];

          }
          else{
              a[k++] = arr[r++];  
          }
      }
      while(l<=m){
          a[k++]=arr[l++];
      }
      while(r<=e){
          a[k++]=arr[r++];
      }
     for(int k=0;k<a.size();k++){
         arr[s+k]= a[k];
     } 
}
void countPair(vector<int>&arr, int s,int m, int e){
     int j = m+1;
    for(int i=s; i<=m;i++){
        while(j<=e && arr[i]>2LL*arr[j]){
            j++;
        }
        cnt+=(j-(m+1));
    }
    
}  
    

void mergeSort(vector<int>&arr, int s, int e){
    if(s<e){
        int m = s + (e-s)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        countPair(arr, s, m, e);
        merge(arr, s, m, e);
    }
}
  
    int reversePairs(vector<int>& nums){
      int s = 0;
        int n = nums.size();
      int e = n-1;
      mergeSort(nums, s, e);
      return cnt;
    }

};