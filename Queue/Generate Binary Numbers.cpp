vector<string> generate(int N) {
    vector<string> result;
    queue<string> q;
    q.push("1");
    
    for (int i = 1; i <= N; ++i) {
        string current = q.front();
        q.pop();
        result.push_back(current);
        q.push(current + "0");
        q.push(current + "1");
    }
    
    return result;
}
