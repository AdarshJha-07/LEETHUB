class Solution {
    static bool cmp(const vector<int>&a,const vector<int>&b ){
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp); 
  priority_queue<int>pq;
        int sum=0,ans=0;
        for(int i=0;i<courses.size();i++){
             if(courses[i][0]>courses[i][1])continue;
        
        
           sum+=courses[i][0];pq.push(courses[i][0]);
                cout<<sum<<endl;
            if(sum<=courses[i][1]){
    
            }
            else if(pq.size()){
               sum-=pq.top();
                cout<<sum<<"gg"<<endl;
                pq.pop();
         
                
            }
         
        }
     return pq.size();
    }
};