import os, glob, re

for filename in glob.glob("*.ino"):
    with open(filename, "r") as f:
        content = f.read()
        
    # We want to replace exactly `int voices;` with `int activeVoices;`
    content = content.replace("int voices;", "int activeVoices;")
    
    # In expressions like `voices++`, `voices--`, `voices <`, `voices =`, `voices >`
    content = re.sub(r'\bvoices\+\+', 'activeVoices++', content)
    content = re.sub(r'\bvoices--', 'activeVoices--', content)
    content = re.sub(r'\bvoices\s*<', 'activeVoices <', content)
    content = re.sub(r'\bvoices\s*>', 'activeVoices >', content)
    content = re.sub(r'\bvoices\s*=', 'activeVoices =', content)
    # Also `voices ==` if present
    content = re.sub(r'\bvoices\s*==', 'activeVoices ==', content)

    with open(filename, "w") as f:
        f.write(content)
