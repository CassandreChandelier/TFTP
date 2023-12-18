# TFTP


## Question 1

In this first question, we just create two functions gettftp and puttftp we are going to complete later.
Then, we will uploaded and download files from a server.
Actually, we can enter in each function.
Moreover, we created a function command to print some text.

```bash
void command(char *output,int exit){
        write(exit, output, strlen(output));
}
```

## Question 2

We use the function getaddrinfo to get the address of the server by using
the structure addrinfo.
We return the address of the server we get.
Actually, we have no address which is associated with the hostname.
