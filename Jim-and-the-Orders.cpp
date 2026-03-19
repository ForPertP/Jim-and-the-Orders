#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'jimOrders' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY orders as parameter.
 */

vector<int> jimOrders(vector<vector<int>> orders)
{
    vector<pair<int, int>> v;

    for (int i = 0; i < orders.size(); i++)
        v.push_back({orders[i][0] + orders[i][1], i + 1});

    sort(v.begin(), v.end());

    vector<int> ans;

    for (const auto &p : v)
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
    
    for(const auto &p : v)
        ans.push_back(p.second);

    return ans;
}


std::vector<int> jimOrders3(vector<vector<int>> orders)
{
    multimap<int, int> mp;

    for (size_t i = 0; i < orders.size(); ++i)
    {
        int totalTime = orders[i][0] + orders[i][1];
        mp.emplace(totalTime, i + 1);
    }

    vector<int> ans;

    for (const auto& [time, index] : mp)
    {
        ans.push_back(index);
    }

    return ans;
}


vector<int> jimOrders4(vector<vector<int>> orders)
{
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    for(int i = 0; i < orders.size(); i++)
        pq.push({orders[i][0] + orders[i][1], i + 1});

    vector<int> ans;

    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> orders(n);

    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        string orders_row_temp_temp;
        getline(cin, orders_row_temp_temp);

        vector<string> orders_row_temp = split(rtrim(orders_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int orders_row_item = stoi(orders_row_temp[j]);

            orders[i][j] = orders_row_item;
        }
    }

    vector<int> result = jimOrders(orders);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

std::vector<string> split(const string &str)
{
    vector<string> tokens;
    string_view str_view(str);
    size_t start = 0;
    size_t end = 0;

    while ((end = str_view.find(' ', start)) != string_view::npos)
    {
        if (end > start)
        {
            tokens.emplace_back(str_view.substr(start, end - start));
        }
        start = end + 1;
    }

    if (start < str_view.size())
    {
        tokens.emplace_back(str_view.substr(start));
    }

    return tokens;
}
