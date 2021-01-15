#include <iostream>
#include <graphics.h>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <conio.h>
#include <cstring>
#include <time.h>
using namespace std;

int a[50][50], nl, nc;
int c[10][10], n;///caracter
int d=50,ok,ok2,k2,k,s,ka,k2a;




void citeste_caracter1()
{
    ifstream g("caracter.in");
    g>>n;
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            g>>c[i][j];

}
void citeste_caracter2()
{
    ifstream g("caracter2.in");
    g>>n;
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            g>>c[i][j];
}



void deseneaza_caracter1(int L, int T)
{
    int i, j, x, y;
    int dc=(d-3)/n;
    L=L+5;
    T=T+5;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            x=L+(j-1)*dc;
            y=T+(i-1)*dc;
            setcolor(c[i][j]);
            rectangle(x,y, x+dc,y+dc);
            setfillstyle(1,c[i][j]);
            floodfill(x+2,y+2,c[i][j]);

        }

    int q;
    q=c[3][2];
    c[3][2]=c[3][3];
    c[3][3]=q;

    q=c[4][2];
    c[4][2]=c[4][3];
    c[4][3]=q;

    q=c[3][6];
    c[3][6]=c[3][7];
    c[3][7]=q;

    q=c[4][6];
    c[4][6]=c[4][7];
    c[4][7]=q;



}
void deseneaza_caracter2(int L, int T)
{
    int i, j, x, y;
    int dc=(d-3)/n;
    L=L+5;
    T=T+5;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            x=L+(j-1)*dc;
            y=T+(i-1)*dc;
            setcolor(c[i][j]);
            rectangle(x,y, x+dc,y+dc);
            setfillstyle(1,c[i][j]);
            floodfill(x+2,y+2,c[i][j]);
        }

    int q;
    q=c[3][2];
    c[3][2]=c[3][3];
    c[3][3]=q;

    q=c[4][2];
    c[4][2]=c[4][3];
    c[4][3]=q;

    q=c[3][6];
    c[3][6]=c[3][7];
    c[3][7]=q;

    q=c[4][6];
    c[4][6]=c[4][7];
    c[4][7]=q;



}


char rez[200];
char rez2[200];

