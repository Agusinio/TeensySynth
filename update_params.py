import re

with open('g_params.ino', 'r') as f:
    content = f.read()

# For the pitch bend block
old_bend_block = r"(bend = 1 \+ \(\(float\)analogRead\(A0\) / 1023 / 4\.3\) \- 0\.12;)"
new_bend_block = r"bend = 1 + ((float)analogRead(A0) / 1023 / 4.3) - 0.12;\n  if (abs(bend - oldBend) > 0.005) {\n    parameterChanged = true;\n    oldBend = bend;\n  }"
content = re.sub(old_bend_block, new_bend_block, content)

# For every preset parameter block where there's a println
# We want to add parameterChanged = true; right before the Serial.println
content = re.sub(r'(Serial\.println\("[^"]+"\);)', r'parameterChanged = true;\n      \1', content)

with open('g_params.ino', 'w') as f:
    f.write(content)
