import torch
import torchvision
from torch.utils import data
from torchvision import transforms
from d2l import torch as d2l

d2l.use_svg_display()
trans = transforms.ToTensor()

# 读取数据集
minst_train = torchvision.datasets.FashionMNIST('./data', transform=trans)
minst_test = torchvision.datasets.FashionMNIST('./data', train=False, transform=trans)

print(len(minst_test), len(minst_train))

X, y = next(iter(data.DataLoader(minst_train, 18)))
d2l.show_images(X.reshape(18, 28, 28), 2, 9, d2l.get_fashion_mnist_labels(y))
