class ZeroEvenOdd {

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->next = -1;
        this->i = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {

        while(this->i <= this->n) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this]() {
                return this->next == -1;
            });

            if (this-> i <= this->n) {
                printNumber(0);
            }

            this->next = i%2;
            lck.unlock();
            cv.notify_all();
        }
        return;
    }

    void even(function<void(int)> printNumber) {

        while (this->i <= this->n) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this](){return this->next == 0;});
            if (this-> i <= this->n) {
                printNumber(i);
            }

            this->i += 1;
            this->next = -1;
            lck.unlock();
            cv.notify_all();
        }
        return;
    }

    void odd(function<void(int)> printNumber) {

        while (this->i <= this->n) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this]() {
                return this->next == 1;
            });

            if (this-> i <= this->n) {
                printNumber(i);
            }

            this->i += 1;
            this->next = -1;
            lck.unlock();
            cv.notify_all();
        }
        return;
    }

private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    int next;
    int i;
};
