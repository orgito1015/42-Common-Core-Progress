def whisper_cipher(text: str, shift: int) -> str:
    result = ""
    for char in text:
        if char.isalpha():
            if char.islower():
                # Shift lowercase letters within a-z range
                result += chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
            else:
                # Shift uppercase letters within A-Z range
                result += chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
        else:
            # Keep non-alphabetic characters unchanged
            result += char
    return result
