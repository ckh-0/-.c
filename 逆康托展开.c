/* 逆康托展开
       假设求4位数中第19个位置的数字。
        ① 19减去1  → 18
        ② 18 对3！作除法 → 得3余0
        ③  0对2！作除法 → 得0余0
        ④  0对1！作除法 → 得0余0
       据上面的可知：
       我们第一位数（最左面的数），比第一位数小的数有3个，显然 第一位数为→ 4
       比第二位数小的数字有0个，所以 第二位数为→1
       比第三位数小的数字有0个，因为1已经用过，所以第三位数为→2
       第四位数剩下 3
       该数字为  4123 
*/
#include<stdio.h>
#define MAX 4
int fac[] = { 1,1,2,6,24,120,720,5040,40320,362880 };//10以内的阶乘
void decantor(int n, int k, int s[])
{
    int i, j, t, vst[MAX+1] = { 0 };
    --k;
    for (i = 0; i < n; i++)
    {
        t = k / fac[n - i - 1];
        for(j=1;j<=n;j++)
            if (!vst[j])
            {
                if (t == 0)
                    break;
                --t;
            }
        s[i] = j;
        vst[j] = 1;
        k %= fac[n - i - 1];
    }
}
int main()
{
    int s[MAX];
    decantor(MAX, 19, s);
    for (int i = 0; i < MAX; i++)
        printf("%d", s[i]);
}
