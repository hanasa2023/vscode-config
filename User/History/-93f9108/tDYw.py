import torch
from torch import nn
from d2l import torch as d2l

#生成数据集
true_w = torch.tensor([1, -3.2])
true_b = 4.2
features, labels = d2l.synthetic_data(true_w, true_b, 1000)

#读取数据集
data_iter = d2l.load_array

