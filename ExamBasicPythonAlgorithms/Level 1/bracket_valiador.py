def bracket_validator(s: str) -> bool:
    stack = []
    matching = {')': '(', ']': '[', '}': '{'}
    for c in s:
        if c in '([{':
            stack.append(c)
        elif c in ')]}':
            if not stack or stack[-1] != matching[c]:
                return False
            stack.pop()
    return len(stack) == 0
