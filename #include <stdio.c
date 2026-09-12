#include <stdio.h>

void fifo(int pages[], int n, int f)
{
    int frame[f];

    for(int i=0;i<f;i++)
        frame[i]=-1;

    int faults=0;
    int pointer=0;

    for(int i=0;i<n;i++)
    {
        int found=0;

        for(int j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
            {
                found=1;
                break;
            }
        }

        if(found==0)
        {
            frame[pointer]=pages[i];

            pointer=(pointer+1)%f;

            faults++;
        }
    }

    printf("\nFIFO Page Faults = %d\n",faults);
}

void lru(int pages[], int n, int f)
{
    int frame[f];
    int recent[f];

    for(int i=0;i<f;i++)
    {
        frame[i]=-1;
        recent[i]=-1;
    }

    int faults=0;
    int time=0;

    for(int i=0;i<n;i++)
    {
        int found=0;

        for(int j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
            {
                found=1;

                recent[j]=time++;

                break;
            }
        }

        if(found==0)
        {
            int pos=0;

            for(int j=1;j<f;j++)
            {
                if(recent[j]<recent[pos])
                    pos=j;
            }

            frame[pos]=pages[i];

            recent[pos]=time++;

            faults++;
        }
    }

    printf("LRU Page Faults = %d\n",faults);
}

void optimal(int pages[], int n, int f)
{
    int frame[f];

    for(int i=0;i<f;i++)
        frame[i]=-1;

    int faults=0;

    for(int i=0;i<n;i++)
    {
        int found=0;

        for(int j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
            {
                found=1;
                break;
            }
        }

        if(found==0)
        {
            int pos=-1;
            int farthest=-1;

            for(int j=0;j<f;j++)
            {
                int k;

                for(k=i+1;k<n;k++)
                {
                    if(frame[j]==pages[k])
                    {
                        if(k>farthest)
                        {
                            farthest=k;
                            pos=j;
                        }

                        break;
                    }
                }

                if(k==n)
                {
                    pos=j;
                    break;
                }
            }

            frame[pos]=pages[i];

            faults++;
        }
    }

    printf("Optimal Page Faults = %d\n",faults);
}

int main()
{
    int n,f;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int pages[n];

    printf("Enter page sequence:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    fifo(pages,n,f);

    lru(pages,n,f);

    optimal(pages,n,f);

    return 0;
}