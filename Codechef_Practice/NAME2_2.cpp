#include<stdio.h>
#include<string.h>
char s1[25000],s2[25000],s3[25000];

int main()
{
    int t,found;
    char *i,*j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",&s1,&s2);
        if(strlen(s1)<strlen(s2))
        {
            strcpy(s3,s1);
            strcpy(s1,s2);
            strcpy(s2,s3);
        }

        i=s2;
        j=s1;
        int l2 = strlen(s2);
        int l1 = strlen(s1);
        while(i<&s2[l2])
        {
            found=0;
            while(j<&s1[l1])
            {
                if(*i==*j)
                {
                    found=1;
                    j++;
                    break;
                }
            j++;
            }
            if(found==0)
                break;
            i++;
        }
        if(found==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}