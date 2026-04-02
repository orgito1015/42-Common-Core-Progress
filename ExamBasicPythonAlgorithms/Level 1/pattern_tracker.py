def pattern_tracker(text: str) -> int:
    count = 0

    for i in range(len(text) - 1):
        if text[i].isdigit() and text[i+1].isdigit():
            if int(text[i+1]) == int(text[i]) + 1:
                count += 1   
    return count


print(pattern_tracker("01234567"))      # 7
print(pattern_tracker("1234567890"))    # 8  
print(pattern_tracker("987654321"))  # 0
print(pattern_tracker("12a34"))  # 2
