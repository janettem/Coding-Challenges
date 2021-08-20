def are_adjacent_nodes(adjacency_matrix: list, node1: int, node2: int) -> bool:
    if adjacency_matrix[node1][node2] == 1:
        return True
    return False


def test():
    adjacency_matrix1 = [
        [0, 1, 0, 0],
        [1, 0, 1, 1],
        [0, 1, 0, 1],
        [0, 1, 1, 0]
    ]

    adjacency_matrix2 = [
        [0, 1, 0, 1, 1],
        [1, 0, 1, 0, 0],
        [0, 1, 0, 1, 0],
        [1, 0, 1, 0, 1],
        [1, 0, 0, 1, 0]
    ]

    print(are_adjacent_nodes(adjacency_matrix1, 0, 1)) # => True
    print(are_adjacent_nodes(adjacency_matrix1, 0, 2)) # => False
    print(are_adjacent_nodes(adjacency_matrix2, 0, 3)) # => True
    print(are_adjacent_nodes(adjacency_matrix2, 1, 4)) # => False
    print(are_adjacent_nodes(adjacency_matrix1, 2, 3)) # => True
    print(are_adjacent_nodes(adjacency_matrix2, 0, 2)) # => False


def main():
    test()


if __name__ == "__main__":
    main()
