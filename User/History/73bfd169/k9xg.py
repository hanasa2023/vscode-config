import os

os.makedirs(os.path.join('..', 'data'), exist_ok=True)
data_file = os.path.join('..', 'data', 'house_tiny.csv')
with open(data_file, 'w') as f:
    f.write('NumRooms,Alley,Price\n')
    f.write('NA,Pave,127500\n')
    f.write('2,NA,178100\n')

import pandas as pd

data = pd.read_csv(data_file)
print(data)

inputs, outputs = data[:, 0:2], data[:, 2]
inputs = inputs.fillna(inputs.means())
print(inputs)