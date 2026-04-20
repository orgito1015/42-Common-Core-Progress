*This activity has been created as part of the 42 curriculum by oleka*

# Net_Practice

## Description

Net_Practice is a system administration exercise focused on the fundamentals of computer networking. The goal is to configure small-scale network diagrams so that they function correctly. Through 10 progressive levels, you will learn how to assign IP addresses, configure subnet masks, connect devices through routers, and understand the role of a default gateway within a network.

Each level presents a non-functioning network diagram. Your task is to modify the available (unshaded) fields until the network configuration is correct and all communication goals are met.

## Instructions

### Running the Training Interface

1. Download the file attached to the activity's page on the 42 intranet.
2. Extract the contents to any folder of your choice.
3. Open the `index.html` file in your web browser.
4. The **Welcome to 42's NetPractice!** interface will load.
5. Enter your intranet login in the field provided, then click **Start!**.
   - You may also leave the field empty to try the review/practice version.

> ⚠️ It is very important that you enter your login in the interface before exporting your configurations.

### Using the Interface

- Each level displays a non-functioning network diagram along with a goal to achieve at the top of the window.
- Modify the unshaded fields to correct the network configuration.
- Use the **Check again** button to verify whether your configuration is correct.
- Consult the logs at the bottom of the page for hints (e.g., missing gateway, invalid IP address).
- Once a level is solved, a **Next level** button will appear.

### Exporting Configurations

- Before moving to the next level, click the **Get my config** button to download your configuration file for that level.
- Repeat this for all 10 levels.

### Submission

- You must complete all **10 levels** and export one configuration file per level.
- Place all **10 exported configuration files** at the **root of your Git repository**.
- Submit your repository as usual. Only the work inside the repository will be evaluated during the defense.
- Double-check your file names to ensure they are correct.

> ⚠️ During the defense, you must successfully complete 3 random levels (from levels 6 to 10) under a time limit. External tools are not allowed — only a simple calculator such as `bc` is tolerated.

## Resources

### Networking Concepts Studied

- **TCP/IP Addressing** — How IP addresses are structured and assigned within a network.
- **Subnet Mask** — How masks are used to divide networks into sub-networks and determine the network/host portions of an address.
- **Default Gateway** — The role of a gateway in routing traffic between networks.
- **Routers and Switches** — How these devices operate and differ in forwarding network traffic.
- **OSI Layers** — The conceptual model describing network communication layers (Physical, Data Link, Network, Transport, Session, Presentation, Application).
- **CIDR Notation** — Classless Inter-Domain Routing and how prefix lengths relate to subnet masks.
- **Routing Tables** — How routers use routing tables to determine where to forward packets.

### Reference Links

- [TCP/IP Addressing — IBM Documentation](https://www.ibm.com/docs/en/aix/7.2?topic=protocol-tcpip-addressing)
- [Subnet Mask Cheat Sheet](https://www.aelius.com/njh/subnet_sheet.html)
- [How Subnetting Works — Cisco](https://www.cisco.com/c/en/us/support/docs/ip/routing-information-protocol-rip/13788-3.html)
- [OSI Model Explained — Cloudflare](https://www.cloudflare.com/learning/ddos/glossary/open-systems-interconnection-model-osi/)
- [What is a Default Gateway? — Cloudflare](https://www.cloudflare.com/learning/network-layer/what-is-a-router/)
- [IP Routing Basics — NetworkLessons.com](https://networklessons.com/cisco/ccna-routing-switching-icnd1-100-105/ip-routing-explained)

### AI Usage

AI (Claude by Anthropic) was used during this activity for the following purposes:

- **Understanding concepts**: Used to clarify networking concepts such as subnetting, CIDR notation, and how routing tables work.
- **README generation**: The structure and content of this README were drafted with AI assistance based on the project specifications.
- **Debugging help**: Used to double-check reasoning when a network configuration produced unexpected results.

> All AI-generated content was reviewed, tested, and validated before being used. No AI tool was used to directly solve the NetPractice levels — all configurations were manually verified and understood.
