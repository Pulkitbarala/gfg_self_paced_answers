void findAll() {
    for (int i = 1; i <= 1000000; i++) {
        int num = i;
        bool satisfied = true;
        while (num > 0) {
            int digit = num % 10;
            if (digit != 1 && digit != 2 && digit != 3) {
                satisfied = false;
                break;
            }
            num /= 10;
        }
        if (satisfied) {
            mp[i] = 1;
        }
    }
}