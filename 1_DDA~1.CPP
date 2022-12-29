# include <graphics.h>
# include <math.h>
# include <iostream.h>
# include <conio.h>
# include <dos.h>


void DDALine(int x1,int y1,int x2,int y2,int Color);

int main()
{

    int x1,y1,x2,y2,r,r1,Color;
    int gd,gm; gd=DETECT;
    initgraph(&gd,&gm,"c://Turboc3//bgi");
    cleardevice();
    DDALine(100,113,50,200,4);
    DDALine(50,200,150,200,4);
    DDALine(150,200,100,113,4);

    r=50/sqrt(3);
    x1=(100+50+150)/3;
    y1=(113+200+200)/3;

    circle(x1,y1,r);

    r1=100/sqrt(3);   
    circle(x1,y1,r1); 

    delay(10000); 
 
    return 0;
}
void DDALine(int x1,int y1,int x2,int y2,int Color)
{
    float dX,dY,Steps;
    float xInc,yInc,i,x,y;

    dX = x2 - x1;
    dY = y2 - y1;

    if (abs(dX) > abs(dY))
    {
        Steps = abs(dX);
    }
    else
    {
        Steps = abs(dY);
    }

    xInc = dX/Steps;
    yInc = dY/Steps;

    x = x1;
    y = y1;

    for (i=1;i<=Steps; i++)
    {
        putpixel(x,y,Color);
        x = x+xInc;
        y=y+yInc;
    }
}

