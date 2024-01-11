import torch

x = torch.zeros(5, 3)
print(x)
y = x[0, :]
print(y)
y += 1
print(x)
print(torch.nonzero(x))

z = torch.ones(2, 3, 4)
print(z)
print(len(z))
print(torch.sum(z, dim=1))