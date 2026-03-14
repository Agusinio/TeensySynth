import re

with open('TeensySynth.ino', 'r') as f:
    content = f.read()

# Replace const int16_t wave[number][size] = {
# with const int16_t wave[number][size] PROGMEM = {
content = re.sub(r'(const\s+int16_t\s+wave\d+\[\d+\])\s*=\s*\{', r'\1 PROGMEM = {', content)

with open('TeensySynth.ino', 'w') as f:
    f.write(content)
