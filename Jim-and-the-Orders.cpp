vector<int> jimOrders(vector<vector<int>> orders)
{
    vector<pair<int, int>> v;

    for (int i = 0; i < orders.size(); i++)
        v.push_back({orders[i][0] + orders[i][1], i + 1});

    sort(v.begin(), v.end());

    vector<int> ans;

    for (auto &p : v)
        ans.push_back(p.second);

    return ans;
}



vector<int> jimOrders2(vector<vector<int>> orders) {
    vector<pair<int,int>> v;

    for(int i = 0; i < orders.size(); i++) {
        int serve = orders[i][0] + orders[i][1];
        v.push_back({serve, i+1});
    }

    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    vector<int> ans;
    
    for(auto &p : v)
        ans.push_back(p.second);

    return ans;
}


vector<int> jimOrders3(vector<vector<int>> orders)
{
    std::vector<int> result;
    std::multimap<int, int> mp;
    int sum = 0;
    
    for (int i = 0; i < orders.size(); ++i)
    {
        sum = orders[i][0] + orders[i][1];
        mp.insert(make_pair(sum, i+1));
    }
    
    for (const auto& m : mp)
    {
        result.push_back(m.second);
    }

    return result;
}

