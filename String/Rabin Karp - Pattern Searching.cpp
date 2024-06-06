bool search(string pat, string txt, int q) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
    int i, j; 
    int p = 0; // hash value for pattern 
    int t = 0; // hash value for txt 
    int h = 1; 

    // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 

    // Calculate the hash value of the pattern and the first window of txt 
    for (i = 0; i < M; i++) { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q; 
    } 

    // Slide the pattern over txt one by one 
    for (i = 0; i <= N - M; i++) { 

        // Check the hash values of current window of txt and pattern. 
        // If the hash values match then only check for characters one by one 
        if (p == t) { 
            /* Check for characters one by one */
            for (j = 0; j < M; j++) { 
                if (txt[i + j] != pat[j]) 
                    break; 
            } 

            // If p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (j == M) 
                return true; 
        } 

        // Calculate the hash value for the next window of txt: Remove 
        // leading digit, add trailing digit 
        if (i < N - M) { 
            t = (d * (t - txt[i] * h) + txt[i + M]) % q; 

            // We might get negative value of t, converting it to positive 
            if (t < 0) 
                t = (t + q); 
        } 
    } 
    return false; 
} 