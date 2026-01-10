import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import torchvision
import torchvision.transforms as transforms


#needed to displayt images
import matplotlib.pyplot as plt
import numpy as np


class Net(nn.Module):
    def __init__(self):
        super().__init__() ###NOTE EACH CONVULTION LAYER SHRINKS THE HEIGHT AND WIDTH ACCORDING TO THIS FORMULA -> W out = W in - Kernel size + 1
        #input takes in 32 pixels x 32 pixels x 3 layers of colors
        self.conv1 = nn.Conv2d(3, 6, 5) 
        #outputs 28 pixels x 28 pixels x 6 layers
        self.pool = nn.MaxPool2d(2, 2) #basically slides a 2x2 window across the features map keeping only the maximum value from each 2x2 area. This reduces the size of the feature map in half, reducing the number of parameters the model needs to learn
        #compresses by 2: 14 X 14 X 6
        self.conv2 = nn.Conv2d(6, 16, 5) 
        #outputs 10 X 10 X 6 = 600 then compresses (call within forward) to 16 * 5 * 5 
        self.fc1 = nn.Linear(16 * 5 * 5, 120) #16 * 5 * 5 represents the total volume after the convultion, now we need to flatten it and feed into 1D linear convolution
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)
    
    def forward(self, input):
        x = self.pool(F.relu(self.conv1(input)))
        x = self.pool(F.relu(self.conv2(x)))

        x = torch.flatten(x, 1) # flatten all dimensions except batch

        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        output = self.fc3(x)

        return output    
    



def imshow(img):
    img = img / 2 + 0.5     # unnormalize
    npimg = img.numpy()
    plt.imshow(np.transpose(npimg, (1, 2, 0)))
    plt.show()


def main():
    net = Net() 

    transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.5,0.5,0.5), (0.5,0.5,0.5))])
    batch_size = 4

    train_set = torchvision.datasets.CIFAR10(root='./data', train=True, download=True, transform=transform) #inited a training set of data
    trainloader = torch.utils.data.DataLoader(train_set, batch_size=batch_size, shuffle=True, num_workers=2) #inited an iterable thats based of the training data set

    testset = torchvision.datasets.CIFAR10(root='./data', train=False, download=True, transform=transform) #inited a test set of data
    testloader = torch.utils.data.DataLoader(testset, batch_size=batch_size, shuffle=False, num_workers=2) #inited an iterable thats based of the test data set

    classes = ('plane', 'car', 'bird', 'cat','deer', 'dog', 'frog', 'horse', 'ship', 'truck')

    #display images
    # # get some random training images
    dataiter = iter(trainloader)
    images, labels = next(dataiter)

    # show images
    imshow(torchvision.utils.make_grid(images))
    # print labels
    print(' '.join(f'{classes[labels[j]]:5s}' for j in range(batch_size)))

    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(net.parameters(), lr=0.001, momentum=0.9)


    for epoch in range(2):
        running_loss = 0.0
        for i, data in enumerate(trainloader, 0):
            #get hte inputs: data is a list of [inputs, labels]
            inputs, labels = data

            # zero the parameter gradients
            optimizer.zero_grad() 

            # forward + backward + optimize
            outputs = net(inputs)
            loss = criterion(outputs,labels)
            loss.backward()
            optimizer.step()

            #prints statistics
            running_loss += loss.item()
            if i % 2000 == 1999:    # print every 2000 mini-batches
                print(f'[{epoch + 1}, {i + 1:5d}] loss: {running_loss / 2000:.3f}')
                running_loss = 0.0

    print('Finished Training')

    #save the model
    PATH = './cifar_net.pth'
    torch.save(net.state_dict(), PATH)


    #test the model on test data
    dataiter = iter(testloader)
    images, labels = next(dataiter)

    #print images
    imshow(torchvision.utils.make_grid(images))
    print('GroundTruth: ', ' '.join(f'{classes[labels[j]]:5s}' for j in range(4)))

    #load back the saved model
    net = Net()
    net.load_state_dict(torch.load(PATH, weights_only=True))

    #test the model on test images
    outputs = net(images)
    _, predicted = torch.max(outputs, 1)
    print('Predicted: ', ' '.join(f'{classes[predicted[j]]:5s}' for j in range(4)))

    #test the NN on the whole data set
    correct = 0
    total = 0
    #because we are not training we don't need to calcualte the gradients for our outputs
    with torch.no_grad():
        for data in testloader:
            images, labels = data

            outputs = net(images)
            _, predicted = torch.max(outputs, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()

    print(f'Accuracy of the network on the 10000 test images: {100 * correct // total} %')


    #test code for detecting what images the model was good at detecting and not good at detecting
    correct_pred = {classname: 0 for classname in classes}
    total_pred = {classname: 0 for classname in classes}

    # again no gradients needed
    with torch.no_grad():
        for data in testloader:
            images, labels = data
            outputs = net(images)
            _, predictions = torch.max(outputs, 1)
            # collect the correct predictions for each class
            for label, prediction in zip(labels, predictions):
                if label == prediction:
                    correct_pred[classes[label]] += 1
                total_pred[classes[label]] += 1


    # print accuracy for each class
    for classname, correct_count in correct_pred.items():
        accuracy = 100 * float(correct_count) / total_pred[classname]
        print(f'Accuracy for class: {classname:5s} is {accuracy:.1f} %')  

    del dataiter
