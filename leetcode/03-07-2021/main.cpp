/* Design a HashMap without using any built-in hash table libraries. */

/* To be specific, your design should include these functions:
 *  - put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
 *  - get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
 *  - remove(key) : Remove the mapping for the value key if this map contains the mapping for the key. */

struct item {
    int key;
    int value;
    item* next;
    item(int aKey, int aValue) {
        key = aKey;
        value = aValue;
        next = nullptr;
    }
};

class MyHashMap {
public:
    std::array<item*, 9941> items;

    /** Initialize your data structure here. */
    MyHashMap() : items() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        cout << "put\n";
        int index = key % 9941;
        if(items[index]) {
            item* node = items[index];
            if(node->key == key) {
                node->value = value;
                return;
            }
            while(node->next) {
                if(node->key == key) {
                    node->value = value;
                    return;
                } else {
                    node = node->next;
                }
            }
            node->next = new item(key, value);
        } else {
            items[index] = new item(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        cout << "get\n";
        int index = key % 9941;
        item* node = items[index];
        while(node && node->key != key) {
            node = node->next;
        }
        if(node && node->key == key) {
            return node->value;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        cout << "remove\n";
        int index = key % 9941;
        item* node = items[index];
        while(node) {
            if(node->key == key) {
                item* temp = node->next;
                delete node;
                items[index] = temp;
                return;
            } else if(node->next) {
                if(node->next->key == key) {
                    item* temp_node = node->next->next;
                    delete node->next;
                    node->next = temp_node;
                    return;
                }
            }
            node = node->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */