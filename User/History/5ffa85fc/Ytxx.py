import torch
from torch.distributions import multinomial
from d2l import torch as d2l

fair_forb = torch.ones(6) / 6
print(fair_forb)