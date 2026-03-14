import re
import glob

components = {
    'lfoA', 'lfoB', 'lfoAenv',
    'vcoA', 'vcoB', 'vcoC', 'sub',
    'modMix', 'voiceMix',
    'dc', 'filterEnv', 'filterMix', 'filter', 'filterMode', 'env'
}

def repl(m):
    name = m.group(1)
    index = m.group(2)
    
    if name in components or (name.startswith('patch_') and 'Global' not in name):
        return f'voices[{index}].{name}'
    
    return m.group(0)

pattern = r'\b([a-zA-Z0-9_]+)\[([^\]]+)\]'

for file in glob.glob('*.ino'):
    with open(file, 'r') as f:
        content = f.read()
    
    new_content = re.sub(pattern, repl, content)
    
    if new_content != content:
        with open(file, 'w') as f:
            f.write(new_content)
