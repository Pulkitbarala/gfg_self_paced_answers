void BFS(int origin)
    {
        queue<int> q;
        set<int> visited;
        q.push(origin);
        visited.insert(origin);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            
            for(int neighbor : adj[node])
            {
                if(visited.find(neighbor) == visited.end())
                {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }