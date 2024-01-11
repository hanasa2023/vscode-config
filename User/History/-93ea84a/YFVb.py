import torch
import torchvision
from torch.utils import data
from torchvision import transforms
from d2l import torch as d2l

d2l.use_svg_display()
trans = transforms.ToTensor()

# 读取数据集
minst_train = torchvision.datasets.FashionMNIST('./data', transform=trans, download=True)
minst_test = torchvision.datasets.FashionMNIST('./data', train=False, transform=trans, download=True)

print(len(minst_test), len(minst_train))