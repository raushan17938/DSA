class MovieRentingSystem {
private:
   
    unordered_map<int, set<pair<int, int>>> unrented;
  
    
    map<pair<int, int>, int> shopAndMovieToPrice;
  
   
    set<tuple<int, int, int>> rented;

public:
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
       
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
          
          
            unrented[movie].insert({price, shop});
          
    
            shopAndMovieToPrice[{shop, movie}] = price;
        }
    }
  
   
    vector<int> search(int movie) {
        vector<int> result;
      
    
        if (unrented.find(movie) != unrented.end()) {
        
            int count = 0;
            for (const auto& [price, shop] : unrented[movie]) {
                if (count >= 5) break;
                result.push_back(shop);
                count++;
            }
        }
      
        return result;
    }
  
   
    void rent(int shop, int movie) {
    
        int price = shopAndMovieToPrice[{shop, movie}];
      

        unrented[movie].erase({price, shop});
      
      
        rented.insert({price, shop, movie});
    }
  
   
    void drop(int shop, int movie) {
    
        int price = shopAndMovieToPrice[{shop, movie}];
      

        unrented[movie].insert({price, shop});
      
  
        rented.erase({price, shop, movie});
    }
  
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
      

        int count = 0;
        for (const auto& [price, shop, movie] : rented) {
            if (count >= 5) break;
            result.push_back({shop, movie});
            count++;
        }
      
        return result;
    }
};