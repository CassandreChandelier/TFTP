# TFTP


##Question 1

In this first question, we just create two functions gettftp and puttftp we are going to complete later.
Then, we will uploaded and download files from a server.
Actually, we can enter in each function.
Moreover, we created a function command to print some text.

```bash
void command(char *output,int exit){
        write(exit, output, strlen(output));
}
```

