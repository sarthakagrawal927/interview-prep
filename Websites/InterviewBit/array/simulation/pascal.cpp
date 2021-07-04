vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> sol(A);
                int sum =0;

    for(int i = 0; i< A; i++){
        if(i == 0){
            sol[i].push_back(1);
        }
        else if(i==1){
            sol[i].push_back(1);
            sol[i].push_back(1);
        }
        else{
            sol[i].push_back(1);
            for(int j = 1; j < i; j++){
                sum = sol[i-1][j-1] + sol[i-1][j];
                sol[i].push_back(sum);
                sum=0;
        }
        sol[i].push_back(1);
        }   
    }
    return sol;
}
