#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i;
    for(i = 0; i < n; i++)
    {
        int r, c;
        scanf("%d %d", &r, &c);

        int count = 0;

        // Loop through each row in the grid
        int j;
        for(j = 0; j < r; j++)
        {
            char row[101];
            scanf("%s", row);

            // Loop through each column
            int k;
            for(k = 0; k < c; k++)
            {
                // Check if this cell has a hyena
                if(row[k] == 'H')
                {
                    count++;
                }
            }
        }

        printf("Location #%d: %d\n", i + 1, count);
    }

    return 0;
}
