#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//�������룺��������ָ�Ϊ��Ӧ��ż��� 
#define THE_TITLE  10

//��һ�� ��д�ж�һ���ַ������Ƿ��ǻ��ĵĺ���������Ƿ���true�����򷵻�false
#if (THE_TITLE == 1)
bool plalindrome(char *p);

void main()
{
    char p[100];
    gets(p);
    if (plalindrome(p))
        printf("true\n");
    else
        printf("false\n");
}

bool plalindrome(char *p)
{
    int i;
    int len = strlen(p);
    for (i = 0; i < len / 2; i++)
    {
        if (p[i] != p[len - i - 1])
            return false;
    }
    return true;
}
#endif

//�ڶ��� 
#if (THE_TITLE == 2)

#define PI 3.14
#define L 2 * PI *r
#define S PI *r *r
int main()
{
    double r, l, s;

    printf("Enter radius: ");
    scanf("%lf", &r);
    l = L;
    s = S;
    printf("l=%.2f, s=%.2f\n", l, s);
}
#endif

//������ ��дһ����������һ���ַ��������������֮��������ָ��ʵ�֣�
#if (THE_TITLE == 3)
int main()
{
    char temp, *s, *s1, *s2;
    s1 = (char *)malloc(sizeof(100)); /*����洢�ռ�*/
    printf("�����ַ�����");
    gets(s1);
    s = s2 = s1;
    while (*s2 != '\0')
    {
        s2++;
    }
    s2--;
    while (s1 < s2)
    {
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        s1++;
        s2--;
    }
    printf("�����ַ�����%s\n", s);
    return 0;
}
#endif

//������
#if (THE_TITLE == 4)


int main()
{

    char *mystrstr(const char *str1, const char *str2);
    char a[101], b[101];
    scanf("%s%s", &a, &b);
   
    if(mystrstr(a, b) == 0)	
    	printf("-1");
    else
    	printf("%d",(strlen(a)- strlen(mystrstr(a, b))));
    
}
char *mystrstr(const char *str1, const char *str2)
{
    char *p1 = str1;
    char *p2 = str2;
    int i = 0;
    while (*p1) //��*��⵽�س�'\n'��ʱ������ѭ����
    {
        char *flag = p1; //���ñ�־λ������ع���
        while (*p1 == *p2 && *p1 != '\0')
        {
            //����ѭ�������������֣�1 ���ַ�����ȣ������Ӵ� �� 2 ��p2�����˶�����ȵģ� �Ӵ�
            p1++;
            p2++;
        }

        if (*p2 == '\0') //�ڶ����ַ����ߵ�\n���𣿣�����
        {
            return flag;
            i++; //�����ҵ��Ӵ�����ʼλ�á�
        }
        if (!*p1)
        {
            //�ߵ����p1����\0 ��p2û�е���\0��û���ҵ�
            return NULL;
        }
        //�ߵ����û��ƥ��ɹ�����������һλ��ʼƥ�������Ӵ�
        p1++;
    }
    return NULL;
}
#endif

//������
#if (THE_TITLE == 5)
int main()
{
    int well, up, down, min = 0;
    int sum = 0;
    scanf("%d%d%d", &well, &up, &down);

    for (min = 0;;)
    {
        if (up > well)
        {
            printf("1");
            break;
        }
        sum = sum + up;
        min++;

        if (sum == well)
        {
            printf("%d", min);
            break;
        }
        else if (well - sum + down <= up)
        {
            printf("%d", min + 2);
            break;
        }
        sum = sum - down;
        min++;
    }
}
#endif

//������
#if (THE_TITLE == 6)
//�����ʽ������ô���⣬�����ֱ�Ӱ� heightSize Ū�ɺ궨�� ��Ҫ�ǿ�����˼·
#define heightSize 9  
int main()
{
    int height[100];
    int  i;
    int head = 0;
    int rear = heightSize - 1;
    int maxArea = 0;
    int tempArea = 0;

	
    for (i = 0; i < heightSize; i++)
    {
        scanf("%d", &height[i]);
    }

    while (head < rear)
    {
        tempArea = (rear - head) *
				   ((height[head] > height[rear]) ? height[rear] : height[head]);

        maxArea = (maxArea >= tempArea) ? maxArea : tempArea;

        if (height[head] >= height[rear])
        {
            rear--;
        }
        else
        {
            head++;
        }
    }

  printf("%d",maxArea);
}

#endif

//������
#if (THE_TITLE == 7)

