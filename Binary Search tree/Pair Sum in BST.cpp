bool findPair(Node* root, int X) {
    stack<Node*> s1, s2;
    Node* curr1 = root, *curr2 = root;
    bool done1 = false, done2 = false;
    int val1 = 0, val2 = 0;

    while (true) {
        while (!done1) {
            if (curr1 != NULL) {
                s1.push(curr1);
                curr1 = curr1->left;
            } else {
                if (s1.empty())
                    done1 = true;
                else {
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->data;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }
        while (!done2) {
            if (curr2 != NULL) {
                s2.push(curr2);
                curr2 = curr2->right;
            } else {
                if (s2.empty())
                    done2 = true;
                else {
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->data;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }

        if (val1 != val2 && val1 + val2 == X)
            return true;
        else if (val1 + val2 < X)
            done1 = false;
        else if (val1 + val2 > X)
            done2 = false;
            
        if (val1 >= val2)
            return false;
    }

    return false;
}