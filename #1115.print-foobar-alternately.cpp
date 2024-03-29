class FooBar {
private:
    int n;
    mutex m1;
    mutex m2;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            m2.lock();
        	printFoo();
            m1.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
        	m1.lock();
            printBar();
            m2.unlock();
        }
    }
};
