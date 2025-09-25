class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        // vector<vector<int>>transpose(n,vector<int>(n));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         transpose[j][i]=grid[i][j];
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         bool match=true;
        //         for(int k=0;k<n;k++){
        //             if(grid[i][k]!=transpose[j][k]){
        //                 match=false;
        //                 break;
        //             }
        //         }
        //         if(match) count++;
        //     }
        // }
        // return count;
        map<vector<int>,int>mp; //row,count
        for(int i=0;i<n;i++){
            mp[grid[i]]++;
        }
        for(int j=0;j<n;j++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                temp.push_back(grid[i][j]);
            }
            count+=mp[temp];
        }
        return count;
    }
};