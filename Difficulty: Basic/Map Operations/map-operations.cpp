map<int, int> mapInsert(vector<int>& arr) {
    map<int, int> mp;
   
    for (int i = 0; i < arr.size(); ++i) {
        mp[arr[i]] = i; 
    }
    return mp;
}

void mapDisplay(map<int, int>& mp) {
  
    for (auto& pair : mp) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void mapErase(map<int, int>& mp, int x) {
 
    if (mp.erase(x)) {
        cout << "erased " << x << endl;
    } else {
      
        cout << "not found" << endl;
    }
}