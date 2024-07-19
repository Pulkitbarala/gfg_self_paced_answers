class Solution
{
    public:
    void findAllWords(vector<string> dict, string pattern) 
    {
	    map<string,string> key;
	    map<string, vector<string> > map;
	    for (int i = 0; i < dict.size(); i++) {

		    string str = "";
	    	int l = dict[i].length();
		    for (int j = 0; j < l; j++) {
	    		if (dict[i][j] >= 'A' && dict[i][j] <= 'Z') {
		    		str += dict[i][j];
			    	map[str].push_back(dict[i]);
				    key[dict[i]] = str;
    			}
	    	}
    	}

	    bool wordFound = false;
	    vector<pair<string, string>> res;
    	for (auto& it : map) {
	    	if (it.first == pattern) {
		    	wordFound = true;
			    for (auto& itt : it.second) {
				    res.push_back({key[itt],itt});
    			}
	    	}
	    }
	
    	sort(res.begin(),res.end());
	    for (auto str : res){
	        cout << str.second<< " ";
	    }
	    if (!wordFound) {
		    cout << "No match found";
	    }
    }
};
 