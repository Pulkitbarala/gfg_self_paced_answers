ll Graph::getMaxsize()
{
    ll max_size = 1;
    stack<ll> Stack;

    bool *visited = new bool[V];
    for(ll i = 0; i < V; i++)
        visited[i] = false;

    for(ll i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    Graph gr = getTranspose();

    for(ll i = 0; i < V; i++)
        visited[i] = false;

    while (Stack.empty() == false)
    {
        ll v = Stack.top();
        Stack.pop();

        if (visited[v] == false)
        {
            curr_scc_size = 0;
            gr.DFSUtil(v, visited);
            max_size = max(max_size, curr_scc_size);
        }
    }

    return max_size;
}
