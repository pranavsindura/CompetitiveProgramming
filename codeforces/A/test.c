#include<stdio.h>

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        char str[100005];
        scanf("%s", str);
        //counting vowels
        int j, count = 0;
        for(j = 0; str[j] != '\0'; j++)
        {
            if(str[j] == 'A' || str[j] == 'a' || str[j] == 'E' || str[j] == 'e' || str[j] == 'I' || str[j] == 'i' || str[j] == 'O' || str[j] == 'o' || str[j] == 'U' || str[j] == 'u')
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}