import pytest
from diamond_sum import diamond_sum


def test_diamond_sum():
    assert diamond_sum(1) == 1
    assert diamond_sum(3) == 20
    assert diamond_sum(5) == 104
