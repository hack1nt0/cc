
import random
import string

print(1)
n = int(5000)
print(''.join(random.choices(string.ascii_lowercase + '?', k=n)))

