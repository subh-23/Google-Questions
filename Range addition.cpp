https://leetcode.com/discuss/interview-question/1771127/Google-or-Onsite-or-Increment-Intervals

Similar - https://leetcode.com/problems/range-addition/


			Brute force (Using Hashmap) T-> O(q*n), S-> O(n)

vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        //map initialization
       unordered_map<int,int>m;
       for(int i=0;i<length;i++){
           m[i]=0;
       }
       // interesting part
       for(int i=0;i<updates.size();i++){
           for(int j=updates[i][0];j<=updates[i][1];j++){
               m[j]+=updates[i][2];
               }
       }
       // dummy vector
       vector<int> v(length,0);
       for(int i=0;i<length;i++){
           v[i]=m[i];
       }
       return v;
    }
};

		Optimal (using prefix sum array) T-> O(N), S-> O(1)
			
vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
      vector<int> v(length+1,0);
    // making the query array
      for(int i=0;i<updates.size();i++){
          int start=updates[i][0];
          int end= updates[i][1];
          int inc=updates[i][2];
          v[start]+=inc;
          if(end+1<length)
            v[end+1]-=inc;
      }
      // prefix sum (first element would be zero)
      for(int i=1;i<v.size();i++){
          v[i]=v[i-1]+v[i];
      }
      v.pop_back();
      return v;
