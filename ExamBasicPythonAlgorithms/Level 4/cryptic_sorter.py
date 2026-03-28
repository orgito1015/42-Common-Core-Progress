def count_vowels(s: str) -> int:
    """Count the number of vowels in a string (case-insensitive)."""
    vowels = "aeiouAEIOU"
    return sum(1 for char in s if char in vowels)


def cryptic_sorter(strings: list[str]) -> list[str]:
    """
    Sort strings by multiple criteria:
    1. By length (shortest first)
    2. Alphabetically (case-insensitive)
    3. By number of vowels (ascending)

    Args:
        strings: List of strings to sort

    Returns:
        Sorted list of strings according to the criteria
    """
    if not strings:
        return []

    return sorted(strings, key=lambda x: (len(x), x.lower(), count_vowels(x)))
