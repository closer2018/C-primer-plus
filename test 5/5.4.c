#include<stdio.h> //身高转换为英尺和英寸
#define FEET 2.54 //1 feet=2.54cm
#define INCH 30.48 //1 inch=30.48cm
int main(void)
{
    float height=0,inch=0;
    int feet=0;
    printf("请输入你的身高(cm):");
    scanf("%f",&height);
    while(height>0)
    {
        feet=(int)(height/INCH);
        inch=(height-feet*INCH)/FEET;
        printf("%.1f cm =%d 英尺, %.1f 英寸.\n",height,feet,inch);
        printf("当你输入0时结束\n");
        scanf("%f",&height);
    }
    system("pause");
    return 0;
}
