vector<int> displayList(Node *head)
{
    vector<int> result;
    Node *current = head;

    while (current != NULL) {
        result.push_back(current->data);
        current = current->next;
    }

    return result;
}
