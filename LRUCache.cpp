#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
//MY CODE - BEGIN
class LRUCache: public Cache{
    private:
        int size;
        void addNode(Node* node){
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next =node;
        }
        void removeNode(Node* node){
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        void moveToHead(Node* node){
            removeNode(node);
            addNode(node);
        }
    public:
    //Initialization of new cache
    LRUCache(int capacity){
        cp=capacity;
        size=0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    void set(int key, int value) override{
        if(mp.find(key) != mp.end()){
            // Key already exists in the cache
            Node* existingNode = mp[key];
            existingNode->value = value; // Update the value
            moveToHead(existingNode);
        }
        else{
            // Key is not present in the cache
            Node* newNode = new Node(key, value); // Create a new node
            mp[key] = newNode;                    // Add the key-node pair to the map
            if(size<cp){
                // Cache is not full, add the new node to the linked list and increment size
                size++;
                addNode(newNode);                
            }else {
                // Cache is full, need to evict the least recently used node
                Node* leastUsed = tail->prev;
                mp.erase(leastUsed->key); // Remove the corresponding key from the map
                removeNode(leastUsed);
                addNode(newNode);               
            }
        }
    }
    int get(int key) override{
       if(mp.find(key) != mp.end()){
           Node* node = mp[key];
           moveToHead(node);
           return node->value;
       }
       return -1; 
    }
};
//MY CODE - END
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