#define MAXN 1000;   //�ָ�һ�ݵĴ�С 
/* ���η��󶨻���*/
double Definite_integral(double a, double b, double (*p)(double x))
{
    int i; 
	int n = MAXN;
    double x, y1, y2, deta, f;
    deta = (b - a) / n;
    x = a;
    y1 = (*p)(x);
    f = 0;
    for (i = 0; i < n; i++)
    {
        x += deta;
        y2 = (*p)(x);
        f += (y1 + y2) * deta / 2;
        y1 = y2;
    }
    return f;
}
/*���屻������,���ֹ�ѡ��*/
double fun1(double x)
{
    double fx;
    fx = x;
    return fx;
}
double fun2(double x)
{
    double fx;
    fx = x * x * x + x * x + x + 1;
    return fx;
}
double fun3(double x)
{
    double fx;
    fx = sin(x);
    return fx;
}
int main()
{
    double a, b;
    printf("����������");
    scanf("%lf %lf", &a, &b);
    printf("����Ϊ%lf\n", Definite_integral(a, b, fun2));
}

#endif

//�ڰ���
#if (THE_TITLE == 8)
int main() 
{
	
	char s1[100],s2[100],str[100];
	int i,num;
	
	gets(s1);
    gets(s2);
	strcpy(str,s1);
	
   while (strstr(s1,s2))
   {

		i=0;
		
		num=strlen(s1);
		char *p=strstr(s1,s2);   //������s1���ҵ��ĵ�һ��s2�ַ�����ַ 
		int cnt=strlen(p);       //cnt�������ҵ��ĵ�ǰs2�ַ�����ַ֮�����е��ַ������� 

		while (i!=strlen(s2))
		{    

		    *p='\0';  //��p�е�s2�ַ�����'\0'������p������һ����ַ 
		    p++;          
			i++;
		}
		strcpy(s1+(num-cnt),p);  //��ǰ��λ����num-cntΪ��ǰs1�ַ������ַ����� 
	}
	num=strlen(s1);

	for (i=0;i<=num;i++)
	{
		printf("%c",s1[i]);
	}
	
	printf("%d��",(strlen(str)-strlen(s1))/strlen(s2));		//����������ȥ��s2���s1���Լ�s2���ֵĴ��� 
	return 0;
}


#endif

//�ھ���
#if (THE_TITLE == 9)
#include <stdio.h>
void main()
{
    int f[1000], g[1000], m, n, i, j, dis, index;
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &f[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &g[i]);
    }

    index = f[0] - g[0];
    if (index < 0)
        index = -index;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            dis = f[i] - g[j];
            if (dis < 0)
                dis = -dis;
            if (dis < index)
                index = dis;
        }
    }
    printf("%d", index);
}
#endif

//��ʮ��

# if  (THE_TITLE == 10)
struct infoBook
{
	char name[80];
	char author[80];
	int num;
	int date;
};

void main()
{
	int i,j;
	/*������ֱ�Ӷ���ģ���һ��������Ҳ��*/
	struct infoBook a[5]={
						  {"ebooks","yincheng",5,18880808},
						  {"lbook","haoyun",34,12330205},
						  {"c++","wangwen",1,19870731},
						  {"C primer","vicky",2,19880310},
					   	  {"data struction","ben",3,19550302}
						 };
	
	for( i=0;i<5;i++)	//����ʼ����Ϣ��ӡ����Ļ��
	{
		printf("%-15s\t\t%s\t\t%d\t%d\n",a[i].name,a[i].author,a[i].num,a[i].date);
	}
	printf("\n\n After order!\n");
	for( i=0;i<4;i++) // ���鱾��������
	{
		for ( j=i+1;j<5;j++)
		{
			char t=a[i].name[0];
			char s=a[j].name[0];
			
			if(t>s)
			{
				struct infoBook temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for( i=0;i<5;i++)	//���������Ϣ��ӡ����Ļ��
	{
		printf("%-15s\t\t%s\t\t%d\t%d\n",a[i].name,a[i].author,a[i].num,a[i].date);
	}

	puts("please enter the book");
	char books[80];
	gets(books);  // ��������

	for( i=0;i<5;i++) // �������������в�ѯ�������ѯ�������ӡ��ϸ��Ϣ
	{
		if(strcmp(books,a[i].name)==0)
		{
			printf("%-15s\t\t%s\t\t%d\t%d\n",a[i].name,a[i].author,a[i].num,a[i].date);
			system("pause");
			return;
		}
	}

	printf("NO");
	system("pause");
}

#endif

//��ʮһ��
#if (THE_TITLE == 11)
int sum = 0;
int arr[100][100];
int i, j;
int t;

void cell(int i, int j);
void main()
{
    int n, m;
    printf("����������:");
    scanf("%d %d", &i, &j);
    for (n = 0; n < i; n++)
        for (m = 0; m < j; m++)
        {
            scanf("%d", &arr[n][m]);
        }
    for (n = 0; n < i; n++)
        for (m = 0; m < j; m++)
            if (arr[n][m] != 0)
            {
                t = arr[n][m];
                sum++;
                cell(n, m);
            }
    printf("%d\n", sum);
}

void cell(int x, int y)
{
    if (x == i || y == j || x < 0 || y < 0 || arr[x][y] == 0 || arr[x][y] != t)
        return;
    arr[x][y] = 0;
    cell(x + 1, y);
    cell(x - 1, y);
    cell(x, y + 1);
    cell(x, y - 1);
}
#endif

