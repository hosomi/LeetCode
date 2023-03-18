class BrowserHistory {
public:
    BrowserHistory(string homepage) {

        hist.push_back(homepage);
    }
    
    void visit(string url) {

        hist.resize(++cur);
        hist.push_back(url);
    }
    
    string back(int steps) {
        
        cur = std::max(0, cur - steps);
        return hist[cur];
    }
    
    string forward(int steps) {
        
        cur = std::min((int)hist.size() - 1, cur + steps);
        return hist[cur];
    }

private:
    int cur = 0;
    vector<string> hist;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
