/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    queue<int>q;
public:

    void flatten(vector<NestedInteger> &nestedList)
    {
        int n=nestedList.size();
        for(int i=0;i<n;i++)
        {
            NestedInteger& obj=nestedList[i];
            if(obj.isInteger())
            q.push(obj.getInteger());
            else{
                flatten(obj.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        if(q.empty())
        return -1;
        int element=q.front();
        q.pop();
        return element;
    }
    
    bool hasNext() {
        if(q.empty())
        return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */