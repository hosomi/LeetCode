class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        int size = foods.size();
        for(int i = 0; i < size; i++) {
            mc[cuisines[i]][ratings[i]].insert(foods[i]);
            md[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {

        if (md.find(food) == md.end()) {
            return;
        }

        auto f = md[food];
        int rate = f.first;
        string cuise = f.second;
        mc[cuise][rate].erase(food);
        mc[cuise][newRating].insert(food);
        if (mc[cuise][rate].size() == 0) {
            mc[cuise].erase(rate);
        }
        
        md[food].first = newRating;
    }
    
    string highestRated(string cuisine) {

        if (mc.find(cuisine) == mc.end()) {
            return "";
        }

        auto i = mc[cuisine].rbegin();
        auto st = i->second;
        return *st.begin();
    }

private:
    map<string, map<int,set<string>>> mc;
    map<string, pair<int,string>> md;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
