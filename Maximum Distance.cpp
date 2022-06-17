int len(string a, string b){
    int last = min(a.length(),b.length());
    int ans=0;
    for(int i=0;i<last;i++){
        if(a[i]==b[i]){ans++;}
    	else break;
    }
    int first = a.length(),sec=b.length();
    return first+sec-(2*ans);
}
int maximumDistance(vector<string> &v)
{   
  int n = v.size();
    int ans= 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j) continue;
            ans=max(len(v[i],v[j]), ans);
        }
    }
    return ans;
}
