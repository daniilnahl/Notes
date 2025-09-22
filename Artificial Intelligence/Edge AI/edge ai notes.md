# What is Edge AI?
Edge AI is running artificial intelligence algorithms on devices that are at the edge of internet (sensors, IoT) instead of cloud to reduce bandwitdh usage and lower latency.

Edge AI is pretty much built on top of Edge Computing...
## What is Edge Computing?
Basically, running services/software directly on the end devices or local network servers instead of big cloud servers.

#### What are advantages of edge computing?
**BLERP**
- **Banwidth**: Reduced bandwidth usage - you no longer need to constantly stream raw data to have it stored, analyzed, or processed by a cloud computing service. Instead, you can simply transmit the results of such processing.
- **Latency**: network latency is the round-trip time it takes for information to travel to its destination (e.g. a cloud server) and for the response to return to the end-point device. For cloud computing, this can be 100s of milliseconds or more. If processing is performed locally, such latency is often reduced to almost nothing.
- **Energy**: Transmitting data, especially via a wireless connection like WiFi, usually requires more electrical power than processing the data locally.
- **Reliability**: Edge computing means that data processing can often be done without an internet connection.
- **Privacy**: If raw data is processed directly on an end device without travelling across the network, it becomes harder to access by malicious parties. This means that user data can be made more secure, as there are fewer avenues to access that raw data.

#### What are disadvanatages of edge computing?
- **Resource constraints**- Most edge devices do not offer the same level of raw computing as most cloud servers. If you need to crunch numbers quickly or run complex algorithms, you might have to rely on cloud computing.
- **Limited remote access** - Services running locally on edge or end devices might not be easily accessed via remote clients. To provide such remote access, you often need to run additional services (such as a web server) and/or configure a VPN on your local network.
- **Security** - Many IoT devices come from the manufacturer with default login credentials and open ports, making them prime targets for attackers (such as with the infamous Mirai botnet attack in 2016). You and your network administrators are responsible for implementing and enforcing up-to-date security plans for all edge devices.
- **Scaling** - Adding more computing power and resources is often easy in cloud computing; you just pay the cloud service provider more money. Scaling your resources for edge computing often requires purchasing and installing additional hardware along with maintaining the infrastructure.

# How to use Edge AI?

## What are some implementation strategies?
1. When defining a threshold for a ML inference create two histogram for true negatives and true positives. Put those histrograms over a plot of y-axis # of time a result occured and x-axis confidence score.
    1. This way you can see where they overlap and come up with a threshold based on your needs.
    2. If you are doing security and high critical stuff it might be well to set threshold lower and experience more true negatives, but also catch those rare true positives in that zone.
## What are some platforms to create Edge AI?
### Edge Impulse
### What is it? 
Edge Impulse is a platform that allows to deploy and train ai models on variety of hardware.

### How to use it?
1. Create a project.
2. Connect a device. Check the [supported devices](https://docs.edgeimpulse.com/hardware) and connect using their pre-built way or by connecting a device through serial using their [data forwarder](https://docs.edgeimpulse.com/tools/clis/edge-impulse-cli/data-forwarder)
3. Collect data.
    - Split data into three categories: ***Training, Validation and Testing.***
        - Training(60%): data on which the model will be based on.
        - Validation(20%): data on which hyperparamters of the model will be fine tuned.
        - Testing(20%): data on which the final model will be evaluated on.
4. Create imuplse -> select spectral analysis and "learning block" (type of ML).

5. Go to spectral features -> generate features.
    - Extract feature sets from the data (done auto). 
        - *Edge impulse does this automatically, but I can still manually tweak it if I want to*.
        - Extract the KEY features needed for the model to predict whatever the objective is!
        - Ensure that the feature sets encompass not just a single frame, but multiple. Basically, 1 sec feature set is going to create a poor model in contast with a 3 sec feature set that shows how the parameters changed over time, creating a better picture on how to predict something.

# How to prepare for Edge AI project?
- [Step 1](https://docs.edgeimpulse.com/knowledge/courses/edge-ai-fundamentals/how-to-choose-an-edge-ai-device)
- [Step 2](https://docs.edgeimpulse.com/knowledge/courses/edge-ai-fundamentals/edge-ai-lifecycle) 