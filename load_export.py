import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import sys

frame = int(sys.argv[1])

data = np.loadtxt("multi_data/export/frame{}.txt".format(frame), dtype=np.float32)
plt.imshow(data)
# plt.xlim([700,850])
# plt.ylim([1275,1440])
plt.show()
