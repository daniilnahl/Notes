import torch

def main():
    print("PyTorch version:", torch.__version__)
    x = torch.rand(5, 3)
    print(x)

if __name__ == "__main__":
    main()