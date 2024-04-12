// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (mSmallerList.empty() || num <= mSmallerList.top() ) {
            mSmallerList.push(num);
        }
        else {
            mLargerList.push(num);
        }

        // balance the heaps
        // (both heaps have either equal numbers or smallerList will have one more element)
        if (mLargerList.size() > mSmallerList.size()) {
            mSmallerList.push(mLargerList.top());
            mLargerList.pop();
        }
        else if (mSmallerList.size() - mLargerList.size() > 1)
        {
            mLargerList.push(mSmallerList.top());
            mSmallerList.pop();
        }
    }
    
    double findMedian() {
        double median;
        if (mSmallerList.size() > mLargerList.size())
            median = mSmallerList.top();
        else
            median = (mSmallerList.top() + mLargerList.top()) / 2.0;

        return median;
    }

private:
    priority_queue<int, vector<int>> mSmallerList ; // a max. heap
    priority_queue<int, vector<int>, greater<int>> mLargerList; // a min. heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
