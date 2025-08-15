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