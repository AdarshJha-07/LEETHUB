class LRUCache {
    
    int cap;
   
    
    class Node{
      public:
        int k ,v;
        Node * next ,* prev;
        Node(int k,int v){
            this->k = k;
            this->v = v;
            next = NULL;
            prev = NULL;
        }
        Node(){
            k = 0;
            v = 0;
            next = NULL;
            prev = NULL;
        }
        
    };
     unordered_map<int , Node*> ump;
    Node * head ,*tail;
        
    void init(){
            head = new Node(0,0);
            tail = new Node(0,0);
        
        head->next = tail;
        tail ->prev = head;
    }
    void insert(Node *n){
        
        n->next = head->next;
        n->prev = head;
        
        head->next = n;
        n->next->prev = n;
        
    }
    
    void update(Node * n){
        n->prev->next = n->next;
        
        n->next->prev = n->prev;
        
        insert(n);
        
    }
    void remove(){
       Node* temp = tail->prev->prev;
        
        temp->next = tail;
        
        
        
        tail -> prev = temp;
        
       
    }
public:
    LRUCache(int capacity) {
        init();
        
        this->cap = capacity;
        
    }
    
    int get(int key) {
        
        if(ump.find(key)==ump.end()){
            return -1;
        }
        
        Node * temp = ump[key];
        int ans = temp->v;
        
        update(temp);
        ump[key] = head->next;
        return ans;
    }
    
    void put(int key, int value) {
        
        Node *n;
        if( ump.find(key) != ump.end()){
            
            n = ump[key];
            n->v = value;
            update(n);
        }
        else{
            Node* temp = new Node( key , value);
          if(ump.size() == cap){
             
              ump.erase(tail->prev->k); 
                  
              remove();
          }  
            insert(temp);
            n =  temp;
        }
        ump[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */