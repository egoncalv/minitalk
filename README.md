# minitalk
Small Program written in C that establishes a communication between a client and a server, using Linux Signals. This project is meant to teach us what are linux signal and how to use them.
The way we can do it is by converting each character into 8bit binaries, and sending each bit using SIGUSR1 or SIGUSR2. The server then interprets these signals and decodes the message.
With tis project, I've also dealed with bitwise operations, binary to decimal conversion, signals and structs.
