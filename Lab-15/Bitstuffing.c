#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], stuffed[200];
    int i, j = 0, count = 0;

    printf("Enter the binary data: ");
    scanf("%s", data);

    for (i = 0; i < strlen(data); i++)
    {
        stuffed[j++] = data[i];
        if (data[i] == '1')
        {
            count++;
            if (count == 5)
            { // After 5 consecutive 1s, stuff a 0
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    stuffed[j] = '\0';

    printf("Bit-stuffed data: %s\n", stuffed);

    return 0;
}