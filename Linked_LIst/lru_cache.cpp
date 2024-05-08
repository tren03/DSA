








// 146. LRU Cache
// Solved
// Medium
// Topics
// Companies
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

 

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
 

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.




class Node {
public:
    pair<int,int> val;
    Node* left;
    Node* right;
    
    Node(pair<int,int> v)
    {
        val.first = v.first;
        val.second = v.second;
        left = NULL;
        right = NULL;
        
    }
};



// we keep a unordered map with key as key and value as a pointer to the key,value given
// we construct a double linked list, with left mosst ele pointing to the least recent used and right most pointing to the most recently used
// when we access a ele, we remove it from ll and add it to the right most of the ll
// when we add ele, we add it to the right most and also add to unordered map. if the size of unordered map is greater that capacity, we find lru node which is pointed to by the left most node and we remove it;
// we right 2 helper functions to remove and insert right;
class LRUCache {
public:
    unordered_map<int,Node*>mp;
    int cap;
    Node* l;
    Node* r;
    LRUCache(int capacity) {
        cap = capacity;   
        l = new Node({0,0});
        r = new Node({0,0});    
        l->right = r;       
        r->left = l;
        
         
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            //before return, we need to update our linked list so that most recent is on most right;
            Node* temp = mp.find(key)->second;
            del(temp);
            insertRight(temp);
            return mp.find(key)->second->val.second;
        }
        return -1;
        
    }

    //insert node at right
    void insertRight(Node* t)
    {
        t->right = r;
        Node* temp = r->left;
        temp->right = t;
        t->left = temp;
        r->left = t;


    }
    //delete node
    void del(Node* t)
    {
        //since left and right will always exist as we have initialized before, we only code the case where we delete middle
        Node* le = t->left;
        Node* ri = t->right;
        le->right = ri;
        ri->left = le;

    }
    void put(int key, int value) {
        //if key already present, delete it, so we can add again
        if(mp.find(key)!=mp.end())
        {
            Node* temp = mp.find(key)->second;
            del(temp);

        }
        Node* n = new Node({key, value});

        mp[key] = n;        
        insertRight(n);

        if(mp.size()>cap)
        {
            //remove lru from linked list and remove that element from hashmap
            Node* lru = l->right;
            mp.erase(mp.find(lru->val.first));
            del(lru);           


        }

         
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */