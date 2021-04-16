/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
bool solve(LLNode* node) {
    stack<int> s;
    LLNode* fast = node;
    LLNode* slow = node;
    while(fast -> next && fast -> next -> next){
        s.push(slow -> val);
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    if(fast -> next){
        s.push(slow -> val);
    }
    
    while(s.size() > 0 && slow -> next){
        slow = slow -> next;
        int k = s.top(); s.pop();
        if(k != slow -> val){
            return false;
        }
        
    }
    return true;
    
}