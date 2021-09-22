class MedianFinder {
private:
    multiset<int> ms;
    multiset<int>::iterator msi;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {

        int size = ms.size();
        ms.insert(num);
        if (size == 0) {
            msi = ms.begin();
        } else if(num < *msi) {
            msi = (size & 1) ? std::prev(msi) : msi;
        } else {
            msi = (size & 1) ? msi : std::next(msi);
        }
    }

    double findMedian() {

        int size = ms.size();
        return (size & 1) ? *msi: (*msi + *(std::next(msi))) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
