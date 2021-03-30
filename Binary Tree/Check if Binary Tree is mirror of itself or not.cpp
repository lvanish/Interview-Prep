#include <bits/stdc++.h>
using namespace std;

bool isMirror(int v, vector<int> treeA[], vector<int> treeB[]){
    
    for(int i = 1; i<=v; i++){
        int sizeA = treeA[i].size();
        int sizeB = treeB[i].size();
        if(sizeA != sizeB)
            return false;
        reverse(treeA[i].begin(), treeA[i].end());
        if(treeA[i] != treeB[i])
            return false;
    }
    return true;
}

int main() {
	
	int t; cin>>t;
	while(t--){
	    int v, e; 
	    cin>>v>>e;
	    vector<int> treeA[v+1];
	    vector<int> treeB[v+1];
	    for(int i = 0 ; i<e; i++){
	        int x, y;
	        cin>>x>>y;
	        treeA[x].push_back(y);
	    }
	    for(int i = 0 ; i<e; i++){
	        int x, y;
	        cin>>x>>y;
	        treeB[x].push_back(y);
	    }
	    cout<<isMirror(v, treeA, treeB)<<endl;
	}
	
	return 0;
}
