#include<stdio.h>
#include<stdint.h>
void DocChuSo(uint8_t ChuSo)
{
    switch (ChuSo)
    {
    case 0:
        printf("khong");
        break;
    case 1:
        printf("mot");
        break;
    case 2:
        printf("hai");
        break;
    case 3:
        printf("ba");
        break;
    case 4:
        printf("bon");
        break;
    case 5:
        printf("nam");//567899
        break;
    case 6:
        printf("sau");
        break;
    case 7:
        printf("bay");
        break;
    case 8:
        printf("tam");
        break;
    case 9:
        printf("chin");
        break;    
    default:
        break;
    }
}
// Dếm Số lượng chữ số
int demsoluongchuso(int n)
{
    int dem=0;
    while(n!=0)
    {
        n/=10;
        dem++;
    }
    return dem;

}
// đảo số 
void DOCSO(int n)
{
    //12345=>54321
    int sodao=0;
    while (n!=0)
    {
        sodao=sodao*10+n%10;
        n/=10;
    }
    int soluong=demsoluongchuso(sodao);
    while (sodao != 0)
    {
        DocChuSo(sodao % 10);
        if(soluong ==7)
        {
            printf("trieu \t");
        }
        if(soluong == 6)
        {
            printf("tram \t");
        }
        if(soluong == 5)
        {
            printf("muoi \t");
        }
        if(soluong == 4)
        {
            printf("ngan\t");
        }
        if(soluong == 3)
        {
            printf("tram\t");
        }
        if(soluong == 2)
        {
            printf("muoi\t");
        }
        soluong--;
        sodao /=10;
    }
    
    
}
int main(int argc, char const *argv[])
{
    int n=12349898;
    DOCSO(n);
    return 0;
}
