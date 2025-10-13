#include <stdio.h>

int main(){
    int a, b, diff, sum, pro, div, rem;
    float divv;
    printf("ARITHMETIC OPERATIONS\n");
    printf("Enter two integers (a,b): ");
    scanf("%d,%d", &a, &b);
    sum = a + b;
    printf("Their sum is %d\n",sum);
    diff = a - b;
    printf("Their difference is %d\n",diff);
    pro = a * b;
    printf("Their product is %d\n",pro);
    div = a / b;
    printf("Their integer division result is %d\n",div);
    divv = a / b;
    printf("Their float division result is %f\n",divv);
    rem = a % b;
    printf("Their remainder is %d\n",rem);
    
    printf("\n\nOperator Precedence and Associativity\n");
    int a1, b1, c1, res1,res2,res3,res4;
    printf("Enter 3 integers (a,b,c): ");
    scanf("%d,%d,%d", &a1, &b1,&c1);
    res1 = a1 + b1 * c1; 
    res2 =  (a1 + b1) * c1;
    res3 = a1-b1-c1;
    res4 = (a1-b1) - c1;
    printf("The difference between  a + b * c and (a + b) * c.\n a + b * c = %d\n(a + b) * c = %d\n", res1,res2);
    printf("The difference between  a - b - c and (a - b) - c.\n a - b - c = %d\n(a - b) - c = %d\n", res3,res4);

    printf("\n\nIncrement and Decrement\n");
    int k, i = 1, j =2;
    k = ++i + j++;
    printf("Using ++i + j++:\ni =%d, j=%d, k=%d\n", i,j,k);
    i = 1, j =2;
    k = i++ + j++;
    printf("Using i++ + j++:\ni =%d, j=%d, k=%d\n", i,j,k);
    /***
     * The key differnce is:
     * In first case the value is 'pre-incremented' which means it increments before it is read.
     * In second case the value is 'post-incremented' which means its first read and then incremented.
     */

    printf("\n\nCompound Assignment\n");
    int x = 10;
    x += 1;
    printf("x is 10.\nUsed += 1 on x. x is %d\n", x);
    x -= 2;
    printf("Used -= 2 on x. x is %d\n", x);
    x *= 3;
    printf("Used *= 3 on x. x is %d\n", x);
    x /= 2;
    printf("Used /= 2 on x. x is %d\n", x);


    printf("\n\nMini Challenge: UPC Check Digit\nEnter 11 UPC digits(a b c...): ");
    int u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11;
    scanf("%d %d %d %d %d %d %d %d %d %d %d", &u1,&u2,&u3,&u4,&u5,&u6,&u7,&u8,&u9,&u10,&u11);
    int odd = u1 + u3 + u5 + u7 + u9 + u11;
    int even = u2 + u4+ u6 + u8+ u10;
    odd *= 3;
    odd += even;
    odd -= 1;
    int total = odd % 10;
    u9 -= total;
    printf("Check digit is %d", u9);
    return 0;
}