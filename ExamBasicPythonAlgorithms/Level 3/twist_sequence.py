def twist_sequence(arr: list[int], k: int) -> list[int]:
    if not arr:
        return arr
    n = len(arr)
    k = k % n
    return arr[-k:] + arr[:-k]
