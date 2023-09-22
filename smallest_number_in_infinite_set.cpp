//You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

//Implement the SmallestInfiniteSet class:

//SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
//int popSmallest() Removes and returns the smallest integer contained in the infinite set.
//void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.

class SmallestInfiniteSet {
    map<int,int>m;
public:
    SmallestInfiniteSet() {
        //putting all numbers till 1001 so that even after after all the pop operation   map not become empty
        for(int i=1;i<1002;i++)
        {
            m[i]++;
        }
        
    }
    
    int popSmallest() {
        int value=m.begin()->first;
        m.erase(m.begin());
        return value;
    }
    
    void addBack(int num) {
        m[num]++;
        
    }
};
