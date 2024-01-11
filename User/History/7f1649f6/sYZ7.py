import torch

x = torch.zeros(5, 3)
print(x)
y = x[0, :]
print(y)
y += 1
print(x)
print(torch.nonzero(x))