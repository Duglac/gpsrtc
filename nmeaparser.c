#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stddef.h>
int main() {
    int fd;
    char buffer[256];
    struct termios serial;

    // Open the serial port
    fd = open("/dev/ttyO4", O_RDWR | O_NOCTTY);
    if (fd == -1) {
        perror("Error opening serial port");
        return 1;
    }

    // Configure the serial port
    memset(&serial, 0, sizeof(struct termios));
    serial.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    serial.c_iflag = IGNPAR;
    serial.c_oflag = 0;
    serial.c_lflag = 0;
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &serial);
    int flag = 1;
    // Read data from the serial port
    while (flag == 1) {
        int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
        sleep(1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            // Look for the GGA sentence
            char *ggaStart = strstr(buffer, "$GNGGA");
            if (ggaStart != NULL) {
                // Extract the latitude and longitude from GGA sentence
                char *strPtr = ggaStart;
                char *token;
                int count = 0;
                while (count < 10){
                 token = strsep(&strPtr,",");
                 if (count == 2){
                  printf("Latitude: %s\n", token);
                 }
                 if (count == 4){
                  printf("Longitude: %s\n", token);
                  flag = 0;
                 }
                 count++;
                }
            }
        }

    }

    // Close the serial port
    close(fd);

    return 0;
}
