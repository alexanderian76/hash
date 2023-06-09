#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned long stringLength(char *str)
{
    unsigned long length = 0;
    while (*str != '\0')
    {
        str++;
        length++;
    }
    return length;
}

char* encryptC(char *str, char *code)
{
    unsigned long codeLength = stringLength(code);
    // cout << codeLength << endl;

    char *tmpStr = (char *)malloc(3 * sizeof(char));
    char *resStr = (char *)malloc(stringLength(str) * 3 * sizeof(char));

    for (int i = 0; i < stringLength(str); i++)
    {
        // if ((int)str[i] > 64 && (int)str[i] < 123)

        str[i] += (int)code[i % codeLength];
        // str[i] = (int)str[i];
        if ((int)str[i] < 0)
        {
            sprintf(tmpStr, "%d", abs((int)str[i]) + 128);
        }
        else
        {
            if ((int)str[i] == 0)
            {
                sprintf(tmpStr, "000");
            }
            else if ((int)str[i] < 10)
            {
                sprintf(tmpStr, "00%d", (int)str[i]);
            }
            else if ((int)str[i] < 100)
            {
                sprintf(tmpStr, "0%d", (int)str[i]);
            }
            else
            {
                sprintf(tmpStr, "%d", (int)str[i]);
            }
        }
        for (int j = i * 3; j < i * 3 + 3; j++)
        {
            resStr[j] = tmpStr[j - 3 * i];
        }
        // cout << tmpStr << endl;
    }
    // cout << resStr << endl;
    // str = resStr;
    //  free(str);
    // str = (char*)malloc(stringLength(resStr) * sizeof(char));
    //strcpy(str, resStr);
    //free(resStr);
    free(tmpStr);
    free(str);
    return resStr;
}

char* decryptC(char *str, char *code)
{
    unsigned long codeLength = stringLength(code);
    char *tmpStr = (char *)malloc(3 * sizeof(char));
    char *resStr = (char *)malloc(stringLength(str) / 3 * sizeof(char));
    char *tmpInt = (char *)malloc(3 * sizeof(char));

    for (int i = 0; i <= stringLength(str); i++)
    {
        tmpStr[i % 3] = str[i];
        if (i % 3 == 2)
        {

            for (int j = 0; j < 3; j++)
            {

                tmpInt[j] = (tmpStr[j]);

                // cout << (int)tmpStr[j] << endl;
            }
            //  cout << tmpInt  << " " << (int)code[(i + 1) / 3 - 1] << endl;
            // cout << (char)(atoi(tmpInt) - (int)code[(i + 1) / 3 - 1])<< endl;
            if (atoi(tmpInt) > 128)
            {
                resStr[(i + 1) / 3 - 1] = -(atoi(tmpInt) - 128) - code[((i + 1) / 3 - 1) % codeLength];
            }
            else
            {
                resStr[(i + 1) / 3 - 1] = atoi(tmpInt) - code[((i + 1) / 3 - 1) % codeLength];
            }

            // tmpStr = "";
        }

        // str[i] -= (int)code[i % codeLength];
    }
    // str = resStr;

   // strcpy(str, resStr);
    puts(resStr);
   // free(resStr);
    free(tmpInt);
    free(tmpStr);
    free(str);
    return resStr;
}

int main()
{
    puts("enter code");
    char *code = (char *)malloc(sizeof(char));
    char *str = (char *)malloc(sizeof(char));
    scanf("%s", code);
    puts("enter string");
    scanf("%s", str);
    puts(str);
    int length = 0;
    length = stringLength(str);
    printf("%d\n", length);
    str = encryptC(str, code);
    puts(str);
    str = decryptC(str, code);
    puts(str);
    for (int i = 0; i < length; i++)
    {

        // str[i]
        // cout << (int)str[i] << endl;
    }

    return 0;
}
