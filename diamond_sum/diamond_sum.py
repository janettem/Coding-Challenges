import math


def diamond_sum(grid_side: int) -> int:
    if grid_side == 1:
        return 1
    return math.ceil(grid_side ** 2) + 1 + math.ceil((grid_side ** 2) / 2) * 2\
        * (grid_side - 2)
