vector<long long> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    
    vector<vector<int>> monsters;
    vector<vector<bool>> alive ;
    
    int mostersleft=0;
    
    for(int i=0;i<A.size();i++){
        vector<int> temp;
        vector<bool> temp2;
        for(int j=A[i][0];j<=A[i][1];j++){
            temp.push_back(j);
            //cout<<j<<" ";
            temp2.push_back(true);
        }
        //cout<<endl;
        monsters.push_back(temp);
        mostersleft+=temp.size();
        
        alive.push_back(temp2);
    }
    
    // for(int i=0;i<alive.size();i++){
    //     for(int j=0;j<alive[i].size();j++) cout<<alive[i][j];
    //     cout<<endl;
    // }
    
    //cout<<mostersleft<<endl;
    
    // int mostersleft= monsters.size()*monsters[0].size();
    
    // for(int i=0;i<B.size();i++){
        
    // }
    vector<long long> ans;
    for(long long i=0;i<B.size();i++){
        long long curhero=B[i][0];
        long long curstrength= B[i][1];
        
        //check for each moster
        for(int j=0;j<A.size();j++){
            //A[i][0]--A[i][1]
            
            if(curhero>=A[j][0] && curhero<=A[j][1] && curstrength>A[j][2] && alive[j][curhero-A[j][0]] == true){
                mostersleft--;
                 alive[j][curhero-A[j][0]] = 0;
                 //cout<<monsters[j][curhero-A[j][0]]<<endl;
            }
        }
        
        ans.push_back(mostersleft);
    }
    
    // for(int i=0;i<alive.size();i++){
    //     for(int j=0;j<alive[i].size();j++) cout<<alive[i][j];
    //     cout<<endl;
    // }
    
    return ans;
}