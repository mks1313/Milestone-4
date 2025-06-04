# NetPractice - 42 Project

## Description

**NetPractice** is a project designed to deepen my understanding of **networking** and **network protocols**. This project involves working with **sockets**, creating **client-server applications**, and learning how to handle communication over the network using **TCP/IP** and **UDP** protocols.

The main goal of this project is to develop a solid understanding of how data is transmitted across networks, how client-server models work, and how to manage network connections efficiently. Through hands-on exercises, I have learned to implement and debug networked applications and understand key concepts such as **packet analysis**, **network security**, and **communication protocols**.

### Features:
- **TCP/IP & UDP**: Gained practical experience with **TCP** and **UDP** protocols for client-server communication.
- **Socket Programming**: Learned how to use **sockets** for communication between clients and servers.
- **Client-Server Architecture**: Implemented multiple client-server applications, handling incoming and outgoing data efficiently.
- **Packet Analysis**: Understand how data is broken into packets and transmitted across networks.

## Key Learnings

- **Socket Programming**: I learned how to create and manage sockets for both **TCP** and **UDP** communication.
- **Network Protocols**: Gained a deep understanding of the **TCP/IP** stack and the differences between **TCP** and **UDP** in terms of reliability, ordering, and error handling.
- **Client-Server Model**: Implemented server-side applications to handle multiple client connections and client-side applications to send and receive data.
- **Networking Tools**: Used tools like **Wireshark** for analyzing network traffic and debugging issues in the communication process.

## Technologies Used

- **C**: Primary language for implementing networked applications.
- **Sockets**: Used for communication between client and server.
- **TCP/IP & UDP**: Protocols used for data transmission over the network.
- **Wireshark**: Used for network traffic analysis and debugging.
- **Make**: For automating the build process of the networked applications.

## Project Structure

- **Server-side Application**: The server listens for client connections, handles incoming requests, and sends responses.
- **Client-side Application**: The client connects to the server, sends requests, and processes the server's responses.
- **Network Debugging**: Network traffic is captured and analyzed to ensure the integrity and efficiency of the communication process.

## Usage

Once the server and client are compiled and running, the applications can be started by executing them in different terminal windows. The client will connect to the server, and the server will respond to client requests.

### Communication Process:

- **Client**: Sends a request (e.g., a message or data) to the server.
- **Server**: Receives the request, processes it, and sends a response back to the client.
- **Client**: Receives and processes the response from the server.

This client-server communication continues until the connection is closed.

## Contributing

Feel free to fork this repository if you have suggestions or improvements. Open a pull request for any enhancements, bug fixes, or new features.

## License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for more details.

