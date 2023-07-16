// 32비트 숫자가 network byte order로 파일에 4바이트 크기로 저장되어 있을 때, 이를 읽어와 합을 출력하는 프로그램을 작성.
// USAGE : add-nbo <file1> <file2>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    FILE *fp1, *fp2;
    uint32_t num1, num2, sum;

    if (argc != 3) {
        printf("[-] USAGE : add-nbo <file1> <file2>\n");
        exit(-1);
    }

    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    if(fp1 == NULL || fp2 == NULL) {
        printf("[-] Cannot Open File\n");
        exit(-1);
    }

    fread(&num1, sizeof(uint32_t), 1, fp1);
    fread(&num2, sizeof(uint32_t), 1, fp2);

    num1 = ntohl(num1);
    num2 = ntohl(num2);
    sum = num1 + num2;

    printf("[*] %d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);

    fclose(fp1);
    fclose(fp2);
}
