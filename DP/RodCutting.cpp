#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while(t--){
        
        int n; cin>>n;
        
        int len[n], pro[n];
        
        for(int i = 0; i<n; i++){
            cin>>pro[i];
        }
        for(int i = 0; i<n; i++){
            int no = i+1;
            len[i] = no;
        }
        int dp[n+1][n+1];
        for(int i = 0; i<=n; i++){
            dp[0][i] = 0;
        }
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<= n; j++){
                if(len[i-1] <= j){
                    dp[i][j] = max(pro[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        cout<<dp[n][n]<<endl;
        
    }
    
    
	return 0;
}
