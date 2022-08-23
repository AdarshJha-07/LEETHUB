class MedianFinder {
    priority_queue<int>pq1;         //left side;
    
    priority_queue<int ,vector<int>, greater<int>>pq2 ; //right side
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty()||pq1.top()>=num){
            pq1.push(num);
           
        }
        else if( pq1.top()<num )pq2.push(num);
        
        if(pq1.size()>=2+pq2.size())
        {
            pq2.push(pq1.top());
            pq1.pop();
        }   
        
        if(pq1.size()<pq2.size()){
            
            pq1.push(pq2.top());
            pq2.pop();
        }
        
    }
    
    double findMedian() {
        
        if( pq1.size() == pq2.size())return (pq1.top()+pq2.top())/2.0;
        
        return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */