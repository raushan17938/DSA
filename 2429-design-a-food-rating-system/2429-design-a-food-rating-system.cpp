class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
          
           
            cuisineToFoodSet[cuisine].insert({-rating, food});
          
            foodInfo[food] = {rating, cuisine};
        }
    }
  
    void changeRating(string food, int newRating) {
        auto [oldRating, cuisine] = foodInfo[food];
      
        foodInfo[food] = {newRating, cuisine};
      
        cuisineToFoodSet[cuisine].erase({-oldRating, food});
      
        cuisineToFoodSet[cuisine].insert({-newRating, food});
    }
  
    string highestRated(string cuisine) {
     
        return cuisineToFoodSet[cuisine].begin()->second;
    }
  
private:
    
    unordered_map<string, set<pair<int, string>>> cuisineToFoodSet;
  
    unordered_map<string, pair<int, string>> foodInfo;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */