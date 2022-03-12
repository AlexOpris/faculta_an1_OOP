#include <cstring>
#include <iostream>



int main()
{
    int n,i,x;
    char s[200], a[200];
    
    std::cin >> n;
    strcpy_s(s, "N qtaj tgojhy twnjsyjiuwtlwfrrnsl!?");
    
    for (i = 0; i < strlen(s); i++)
    {
        if (n > 0) 
        {
            if ((s[i] >= 'A' && s[i] <= 'Z')) 
            {
                s[i] = s[i] - n;
                if (isalpha(s[i]) == 0)
                {
                    x = 'A' - s[i];
                    s[i] = 'Z' - x + 1;
                }
            }

            if ((s[i] >= 'a' && s[i] <= 'z'))
            {
                s[i] = s[i] + n;
                if (isalpha(s[i]) == 0)
                {
                    x = 'A' - s[i];
                    s[i] = 'Z' - x + 1;
                }
            }
        }
        else
        {
            if ((s[i] >= 'A' && s[i] <= 'Z')) 
            {
                {
                    s[i] = s[i] - n;
                    if (isalpha(s[i]) == 0)
                    {
                        x = s[i] - 'Z';
                        s[i] = 'A' + x - 1;
                    }
                }
                if ((s[i] >= 'a' && s[i] <= 'z'))
                {
                    s[i] = s[i] + n;
                    if (isalpha(s[i]) == 0)
                    {
                        x = s[i] - 'Z';
                        s[i] = 'A' + x - 1;
                    }
            }
        }

    }

    std::cout << s;

}

