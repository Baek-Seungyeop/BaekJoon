#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main()
{
    //char strnum[7];
    //int len, testcase, num[6];
    //bool yesNo = true;

    //scanf("%d", &testcase);

    //while (testcase--)
    //{
    //    scanf("%s", strnum);

    //    len = strlen(strnum);

    //    for (int i = 0; i < len; i++)
    //    {
    //        num[i] = (strnum[i] - '0') + (strnum[len - 1 - i] - '0');
    //    }

    //    for(int i = 0; i<len; i++)
    //    {
    //        if (num[i] == num[len - 1 - i])
    //        {
    //            continue;
    //        }
    //        else
    //        {
    //            yesNo = false;
    //            break;
    //        }
    //    }
    //    if (yesNo) printf("YES\n");
    //    else printf("NO\n");
    //}
    int i, n;
    bool b;
    i = scanf("%d", &n);

    printf("%d %d", i, n);
	return 0;
}
//while (cin>>ia>>ib)
//{
//
//}
//
//while (1)
//{
//	if (!(cin >> ia >> ib)) break;
//}
//
//while (scanf("%d %d", &ia, &ib) != EOF)
//{
//
//}
//
//do 
//{
//	if (scanf("%d %d", &ia, &ib) == EOF) break;
//}