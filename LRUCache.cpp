#include <unordered_map>
class LRUCache {
public:
    class node{
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key= _key;
            val= _val;
        }
    };
    node* head= new node(-1, -1);
    node* tail= new node(-1, -1);
    int cap;

    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }
    void addnode(node* newnode){
        node* temp= head->next;
        newnode->next= temp;
        newnode->prev= head;
        head->next= newnode;
        temp->prev= newnode;
    }

    void deletenode(node* delnode){
        node* delnext= delnode->next;
        node* delprev= delnode->prev;
        delprev->next= delnext;
        delnext->prev= delprev;
    }

    int get(int key) {
        if(m.count(key)>0){
            node* temp= m[key];
            int ans= temp->val;
            m.erase(key);
            deletenode(temp);
            addnode(temp);
            m[key]= head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)>0){
            node* existing= m[key];
            m.erase(key);
            deletenode(existing);
        }
        if(m.size() == cap){
            node* deletion= tail->prev;
            m.erase(deletion->key);
            deletenode(deletion);
        }
        addnode(new node(key, value));
        m[key]= head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */