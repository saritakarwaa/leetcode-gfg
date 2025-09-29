class FreqStack {
public:
    unordered_map<int,int>freq;
    int pos=0;
    priority_queue<pair<int,pair<int,int>>>maxH;
    FreqStack() {
        
    }
    
    void push(int val) {
        maxH.push({freq[val]++, {pos++, val}});
    }
    
    int pop() {
        auto val=maxH.top();
        maxH.pop();
        int x=val.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */