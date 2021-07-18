Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Note: use of list(STL in C++ for doubly linked list allows insertion(push_back,push_front) and deletion(pop_back,pop_front) in O(1), more gfg)
One map(values) for storing key-value pairs , another map for storing addresses of pointers of list(lru), and list(stl 
for doubly linked list) for storing pointers of key.
In LRU cache, we have to remove the least recent key.
**: The least recent key is present in front of the list and most recent key is being pushed back so its present
at the last of the list(lru).
In put function, just check if key is already present then just update the value and make this key as most recent by deleting its 
current positon in the lru and then pushing back in lru(tp make most recent used key). If not present and capacity is less
then, insert in values, push back in key, update the address of new key in position map. Else, we need to remove the least recent
used key and do the insertion.

In get function, if key is not pesent return -1 else make sure to make it most recent by deleting its current positon9take 
address from postion) int the list and pushing back in the list.
class LRUCache {
public:
    unordered_map<int,int> values;
    unordered_map<int,list<int>::iterator> position;
    list<int> lru;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(values.find(key)==values.end()) return -1;
        auto itr=position[key];
        lru.erase(itr);
        lru.push_back(key);
        position[key]=--lru.end();            
        
        return values[key];
    }
    
    void put(int key, int value) {
        if(values.find(key)!=values.end()){
            values[key]=value;
            auto itr=position[key];
            lru.erase(itr);
            lru.push_back(key);
            position[key]=--lru.end();
            return ;
        }
        //insert into values, update the position of key, push in lru
        if(values.size()<n){
            values[key]=value;
            lru.push_back(key);
            position[key]=--lru.end();
        }
        // need to remove least recent //present at front of list(lru)
        else{
            auto itr=lru.begin();
            values.erase(*itr);
            position.erase(*itr);
            lru.erase(lru.begin());
            values[key]=value;
            lru.push_back(key);
            position[key]=--lru.end();
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */