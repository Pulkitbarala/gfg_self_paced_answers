void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; // Length of the previous longest prefix suffix

    lps[0] = 0; // lps[0] is always 0

    // Loop through the pattern
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to check if the pattern exists in the string or not
bool KMPSearch(string pat, string txt) 
{
    int M = pat.length();
    int N = txt.length();

    // Create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            // Pattern found
            return true;
        } else if (i < N && pat[j] != txt[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false; // Pattern not found
}
