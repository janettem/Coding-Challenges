def snakefill(screen_side: int) -> int:
    screen_area = screen_side * screen_side
    snake_length = 1
    snake_eats = 0
    while snake_length < screen_area:
        snake_length *= 2
        if snake_length <= screen_area:
            snake_eats += 1
    return snake_eats


def test():
    print(snakefill(3)) # => 3
    print(snakefill(6)) # => 5
    print(snakefill(24)) # => 9


def main():
    test()


if __name__ == "__main__":
    main()
