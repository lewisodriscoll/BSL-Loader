from load_bsl import BSLLoader

# data = load_otoko_data("C:/Corfunc141/examples/B00000.QAX", "C:/Corfunc141/examples/B00000.APS")

loader = BSLLoader("X29000.QAX", "X29000.L1P")

data = loader.load_bsl_data()

import matplotlib.pyplot as plt

plt.plot(data.q_axis.data[0], data.data_axis.data[0])
plt.show()
