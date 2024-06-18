def makeDoubly(head):
    prev_node = None
    curr_node = head
    while curr_node is not None:
        next_node = curr_node.next
        curr_node.prev = prev_node
        prev_node = curr_node
        curr_node = next_node
