Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int l=A.size(),m=B.size(),n=C.size();
    int ans=INT_MAX;
    A.push_back(INT_MAX);
    B.push_back(INT_MAX);
    C.push_back(INT_MAX);
    int i=0,j=0,k=0;
    while(i<l && j<m && k<n){
        int mx=max(A[i],max(B[j],C[k]));
        int mn=min(A[i],min(B[j],C[k]));
        ans=min(ans,abs(mx-mn));
        
        if(min(A[i+1],min(B[j+1],C[k+1]))==A[i+1]){
            i++;
        }
        else if(min(A[i+1],min(B[j+1],C[k+1]))==B[j+1]){
            j++;
        }
        else if(min(A[i+1],min(B[j+1],C[k+1]))==C[k+1]){
            k++;
        }
    }
    return ans;
}
