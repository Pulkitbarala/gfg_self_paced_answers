int avgOfString(string s) {
    int ascii_sum = 0;
    int length = s.length();
    
    for (char c : s) {
        ascii_sum += int(c);
    }
    
    double avg = double(ascii_sum) / length;
    return floor(avg);
}
