#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
class xyz
{
public:

void scanline(int [] ,int [],int);
};


 void xyz :: scanline(int xx[10],int yy[10],int n)
 {
    int temp,ymax=0,ymin=480,inx[50],y;
    float m[50],dx,dy;
    setcolor(BLUE);
   for(int i=0;i<n;i++)
   {
    if(yy[i]>=ymax)
	      ymax=yy[i];
    if(yy[i]<=ymin)
       ymin=yy[i];

     dx = xx[i+1] - xx[i];
     dy = yy[i+1]-yy[i];

     if(dy == 0)
	      m[i] = 0;
     if(dy == 0)
	      m[i] =1;
     if(dx!=0 && dy!=0)
	      m[i]= (float) (dx/dy);
  }

   for(y=ymax;y>=ymin;y--)
      {
       int cnt=0;
       for(i=0;i<n;i++)
	{
	  if((yy[i]>y&&yy[i+1]<=y) || ( yy[i]<=y&&yy[i+1]>y))
	    {
	      inx[cnt]=(xx[i]+(m[i] * (y-yy[i])));
	      cnt++;
	    }
	 }
	for(int k=0;k<cnt-1;k++)
	  {
	    for(i=0;i<cnt-1;i++)
	     {
	       if(inx[i]>inx[i+1])
		{
		  temp = inx[i];
		  inx[i] = inx[i+1];
		  inx[i+1] = temp;
		}
	     }
	 }
	 for(i=0;i<cnt-1;i+=2)

	  {
	     line(inx[i],y,inx[i+1]+1,y);
	     delay(100);
	   }
     }
 }
 int main()
{
 clrscr();
 int xx[10],yy[10],n,i=0,x,y,gd=DETECT,gm=0;
 xyz s;
 cout<<"Enter No. of vertices::";
 cin>>n;
 for(i=0;i<n;i++)
  {
   cout<<"\n Enter vertices of poly::";
   cin>>xx[i];
   cin>>yy[i];
  }

  xx[i] = xx[0];
  yy[i] = yy[0];

  initgraph(&gd,&gm,"c://Turboc3//bgi");
  for(i=0;i<=n-1;i++)
   {
    delay(200);
    line(xx[i],yy[i],xx[i+1],yy[i+1]);
   }
 s.scanline(xx,yy,n);
 getch();
 closegraph();
 return 0;
 }