int main()
{
    int pietre=17;
    int sp=5,xb,yb,xb2,yb2;
    char v[200]="Scor:";
    char v2[200]="Scor:";
    char scor[200]="Scor";
    int i, j;
    int xc, yc,xc2,yc2;
    ///Stabilire scop joc.
    for(i=1; i<=nc; i++)
        for(j=1; j<=nl; j++)
        {
            if(a[i][j]==0)
                s++;
        }
    ///-----citirea DI harta----------
    ifstream f("matrice.in");
    f>>nl>>nc;

    ///for(i=1; i<=nl; i++)
    ///for(j=1; j<=nc; j++)
    ///f>>a[i][j];
    srand( time(NULL) );
    for(i=1; i<=nl; i++)
        for(j=1; j<=nc; j++)
        {
            int m = rand() % 4; ///primul numar random (de la 0 pana la 13)

            if( m!=2 && pietre>1)
            {
                if(m==3 && i>4 && i<10)
                     {a[i][j]=m;
                     pietre--;}

            if(m==1 || m==2)
                a[i][j]=m;
            }
        }
    a[1][1]=1;
    a[2][1]=1;
    a[1][2]=1;
    a[14][14]=1;
    a[14][13]=1;
    a[13][14]=1;


    f>>xc>>yc;
    f>>xc2>>yc2;
    citeste_caracter1();

    ///-- SETARI fereastra -------------------------

    int W=nc*(d+sp)+sp;
    int H=nl*(d+sp)+sp;
    int Top=sp,Left=sp;
    initwindow(W+500,H,"BOMBERGRASS");
    setcolor(14);
    itoa(k,rez,20);
    strcat(v,rez);
    settextstyle(1,0,2);
    outtextxy(W,50,"jucatorul 1:");
    outtextxy(W,75,v);
    setcolor(5);
    itoa(k2,rez2,20);
    strcat(v2,rez2);
    settextstyle(1,0,2);
    outtextxy(W,100,"jucatorul 2:");
    outtextxy(W,125,v2);

    ///------desenarea careului ------
    int x,y,x2,y2;
    setcolor(10);
    for(i=1; i<=nl; i++)
        for(j=1; j<=nc; j++)
        {
            x=Left+(j-1)*(d+sp);
            y=Top+(i-1)*(d+sp);
            rectangle(x,y, x+d,y+d);
            if(a[i][j]==1)
            {
                setfillstyle(9,7);///model 9, culoare 7
                floodfill(x+3,y+3,10);
            }
            if(a[i][j]==0)
            {
                setfillstyle(9,2);///model 9, culoare 2
                floodfill(x+3,y+3,10);
                s++;
            }
            if(a[i][j]==3)
            {
                setfillstyle(5,8);
                floodfill(x+3,y+3,10);
            }

        }
    cout<<s;



    ///coordonatele si caracteristicile "personajului "
    x=Left+(yc-1)*(d+sp);
    y=Top+(xc-1)*(d+sp);
    setfillstyle(9,4);///model 9, culoare 2
    //floodfill(x+3,y+3,10);
    deseneaza_caracter1(x,y);
    ///coordonatele si caracteristicile personajului 2.
    x2=Left+(yc2-1)*(d+sp);
    y2=Top+(xc2-1)*(d+sp);
    setfillstyle(9,4);///model 9, culoare 2
    deseneaza_caracter2(x2,y2);

    ///----------------------------
    int gata=0;
    char dir;
    while(gata==0)
    {
        while(!kbhit())
            deseneaza_caracter1(x,y);
        if(k!=ka)
        {
            setcolor(0);
            outtextxy(W,75,v);
            itoa(k,rez,10);
            char v[200]="Scor:";
            strcat(v,rez);
            setcolor(14);
            outtextxy(W,75,v);
            ka=k;
        }
        if(k2!=k2a)
        {
            cout<<k2<<" ";
            setcolor(0);
            outtextxy(W,125,v2);
            itoa(k2,rez2,10);
            char v2[200]="Scor:";
            strcat(v2,rez2);
            setcolor(5);
            outtextxy(W,125,v2);
            k2a=k2;
        }
        dir=getch();
        ///sageti pentru deplasare
        ///space pentru plasare "obstacol" la dreapta pe un "culoar"
        if(dir==KEY_RIGHT && a[xc][yc+1]==1)
        {
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            if(a[xc][yc]!=2)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc][yc]==2)
            {
                setfillstyle(1,14);///model 1, culoare 14
                floodfill(xb+3,yb+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb+d/2,yb+d/2,d/2-4-2*k);
            }

            yc++;
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            deseneaza_caracter1(x,y);
        }

        if(dir==KEY_LEFT && a[xc][yc-1]==1)
        {
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            if(a[xc][yc]!=2)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc][yc]==2)
            {
                setfillstyle(1,14);///model 1, culoare 14
                floodfill(xb+3,yb+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb+d/2,yb+d/2,d/2-4-2*k);
            }

            yc--;
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            deseneaza_caracter1(x,y);
        }


        if(dir==KEY_UP && a[xc-1][yc]==1)
        {
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            if(a[xc][yc]!=2)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc][yc]==2)
            {
                setfillstyle(1,14);///model 1, culoare 14
                floodfill(xb+3,yb+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb+d/2,yb+d/2,d/2-4-2*k);
            }

            xc--;
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            deseneaza_caracter1(x,y);
        }

        if(dir==KEY_DOWN && a[xc+1][yc]==1)
        {
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            if(a[xc][yc]!=2)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc][yc]==2)
            {
                setfillstyle(1,14);///model 1, culoare 14
                floodfill(xb+3,yb+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb+d/2,yb+d/2,d/2-4-2*k);
            }

            xc++;
            x=Left+(yc-1)*(d+sp);
            y=Top+(xc-1)*(d+sp);
            deseneaza_caracter1(x,y);
        }
        if(dir=='x' && a[xc2][yc2]==1 && ok2==0)
        {
            a[xc2][yc2]=4;///plaseaza sub personaj bomba
            xb2=Left+(yc2-1)*(d+sp);
            yb2=Top+(xc2-1)*(d+sp);
            setfillstyle(1,5);///model 1, culoare 14
            floodfill(xb2+3,yb2+3,10);
            setcolor(1);
            for(int k=1; k<=5; k++)
                circle(xb2+d/2,yb2+d/2,d/2-4-2*k);
            ok2=1;
        }
        if(dir=='o'&& ok==0)
        {
            a[xc][yc]=2;///plaseaza sub personaj bomba
            xb=Left+(yc-1)*(d+sp);
            yb=Top+(xc-1)*(d+sp);
            setfillstyle(1,14);///model 1, culoare 14
            floodfill(xb+3,yb+3,10);
            setcolor(1);
            ok=1;
            for(int k=1; k<=5; k++)
                circle(xb+d/2,yb+d/2,d/2-4-2*k);
        }
        if(dir=='w' && a[xc2-1][yc2]==1)
        {
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            if(a[xc2][yc2]!=4)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc2][yc2]==4)
            {
                setfillstyle(1,5);///model 1, culoare 14
                floodfill(xb2+3,yb2+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb2+d/2,yb2+d/2,d/2-4-2*k);
            }
            xc2--;
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            deseneaza_caracter2(x,y);
        }
        if(dir=='s' && a[xc2+1][yc2]==1)
        {
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            if(a[xc2][yc2]!=4)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc2][yc2]==4)
            {
                setfillstyle(1,5);///model 1, culoare 14
                floodfill(xb2+3,yb2+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb2+d/2,yb2+d/2,d/2-4-2*k);
            }
            xc2++;
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            deseneaza_caracter2(x,y);
        }
        if(dir=='a' && a[xc2][yc2-1]==1)
        {
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            if(a[xc2][yc2]!=4)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc2][yc2]==4)
            {
                setfillstyle(1,5);///model 1, culoare 14
                floodfill(xb2+3,yb2+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb2+d/2,yb2+d/2,d/2-4-2*k);
            }
            yc2--;
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            deseneaza_caracter2(x,y);
        }
        if(dir=='d' && a[xc2][yc2+1]==1)
        {
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            if(a[xc2][yc2]!=4)
            {
                setfillstyle(9,7);///model 9, culoare 2
                floodfill(x+3,y+3,10);
            }
            if(a[xc2][yc2]==4)
            {
                setfillstyle(1,5);///model 1, culoare 14
                floodfill(xb2+3,yb2+3,10);
                setcolor(1);
                for(int k=1; k<=5; k++)
                    circle(xb2+d/2,yb2+d/2,d/2-4-2*k);
            }
            yc2++;
            x=Left+(yc2-1)*(d+sp);
            y=Top+(xc2-1)*(d+sp);
            deseneaza_caracter2(x,y);
        }

        if (dir=='p')
        {

            for(i=1; i<=nc; i++)
                for(j=1; j<=nl; j++)
                    if(a[i][j]==2)
                    {
                        setfillstyle(9,7);///model 9, culoare 7
                        floodfill(xb+3,yb+3,10);
                        a[i][j]=1;
                        setfillstyle(9,7);///model 9, culoare 7
                        if(a[i-1][j]==0 && i-1!=0 && j!=0)
                        {
                            a[i-1][j]=1;
                            floodfill(xb+10,yb-d+3-sp,10);
                            k++;
                        }
                        if (a[i+1][j]==0 && j!=0 && i+1!=1)
                        {
                            floodfill(xb+10,yb+d+3+sp,10);
                            a[i+1][j]=1;
                            k++;
                        }
                        if (a[i][j-1]==0 && j-1!=0 && i!=0 )
                        {
                            a[i][j-1]=1;
                            k++;
                            floodfill(xb-d+3+sp,yb+3,10);
                        }
                        if (a[i][j+1]==0 && i!=0 &&j+1!=1 && j+1<=14  )
                        {
                            floodfill(xb+d+3+sp,yb+3,10);
                            a[i][j+1]=1;
                            k++;
                        }
                        ok=0;
                    }
        }
        if (dir=='c')
        {

            for(i=1; i<=nc; i++)
                for(j=1; j<=nl; j++)
                    if(a[i][j]==4)
                    {
                        setfillstyle(9,7);///model 9, culoare 7
                        floodfill(xb2+3,yb2+3,10);

                        a[i][j]=1;
                        setfillstyle(9,7);///model 9, culoare 7
                        if(a[i-1][j]==0)
                        {
                            a[i-1][j]=1;
                            floodfill(xb2+10,yb2-d+3-sp,10);
                            k2=k2+1;

                        }
                        if(a[i+1][j]==0 && j!=0 && i+1!=1 && i<14)
                        {
                            a[i+1][j]=1;

                            floodfill(xb2+10,yb2+d+3+sp,10);
                            k2++;
                        }
                        if(a[i][j-1]==0 && j-1!=0 && i!=0 )
                        {
                            a[i][j-1]=1;

                            k2++;
                            floodfill(xb2-d+3+sp,yb2+3,10);
                        }

                        if(a[i][j+1]==0 && j+1<=14)
                        {
                            a[i][j+1]=1;

                            k2++;
                            floodfill(xb2+d+3+sp,yb2+3,10);
                        }
                        ok2=0;


                    }


        }
        if(k>=(s+1)/2)
        {
            setcolor(14);
            outtextxy(W+100,500,"jucatorul 1 a castigat");
            system("pause");
        }
        if(k2>=(s+1)/2)
        {
            setcolor(5);
            outtextxy(W+100,500,"jucatorul w a castigat");
            system("pause");
        }
    }

    delay(60000);
    return 0;
}
