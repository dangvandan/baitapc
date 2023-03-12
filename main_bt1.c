#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
/*
1. Random 1 mảng bất kỳ
2. Sắp xếp mảng theo thứ tự tăng dần 
3. Liệt kê các phần tử có số lần xuất hiện 
*/
#pragma region mảng bất kỳ // mảng ngẫu nhiên 
typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    for(int i = 0; i < value->size; ++i){
        value->firstAdd[i] = randomA(0,10);
    }    
}

void displayArray(typeArray arr) {
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.firstAdd[i]);
    }
}
#pragma endregion
// Sắp xếp mảng: tăng dần
#pragma region săpxep
void sortArray(typeArray *arr) 
{
   printf("sap xep theo thu tu tang dan:\n");
   int tg;
    for(int i = 0; i < arr->size - 1; i++){
        for(int j = i + 1; j < arr->size-1; j++){
            if(arr->firstAdd[i] > arr->firstAdd[j]){
                // Hoan vi 2 so arr[i] va arr[j]
                tg = arr->firstAdd[i];
                arr->firstAdd[i] = arr->firstAdd[j];
                arr->firstAdd[j] = tg;        
            }
        }
        printf("%d",arr->firstAdd[i]);
    }
}
#pragma endregion
// th 1: sắp xếp theo thứ tự tăng dần , nếu số trước bằng số sau thì cộng nên 1.. cứ so sánh cho hết vòng lặp  
#pragma region TH1
void countArray_case1(typeArray *arr) {
    int dem = 1;
    int i;
    for (i = 0; i < (arr->size - 1); i++)
    {
        if(arr->firstAdd[i] == arr->firstAdd[i + 1]) {
            dem++;
        }
        else {
            printf("%2d xuất hiện số lần là: %2d \n", arr->firstAdd[i], dem);
            dem = 1;
        }
    }
    printf("%2d xuất hiện số lần là: %2d \n", arr->firstAdd[i], dem);
    
}
#pragma endregion
//TH2 : xét từng phần tử mảng gốc xem nó đã có trong mảng phụ chưa . 
//nếu chưa thì thêm vào mảng phụ 
// có rồi thì tăng biến dếm tại vị treis tương ứng của mảng phụ nên 
#pragma region TH2

int chuaco(int *b,int n,int x)
{
    for (int i = 0; i < n; i++)
    {
        if(b[i]==x)
        {
            return i;
        }
    }
    return -1; // phần tử x chưa tôn tai mang b
    
}
void countArray_case2(typeArray *arr)
{
    int b[100]; // lưu giái trị
    int dem[100];// lưu số lần xuất hiện giá trị tương ứng 
    int i;          
    int size = 0 ;// số lương phần tử độc lập trong mảng phụ 
    for(int i = 0 ; i < arr->size; i++)
    {
        dem[i]=0;
    }
    for(int i=0;i<arr->size;i++){
        int index = chuaco(b,size,arr->firstAdd[i]);
        if(index == -1)// nếu vị trí chưa tồn tại
        {
            b[size] = arr->firstAdd[i];    
            dem[size]=1;
            size++;
        }
        else{
            dem[index]++;
        }
        
    }
    hienthi(b,dem,size);
}
void hienthi (int *b, int *dem,int n)
{
    printf("-------- kết quả -----");
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d:%d\n",b[i],dem[i]);
    }
}
#pragma endregion
int main(int argc, char const *argv[])
{
    typeArray arr;
    randomArray(&arr, 20);
    sortArray(&arr);
    countArray_case1(&arr);
    countArray_case2(&arr);
    return 0;
}