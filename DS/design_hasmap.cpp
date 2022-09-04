Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

// ------------------------solution
class MyHashMap {
public:
    /*
    We need to declare unordered_map.

For put function,
we need to just insert the key, values pair if the key is new in the map.
else if key is already present in the map, we need to find the iterator to the key and update its value.

For get function,
We need to return the value corresponding to the key.
so we find the iterator to that key, if present in the map, and return its value.
else just return -1 beacause key cannot be found.

For remove function
just use erase map stl function to remove the key and its value from map.
    */
  MyHashMap() { 
}

unordered_map<int, int>mp;
void put(int key, int value) {
      auto it = mp.find(key);
        if(it != mp.end()){
                it->second = value;
        }
    mp.insert({key, value});
}

int get(int key) {
    auto it= mp.find(key);
        if(it != mp.end()){
                return it->second;
        }
        return -1;
}

void remove(int key) {
    mp.erase(key);
}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */