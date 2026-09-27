#include <stdio.h>

void test_1(){
    char *p1 = "hello";
    char *p2 = {"hello"};
    char  p3[] = "hello";

    // 尝试修改字符串
    //*p1 = 'H'; // 错误：常量字符串不能修改
    //*p2 = 'H'; // 错误：跟p1相同，都是字符串面量
    *p3 = 'H';   // 正确，输出Hello 

    printf("p1: %s\n", p1); // 输出：hello
    printf("p2: %s\n", p2); // 输出：Hello
    printf("p3: %s\n", p3); // 输出：Hello
    
}

void test_2(){
    char acX[] = "abc"; //四个字节 
    char acY[] = {'a', 'b', 'c'}; //三个字节
    char acZ[] = {"abc"}; //四个字节
    printf("size of acX: %d\n", sizeof(acX)); 
    printf("size of acY: %d\n", sizeof(acY)); 
    printf("size of acZ: %d\n", sizeof(acZ)); 
}

int main() {
    //test_1();
    test_2();
    return 0;
}
