def echo_validator(text: str) -> bool:
    cleaned = ''.join(c.lower() for c in text if c.isalpha())
    return bool(cleaned) and cleaned == cleaned[::-1]
